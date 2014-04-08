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
  void reset();

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

