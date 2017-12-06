#ifndef _JUAN_H_
#define _JUAN_H_

#include <string>
#include <fstream>
#include <iostream>

namespace Juan {
  void writeFile( std::string name , std::string path="./src/components" );
  void testWriteFile( std::string name , std::string path="./src/components" );
  void checkExecution( std::string name , std::string path );
  bool validateFileName( std::string name , std::string path );
  bool isUppercase( char n );
  bool isCapitalized( std::string name );
} /* Juan */

#endif
