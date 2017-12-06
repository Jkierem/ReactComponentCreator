#include "Juan.h"

void Juan::writeFile( std::string name , std::string path ){
  if( validateFileName(name, path) ){
    std::string createDirectory = "mkdir "+ path + "/" + name ;
    std::string createIndex     = "touch "+ path + "/" + name + "/index.js";
    system( createDirectory.c_str() );
    system( createIndex.c_str() );
    std::ofstream file (path + "/" + name + "/index.js");
    if (file.is_open())
    {
      file << "import React from \'react\'"
      << std::endl << std::endl
      <<"class "+ name + " extends React.Component{"
      << std::endl
      << "\tconstructor(props){"
      << std::endl
      << "\t\tsuper(props);"
      << std::endl
      << "\t\tthis.state={}"
      << std::endl
      << "\t}"
      << std::endl << std::endl
      << "\trender(){"
      << std::endl
      << "\t\treturn(<div> " + name + " </div>);"
      << std::endl
      << "\t}"
      << std::endl
      << "}"
      << std::endl << std::endl
      << "export default " + name+ ";";
      file.close();
    }
    checkExecution(name , path);
  }
}

void Juan::testWriteFile( std::string name , std::string path){
  std::cout << "Component name : "<< name << std::endl;
  std::cout << "Component dir  : "<< path << std::endl;
  std::cout << "Component text :" << std::endl;
  std::cout << "import React from \'react\'"
       << std::endl << std::endl
       <<"class "+ name + " extends React.Component{"
       << std::endl
       << "\tconstructor(props){"
       << std::endl
       << "\t\tsuper(props);"
       << std::endl
       << "\t\tthis.state={}"
       << std::endl
       << "\t}"
       << std::endl << std::endl
       << "\trender(){"
       << std::endl
       << "\t\treturn(<div/>);"
       << std::endl
       << "\t}"
       << std::endl
       << "}"
       << std::endl << std::endl
       << "export default " + name+ ";";
}

void Juan::checkExecution( std::string name , std::string path ){
  std::cout << "Component Name: " << name << std::endl;
  std::cout << "Component dir : " << path << std::endl;
  std::ifstream file (path + "/" + name + "/index.js" , std::ifstream::in);
  if ( file.is_open() ){
    std::cout << "Status : File created successfully. Happy coding! :)" << std::endl;
  }else{
    std::cout << "Status : Something went wrong. Could not create component." << std::endl;
  }
  file.close();
}

bool Juan::validateFileName( std::string name , std::string path ){
  bool ret = true;
  std::ifstream file (path + "/" + name + "/index.js" , std::ifstream::in);
  if ( file.is_open() ){
    std::cout << "Status : File already exists." << std::endl;
    ret = false;
  }
  file.close();
  return ret;
}

bool Juan::isUppercase( char n ){
  if( n < 'A' || n > 'Z'){
    return false;
  }
  return true;
}

bool Juan::isCapitalized( std::string name ){
  return isUppercase( name[0] );
}
