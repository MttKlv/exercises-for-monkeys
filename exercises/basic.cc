#include "../includes/basic.hh"

Basic::Basic(int px, int tpe, int rndom){
  _pxl   = px;
  _type  = tpe;
   _random = rndom; 
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
    switch (_random){
    case 0:
      a = width/2-(_pxl/2);
      b = width/2+(_pxl/2);
      c = height/2-(_pxl/2);
      d = height/2+(_pxl/2);
      break;
    case 1:
      a = width/2-(_pxl/2)+((DEP/2)*width);
      b = width/2+(_pxl/2)+((DEP/2)*width);
      c = height/2-(_pxl/2);
      d = height/2+(_pxl/2);
      break;
    case 2:
      a = width/2-(_pxl/2)-((DEP/2)*width);
      b = width/2+(_pxl/2)-((DEP/2)*width);
      c = height/2-(_pxl/2);
      d = height/2+(_pxl/2);
      break;
    case 3:
      a = width/2-(_pxl/2);
      b = width/2+(_pxl/2);
      c = height/2-(_pxl/2)-((DEP/2)*height);
      d = height/2+(_pxl/2)-((DEP/2)*height);
      break;
    case 4:
      a = width/2-(_pxl/2);
      b = width/2+(_pxl/2);
      c = height/2-(_pxl/2)+((DEP/2)*height);
      d = height/2+(_pxl/2)+((DEP/2)*height);
      break;
    }

    if (x>=a && x<=b){
      if (y>=c && y<=d){
	printf("PAF!\n");
	printf("Debut pause ... Zzz...\n");
	//sleep(3);
	if (_random != -1){
	  reset();
	}
	printf("Fin pause!\n");
    
      }
    }
    
    }
  
}

void 
Basic::display(){
  Session* s = Session::getInstance();

  if (_type==0){
    glPushMatrix();
    
    switch(_random){
    case 1:
      glTranslatef(0.75,0,0);	
      break;
    case 2:
      glTranslatef(-0.75,0,0);
      break;
    case 3:
      glTranslatef(0,0.75,0);
      break;
    case 4:
      glTranslatef(0,-0.75,0);
      break;
    }
    
    double x = (float)_pxl*(1.0/s->getWidth());
    double y = (float)_pxl*(1.0/s->getHeight());

    glBegin(GL_QUADS);
    glColor3ub(255,0,0); 
    glVertex2f(-x,-y);
    glVertex2f(-x,y);
    glVertex2f(x,y);
    glVertex2f(x,-y);
    glEnd();

    glPopMatrix();
  }
  else{
    glOrtho(-2.0,
	     2.0,
	    -2.0*(double) s->getHeight()/s->getWidth(),
	     2.0*(double) s->getHeight()/s->getWidth(),
	     0.0,
	     2.0);
    int 
      slices    = 20,
      ii        = 0;
    float 
      angle     = 2*M_PI/slices,
      radius    = 0.2,
      x         = 0, 
      y         = 0, 
      previousX = radius, 
      previousY = 0;
  
    glBegin(GL_TRIANGLES);
  
    for (ii=0; ii<=slices; ii++){
    
      x = radius * cos(angle*ii);
      y = radius * sin(angle*ii);
      
      glColor3ub(_R,_G,_B);
      
      glVertex3f(0.0,0.0,0.0);
      glVertex3f(previousX, previousY,0.0);
      glVertex3f(x, y,0.0);

      previousX = x;
      previousY = y;
    }
  
    glEnd();

  }
}

void
Basic::menu(){
  printf("\tType de forme : 0 cercle | 1 carré => ");
  cin >> _type;
  if (_type==0){
    printf("\tRayon => ");
  }
  else{
    printf("\tTaille => ");
  }
  cin >> _pxl;
  printf("\tCouleur RGB\n");
  printf("\tR => ");
  cin >> _R;
  printf("\tG => ");
  cin >> _G;
  printf("\tB => ");
  cin >> _B;
}

void
Basic::reset(){
  _random = random(0,5);
}
 
