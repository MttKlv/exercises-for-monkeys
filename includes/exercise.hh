#ifndef EXERCISE_HH_
#define EXERCISE_HH_

#include <math.h>
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <time.h>

using namespace std;
class Exercise{
public:
  Exercise();
  ~Exercise();
  virtual void mouse(int button, int state, int x, int y){};
  virtual void display(){};
  virtual void reset(){};
  virtual void menu(){};
protected:
  int random(int min, int max);
};

#endif
