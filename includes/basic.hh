#ifndef BASIC_HH_
#define BASIC_HH_

#include "exercise.hh"
#include "session.hh"
#include <unistd.h>

class Basic : public Exercise{
public:
  Basic(int px, int tpe, int rndom);
  ~Basic();
  bool mouse(int button, int state, int x, int y);;
  void display();
  void reset();
  void menu();

private:
  float _pxl;
  int _type;
  int _random;
  int _R;
  int _G;
  int _B;

  float _depX;
  float _depY;

};

  
#endif

