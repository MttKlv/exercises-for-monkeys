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

  return false;


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
	    std::cout << "Substring: " << sub << endl;
	    _variables.push_back(sub);
	  }
	} while (iss);    
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
