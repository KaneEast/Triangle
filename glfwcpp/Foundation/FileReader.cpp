//
//  FileReader.cpp
//  glfwcpp
//
//  Created by inman on 2020/04/29.
//  Copyright © 2020 inman. All rights reserved.
//

#include "FileReader.hpp"


// returns files content cstr
std::string readFileToCstr(std::string filePath)
{
    // 1. retrieve the vertex/fragment source code from filePath
    std::string vertexCode;
    std::ifstream vShaderFile;
    // ensure ifstream objects can throw exceptions:
    vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        // open files
        vShaderFile.open(filePath);
        std::stringstream vShaderStream;
        // read file's buffer contents into streams
        vShaderStream << vShaderFile.rdbuf();
        // close file handlers
        vShaderFile.close();
        // convert stream into string
        vertexCode = vShaderStream.str();
        // if geometry shader path is present, also load a geometry shader

    }
    catch (std::ifstream::failure e)
    {
        std::cout << "FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
    return vertexCode;
}
