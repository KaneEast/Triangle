#ifndef NEGLFW_hpp
#define NEGLFW_hpp

#include <iostream>
#include <cstdlib>

// 以下のinclude順番を変えるとビルドエラーになる
// --------------------------------------
#include <GL/glew.h>        // step 1
//#include <glad/glad.h>
#include <GLFW/glfw3.h>     // step 2

void ne_glfwinit();
GLFWwindow* ne_createWindow(float width, float height, const char* title);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
bool ne_glewInit();

#endif /* Test_hpp */
