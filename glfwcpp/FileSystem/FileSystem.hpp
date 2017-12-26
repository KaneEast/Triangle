//
//  FileSystem.hpp
//  glfwcpp
//
//  Created by inman on 2017/12/23.
//  Copyright © 2017年 inman. All rights reserved.
//

#ifndef FileSystem_hpp
#define FileSystem_hpp

#include <string>

//欺骗性代码。。。
namespace FileSystem {
    static std::string getPath(char* path)
    {
        return path;
    }
}

#endif /* FileSystem_hpp */
