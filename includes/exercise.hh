#ifndef EXERCISE_HH_
#define EXERCISE_HH_

class Exercise{
public:
  Exercise();
  ~Exercise();
  virtual void mouse(int button, int state, int x, int y){};
  virtual void display(){};

};

#endif
