#include <iostream>
#include <iomanip>
#include <string>
#include "Juan.h"

int main(int argc, char const *argv[]) {
  //check usage
  if( argc != 2 && argc != 3){
    std::cerr << "Usage: createComponent <Name> " << std::endl
              << "       createComponent <Name> <DIRECTORY>" << std::endl;
  }else{
    std::string name(argv[1]);
    if( ( name == "help" || name == "-help" || name == "-h" )&& argc == 2){
      std::cout << "NAME: " << std::endl;
      std::cout << "       createComponent - Creates a basic React Component." << std::endl << std::endl;
      std::cout << "SYNOPSIS: " << std::endl
                << "       createComponent [NAME] " << std::endl
                << "       createComponent [NAME] [DIRECTORY]" << std::endl << std::endl
                << "DESCRIPTION: " << std::endl << std::endl
                << "- Create a basic React Component in the specified directory. If no [DIRECTORY] is given, \"./src/components\" will be used. The created component will be inside a folder with the given name and saved as [DIRECTORY]/[NAME]/index.js. The specified directory must exist or in case no directory is specified then ./src/components must exist"
                << std::endl << std::endl;
    }else if( !Juan::isCapitalized(name) ){
      std::cout << "Error : Class names must start with an uppercase letter." << std::endl;
    }else{
      if( argc == 3){
        std::string path(argv[2]);
        Juan::writeFile( name , path );
      }else{
        Juan::writeFile( name );
      }
    }
  }

  return 0;
}
