#ifndef BASIC_HH_
#define BASIC_HH_

#include "exercise.hh"
#include "session.hh"
#include <unistd.h>
#include <vector>

class Basic : public Exercise{
public:
  Basic(vector<string> variables);
  ~Basic();
  bool mouse(int button, int state, int x, int y);;
  void display();
  void displayPause();
  void reset();

private:
  float _pxl;
  int _type;
  int _mode;
  int _RGB[3];
  int _pauseRGB[3];
  int _random;
  float _depX;
  float _depY;

};

  
#endif

