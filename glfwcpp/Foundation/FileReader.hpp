//
//  FileReader.h
//  glfwcpp
//
//  Created by inman on 2020/04/29.
//  Copyright © 2020 inman. All rights reserved.
//

#ifndef FileReader_h
#define FileReader_h

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

// returns files content cstr
std::string readFileToCstr(std::string filePath);

#endif /* FileReader_h */
