#include "../includes/session.hh"

Session::Session():
  _startTime(-1),
  _nbFrame(0),
  _nbFramePause(0){ 
  _recorder = new Recorder("/home/xeno1/Desktop/exercises-for-monkeys/output/");
  _recorder->createFile();
}

Session::~Session(){
  // TODO
}

void 
Session::time(){
  if (_startTime == -1){
    _startTime = getTime();
  }
  _currentTime = getTime();
}

int 
Session::getTime(){
  timeb tb;
  ftime(&tb);
  int time = tb.millitm + (tb.time & 0xfffff)*1000;
  
  return time; 
}

void 
Session::reshape(int wdth, int heght){
  _width = wdth;
  _height = heght;

  glViewport(0,0, _width, _height);
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  //  gluPerspective(65.,(double) _width/_height,1.0,200.0);
  glMatrixMode(GL_MODELVIEW);

}
 
void 
Session::reset(){
  _nbFrame = 0;
}
 
Session*
Session::createInstance(){
  _instance = new Session(); 
  return _instance;
}
