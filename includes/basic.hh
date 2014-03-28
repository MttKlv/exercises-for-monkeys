#ifndef BASIC_HH_
#define BASIC_HH_

#include "exercise.hh"
#include "session.hh"
#include <unistd.h>

class Basic : public Exercise{
public:
Basic(int px, int tpe, int rndom);
~Basic();
void mouse(int button, int state, int x, int y);;
void display();
void reset();

private:
int _pxl;
int _type;
int _random;

const float DEP = 0.75;

};

  
#endif

