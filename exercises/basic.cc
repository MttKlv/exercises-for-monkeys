#include "../includes/basic.hh"


Basic::Basic(int px){
  _pxl = px;
}

Basic::~Basic(){

}

void
Basic::mouse(int button, int state, int x, int y){
  Session* s = Session::getInstance();

  int a, b, c, d;

  int width = s->getWidth();
  int height = s->getHeight();
  if (state==0){
    
    a = width/2-(_pxl/2);
    b = width/2+(_pxl/2);
    
    c = height/2-(_pxl/2);
    d = height/2+(_pxl/2);

    if (x>=a && x<=b){
      if (y>=c && y<=d){
	printf("PAF!\n");
	printf("Debut pause ... Zzz...\n");
	sleep(3);
	printf("Fin pause!\n");
    
      }
    }
    
    }
  
}

void 
Basic::display(){
  Session* s = Session::getInstance();

  double x = (float)_pxl*(1.0/s->getWidth());
  double y = (float)_pxl*(1.0/s->getHeight());

  glBegin(GL_QUADS);
  glColor3ub(255,0,0); 
  glVertex2f(-x,-y);
  glVertex2f(-x,y);
  glVertex2f(x,y);
  glVertex2f(x,-y);
  glEnd();
}
