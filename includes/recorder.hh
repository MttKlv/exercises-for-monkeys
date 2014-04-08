#ifndef RECORDER_HH_
#define RECORDER_HH

#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream> 
#include <ctime>
#include <cstdlib>

using namespace std;
class Recorder{
public:
  Recorder(string pth);
  ~Recorder();
  void createFile();
  void write(int x, int y, string pos, string auth);
private:
  string getDateTime();
  string _path;
  string _nameFile;
    
};


#endif
