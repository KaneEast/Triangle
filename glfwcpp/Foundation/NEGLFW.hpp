#ifndef NEGLFW_hpp
#define NEGLFW_hpp

#include <iostream>
#include <cstdlib>
#include <GL/glew.h>
//#include <glad/glad.h>
#include <GLFW/glfw3.h>

void ne_glfwinit();
GLFWwindow* ne_createWindow(float width, float height, const char* title);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

#endif /* Test_hpp */
