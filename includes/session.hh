#ifndef SESSION_HH_
# define SESSION_HH_
 
#include <GL/glut.h>
#include <sys/timeb.h>

#include <stdio.h>
#include "recorder.hh"

class Session{
public:

  ~Session();

  void time();
  void addFrame(){ _nbFrame++; }
  void reshape(int wdth, int heght);
  void reset();
  static Session* getInstance(){return _instance;}
  static Session* getInstance(int wdth, int heght);

  int getStartTime(){ return _startTime; }
  int getCurrentTime(){ return _currentTime; }
  int getNbFrame(){ return _nbFrame; }
  int getAppTime(){ return (_currentTime - _startTime); }
  int getWidth(){ return _width; }
  int getHeight(){ return _height; }
  Recorder* getRecorder(){ return _recorder; }
  void setWidth(int wdth){ _width = wdth; } 
  void setHeight(int heght){ _height = heght; }

private:
  Session();
  Recorder* _recorder;

  int _startTime;
  int _currentTime;
  int _nbFrame;
  int _height;
  int _width;
  static Session* _instance;

  int getTime();
  
};



#endif
