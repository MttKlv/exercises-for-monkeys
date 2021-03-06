#include "../includes/basic.hh"

Basic::Basic(vector<string> variables):
  _depX(0.75),
  _depY(0.75){

  assert(variables.size()==11);

  _mode   = atoi((variables.at(2)).c_str());
  _type  = atoi((variables.at(3)).c_str());
  _pxl = atoi((variables.at(4)).c_str()); 
  _RGB[0] = atoi((variables.at(5)).c_str());
  _RGB[1] = atoi((variables.at(6)).c_str());
  _RGB[2] = atoi((variables.at(7)).c_str());
  _pauseRGB[0] = atoi((variables.at(8)).c_str());
  _pauseRGB[1] = atoi((variables.at(9)).c_str());
  _pauseRGB[2] = atoi((variables.at(10)).c_str());
  _random = 0;
}

Basic::~Basic(){

}

bool 
Basic::mouse(int button, int state, int x, int y){
  Session* s = Session::getInstance();

  int a, b, c, d, pxl;

  int width = s->getWidth();
  int height = s->getHeight();

  pxl = _pxl/2;
  
  if (state==0){
    if (_mode==1){
      switch (_random){
      case 0:
	a = width/2-(pxl);
	b = width/2+(pxl);
	c = height/2-(pxl);
	d = height/2+(pxl);
	break;
      case 1:
	a = width/2-(pxl)+((_depX/2)*width);
	b = width/2+(pxl)+((_depX/2)*width);
	c = height/2-(pxl);
	d = height/2+(pxl);
	break;
      case 2:
	a = width/2-(pxl)-((_depX/2)*width);
	b = width/2+(pxl)-((_depX/2)*width);
	c = height/2-(pxl);
	d = height/2+(pxl);
	break;
      case 3:
	a = width/2-(pxl);
	b = width/2+(pxl);
	c = height/2-(pxl)-((_depY/2)*height);
	d = height/2+(pxl)-((_depY/2)*height);
	break;
      case 4:
	a = width/2-(pxl);
	b = width/2+(pxl);
	c = height/2-(pxl)+((_depY/2)*height);
	d = height/2+(pxl)+((_depY/2)*height);
	break;
      }
    }
    else{
      a = width/2-(pxl);
      b = width/2+(pxl);
      c = height/2-(pxl);
      d = height/2+(pxl);
    }

    if (x>=a && x<=b){
      if (y>=c && y<=d){
	printf("PAF!\n");
	printf("Debut pause ... Zzz...\n");
	//sleep(3);
	if (_mode == 1){
	  reset();
	}
	printf("Fin pause!\n");
	return true;
      }
    }
    return false;
    }
  return false;
}

void
Basic::displayPause(){
  display();
}
void 
Basic::display(){
  Session* s = Session::getInstance();
  
  float pxlScreen[2];
  pxlScreen[0] = 1.0/s->getWidth();
  pxlScreen[1] = 1.0/s->getHeight();

  glPushMatrix();
    
  if (_mode == 1){
    switch(_random){
    case 1:
      glTranslatef(_depX,0,0);	
      break;
    case 2:
      glTranslatef(-_depX,0,0);
      break;
    case 3:
      glTranslatef(0,_depY,0);
      break;
    case 4:
      glTranslatef(0,-_depY,0);
      break;
    }
  }
  if (s->getParapin()==true){
    glColor3ub(_pauseRGB[0], _pauseRGB[1], _pauseRGB[2]);
  }
  else{
    glColor3ub(_RGB[0],_RGB[1],_RGB[2]); 
  }
  if (_type==0){

    float x = (float)_pxl*(pxlScreen[0]);
    float y = (float)_pxl*(pxlScreen[1]);

    glBegin(GL_QUADS);

    glVertex2f(-x,-y);
    glVertex2f(-x,y);
    glVertex2f(x,y);
    glVertex2f(x,-y);
    glEnd();

    glPopMatrix();
  }
  else{
    int 
      slices    = 20,
      ii        = 0;
    float 
      angle     = 2*M_PI/slices,
      radius    = _pxl,
      x         = 0, 
      y         = 0, 
      previousX = radius, 
      previousY = 0;
  
    glBegin(GL_TRIANGLES);
  
    for (ii=0; ii<=slices; ii++){
    
      x = radius * cos(angle*ii)*pxlScreen[0];
      y = radius * sin(angle*ii)*pxlScreen[1];
            
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
Basic::reset(){
  _random = random(0,5);
  // _depX = random();
  // _depY = random();
}
 
