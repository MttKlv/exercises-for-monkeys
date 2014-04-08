
#include <GL/freeglut.h>
#include <GL/gl.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/timeb.h>
#include <iostream>

#include "includes/session.hh"
#include "includes/exercise.hh"
#include "includes/basic.hh"
#include "includes/parser.hh"
#include "includes/parapin.hh"

Session* Session::_instance = NULL;
Session* s;

Exercise* e;

using namespace std;

void keyboard(unsigned char key, int xmouse, int ymouse);
void mouse(int button, int state, int x, int y);
bool initApp(int argc, char *argv[]);
void reshape (int wdth, int heght);
void display();
void prepareExercise(vector<string> variables);

int
main (int argc, char *argv[])
{
  const char *path = "definition.txt";
  Parser *p = new Parser(path);
  if(p->parse()){
    s = Session::getInstance();
    s->setNbFramePause(atoi(p->getVariables().at(1).c_str()));

    prepareExercise(p->getVariables());    
    initApp(argc, argv);  

    return EXIT_SUCCESS;
  }
  std::cout << "parse fail" << endl;
  return EXIT_FAILURE;
}

void prepareExercise(vector<string> variables){
  int choice = atoi((variables.at(0)).c_str());

  switch(choice){
  case 1:
    e = new Basic(variables);
    break;
  case 2:
    e = new Basic(variables);
    break;
  }
  //  printf("\tTemps entre chaque essai (Frame) => ");
  // cin >> frame;
}

bool
initApp(int argc, char *argv[]){
  glutInit (&argc, argv);
  glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DOUBLE);
  glutInitWindowSize (1920, 1080);
  glutCreateWindow (""); // name
  // glutGameModeString("1920x1080:32@60");
  // glutEnterGameMode();
  glutFullScreen();
  glutReshapeFunc (&reshape);
  glutDisplayFunc (&display);
  glutMouseFunc(&mouse);
  glutKeyboardFunc(&keyboard);
 
  s->setWidth(glutGet(GLUT_WINDOW_WIDTH));
  s->setHeight(glutGet(GLUT_WINDOW_HEIGHT));

  glutMainLoop();

  return 0;
}

void
mouse(int button, int state, int x, int y){

  if (state == 0){
    if (s->getNbFrame()>s->getNbFramePause()){
    
      bool rep = false;
      rep = e->mouse(button, state, x, y);
      if (rep){
	s->reset();
	s->getRecorder()->write(x, y, 1);
      }
      else{
	s->getRecorder()->write(x, y, 0);
      }
    }
    else{
      s->getRecorder()->write(x, y, 0);
    }
  }
 
}

void
keyboard (unsigned char key, int xmouse, int ymouse){
  switch((int) key){
  case 27 :
    exit(EXIT_SUCCESS);
    break;
  }
}

void
reshape (int wdth, int heght)
{
  s->reshape(wdth, heght);
}

void
display()
{
  s->time();

  glClear(GL_COLOR_BUFFER_BIT);
  glClearColor(0,0,0, 1);

  glLoadIdentity ();
  glMatrixMode(GL_MODELVIEW);

  if (s->getNbFrame()>s->getNbFramePause()){
    e->display();
  }

  s->addFrame();

  glutPostRedisplay();
  glutSwapBuffers();
}



/**********...pour les textures... ********

  char* pPath;
  pPath = getenv ("session");
   if (pPath!=NULL)
       printf ("The current path is: %s",pPath);

  char path[200];
  getcwd(path, 200);
  printf("pwd -> %s\n", path);

*****************************/
