
#include "NEGLFW.hpp"

#define RESIZE_VIEWPORT     0

void ne_glfwinit()
{
    // GLFW を初期化する
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif
    
    atexit(glfwTerminate);
}

bool ne_glewInit()
{
    // GLEW を初期化する
    // ハードウェアやドライバには用意されているにも関わらず、プラットフォームではサポートさ れていない OpenGL の機能を有効にし、プログラムから呼び出せるようにします。
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        // GLEW の初期化に失敗した
        std::cerr << "Can't initialize GLEW" << std::endl;
        return false;
    }
    return true;
}
