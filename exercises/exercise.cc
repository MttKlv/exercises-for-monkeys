#include "../includes/exercise.hh"


Exercise::Exercise(){
  ;
}
Exercise::~Exercise(){
  ;
}

int
Exercise::random(int min, int max){
  srand (time(NULL));
  return (rand() % max + min);
}
