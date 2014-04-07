#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/timeb.h>
#include <iostream>

#include "includes/session.hh"
#include "includes/exercise.hh"
#include "includes/basic.hh"
#include "includes/parser.hh"

Session* Session::_instance = NULL;
Session* s;

Exercise* e;

int frame;

using namespace std;

void keyboard(unsigned char key, int xmouse, int ymouse);
void mouse(int button, int state, int x, int y);
bool initApp(int argc, char *argv[]);
void reshape (int wdth, int heght);
void display();
void menu();

int
main (int argc, char *argv[])
{
  const char *path = "definition.txt";
  Parser *p = new Parser(path);
  if(p->parse()){
    //   printf("oui\n");
    exit(1);
  }
  //    printf("nop\n");
  //exit(0);
  menu();

  bool b = initApp(argc, argv);
  return b;
}

void menu(){
  int choice = 2;
  
  printf("\t1 - Cible au centre, ne bouge pas\n");
  printf("\t2 - Cible qui se déplace\n");
  // printf("\t3 - Choix entre animaux ou objets\n");
  printf("\tSelection => ");
  cin >> choice; 
  switch(choice){
  case 1:
    e = new Basic(100,0,-1);
    e->menu();
    break;
  case 2:
    e = new Basic(100,0,0);
    e->menu();
    break;
  }
  printf("\tTemps entre chaque essai (Frame) => ");
  cin >> frame;
}

bool
initApp(int argc, char *argv[]){
  glutInit (&argc, argv);
  glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DOUBLE);
  // glutInitWindowSize (1920, 1080);
  glutCreateWindow (""); // name
  // glutGameModeString("1920x1080:32@60");
  // glutEnterGameMode();
  glutFullScreen();
  glutReshapeFunc (&reshape);
  glutDisplayFunc (&display);
  glutMouseFunc(&mouse);
  glutKeyboardFunc(&keyboard);
 
  s = Session::getInstance(glutGet(GLUT_WINDOW_WIDTH),
			   glutGet(GLUT_WINDOW_HEIGHT));

  glutMainLoop();

  return 0;
}

void
mouse(int button, int state, int x, int y){

  if (state == 0){
    if (s->getNbFrame()>frame){
    
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

  // gluOrtho2D(0,s->getHeight(),0,s->getWidth());

  //  gluPerspective(65.,(float) s->getWidth()/s->getHeight(),0.1,200.0);
  glMatrixMode(GL_MODELVIEW);
  
  if (s->getNbFrame()>frame){
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
