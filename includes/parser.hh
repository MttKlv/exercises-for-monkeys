#ifndef PARSER_HH_
#define PARSER_HH_

#include <string.h>
#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

#include <sstream>
#include <string>

using namespace std;

class Parser{
  
public:
  Parser(const char* pth);
  ~Parser();
  bool parse();
  bool fileExist();
  vector<string> getVariables(){return _variables;};

private: 
  const char* _path;
  vector<string> _variables;
};

#endif
