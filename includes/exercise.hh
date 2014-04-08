#ifndef EXERCISE_HH_
#define EXERCISE_HH_

#include <math.h>
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <assert.h>

using namespace std;
class Exercise{
public:
  Exercise();
  ~Exercise();
  virtual bool mouse(int button, int state, int x, int y){return false;};
  virtual void display(){};
  virtual void reset(){};
protected:
  int random(int min, int max);
  float random(){return (float) rand()/RAND_MAX;}
};

#endif
