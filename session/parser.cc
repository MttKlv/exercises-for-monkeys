#include "../includes/parser.hh"
#
Parser::Parser(const char* pth):
  _path(pth),
  _variables(NULL){

}

Parser::~Parser(){

}

bool
Parser::parse(){

  fstream def(_path, std::fstream::in | std::fstream::out);
  streamsize nb = 100;
  char* infos = NULL;

  infos = (char*) malloc(100);

  if (infos != NULL){
    if (def.is_open()){
      def.get(infos, nb, ';');
      istringstream iss((string) infos);
      do
	{
	  string sub;
	  iss >> sub;
	  if (!sub.empty()){	     
	    _variables.push_back(sub);
	  }
	} while (iss);    
      vector<string>::iterator ii;
      for (ii = _variables.begin(); ii != _variables.end(); ii++){
	std::cout << *ii << endl;
      }
      return true;
    }
  }
  else{
    printf("Erreur d'allocation de mémoire.");
    exit(0);
  }
  def.close();
  return false;
}

bool
Parser::fileExist(){
  return false;
}
