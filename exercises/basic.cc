#include "../includes/basic.hh"


Basic::Basic(int px, int tpe){
  _pxl = px;
  _type = tpe;
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

  if (_type==0){
    
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
  else{
    glOrtho(-1.0,
	     1.0,
	    -1.0*(double) s->getHeight()/s->getWidth(),
	     1.0*(double) s->getHeight()/s->getWidth(),
	     0.0,
	     1.0);
    int 
      slices = 20,
      ii = 0;
    float 
      angle = 2*M_PI/slices, 
      radius = 0.2,
      x = 0, 
      y = 0, 
      previousX = radius, 
      previousY = 0;
  
    glBegin(GL_TRIANGLES);
  
    for (ii=0; ii<=slices; ii++){
    
      x = radius * cos(angle*ii);
      y = radius * sin(angle*ii);
      
      glColor3ub(255,0,0);
      
      glVertex3f(0.0,0.0,0.0);
      glVertex3f(previousX, previousY,0.0);
      glVertex3f(x, y,0.0);

      previousX = x;
      previousY = y;
    }
  
    glEnd();

  }
}
