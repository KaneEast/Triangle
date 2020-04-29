//
//  all.h
//  glfwcpp
//
//  Created by inman on 2020/04/28.
//  Copyright © 2020 inman. All rights reserved.
//

#ifndef all_h
#define all_h

#include <iostream>
#include <cstdlib>
#include <memory>

// 以下のinclude順番を変えるとビルドエラーになる
// --------------------------------------
#include <GL/glew.h>        // step 1
//#include <glad/glad.h>
#include <GLFW/glfw3.h>     // step 2


#include "Window.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <learnopengl/shader_s.h>

//#ifndef STB_IMAGE_IMPLEMENTATION

#include <stb_image.h>
//#endif



#endif /* all_h */
