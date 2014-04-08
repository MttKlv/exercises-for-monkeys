#include "../includes/recorder.hh"

Recorder::Recorder(string pth){
  _path = pth;
}


Recorder::~Recorder(){

}

string
Recorder::getDateTime(){
  time_t now = time(0);
  tm* ltm = localtime(&now);
  ostringstream oss;
  oss << ltm->tm_mon << "-" << ltm->tm_mday << "-" << (ltm->tm_year+1900)
      << " "
      << ltm->tm_hour<< ":" << ltm->tm_min << ":" << ltm->tm_sec;
  return oss.str();
 
}
void
Recorder::createFile(){
  string datetime = getDateTime();
  _nameFile =  datetime + ".txt";
  string file = _path + _nameFile;
  
  FILE * pfile;
  pfile = fopen(file.c_str(), "w");
  if (pfile == NULL){
    printf("Impossible de créer le fichier d'enregistrement.\n");
    exit(0);
  }
  fclose(pfile);
}

void
Recorder::write(int x, int y, string pos, string auth){

  ostringstream oss;
  string file = _path + _nameFile;

  FILE * pfile;
  pfile = fopen(file.c_str(), "a");
  if (pfile != NULL){
    oss << getDateTime() << " "  << x << " " << y << " : " << pos << " " << auth << "\n";
    string str = oss.str();
    fprintf(pfile,"%s", str.c_str());
    fclose(pfile);
  }
  else{
    printf("Impossible d'enregistrer la réponse sujet.");
  }
}
