#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/timeb.h>
#include <iostream>

#include "includes/session.hh"
#include "includes/exercise.hh"
#include "includes/basic.hh"

Session* Session::_instance = NULL;
Session* s;

Exercise e;

static Basic basic(100);
using namespace std;

void mouse(int button, int state, int x, int y);
void keyboard(unsigned char key, int xmouse, int ymouse);
void reshape (int wdth, int heght);
void display();
bool initApp(int argc, char *argv[]);


int
main (int argc, char *argv[])
{
  
  Basic basic(100);
  bool b = initApp( argc, argv);
  return b;
}

bool
initApp(int argc, char *argv[]){
  glutInit (&argc, argv);
  glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DOUBLE);
  glutInitWindowSize (1920, 1080);
  glutCreateWindow (""); // name
  glutGameModeString("1920x1080:32@60");
  //  glutEnterGameMode();
  glutFullScreen();
  glutReshapeFunc (&reshape);
  glutDisplayFunc (&display);
  glutMouseFunc(&mouse);
  glutKeyboardFunc(&keyboard);
 
  s = Session::getInstance(glutGet(GLUT_WINDOW_WIDTH),glutGet(GLUT_WINDOW_HEIGHT));

  glutMainLoop();

  return 0;
}

void
mouse(int button, int state, int x, int y){
  if (s->getNbFrame()>30){
    
    basic.mouse(button, state, x, y);

    s->reset();
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

  glClearColor(0, 0, 0, 0);
  glLoadIdentity ();

  basic.display();

  s->addFrame();

  glutPostRedisplay();
  glutSwapBuffers();
}



/********** BLABLA ********

  char* pPath;
  pPath = getenv ("session");
   if (pPath!=NULL)
       printf ("The current path is: %s",pPath);

  char path[200];
  getcwd(path, 200);
  printf("pwd -> %s\n", path);

*****************************/
