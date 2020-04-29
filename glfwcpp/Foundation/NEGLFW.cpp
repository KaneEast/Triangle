
#include "NEGLFW.hpp"

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

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

// glfw window creation
// --------------------
GLFWwindow* ne_createWindow(float width, float height, const char* title)
{
    // ウィンドウを作成する
    GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        // ウィンドウが閉じたら終了処理を行う
        glfwTerminate();
        return NULL;
    }
//    glfwMakeContextCurrent(window); //TODO: ??
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    return window;
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
