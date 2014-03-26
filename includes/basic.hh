#ifndef BASIC_HH_
#define BASIC_HH_

#include "exercise.hh"
#include "session.hh"
#include <unistd.h>

class Basic : public Exercise{

public:
  Basic(int px);
  ~Basic();
  void mouse(int button, int state, int x, int y);
  void display();

private:
  int _pxl;
};


#endif

