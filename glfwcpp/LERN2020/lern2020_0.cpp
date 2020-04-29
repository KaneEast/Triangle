#ifdef k_DEF_LERN2020_0

#include "all.h"
// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
    ne_glfwinit();
    
    // glfw window creation
    // --------------------
    GLFWwindow* window = ne_createWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL");
    if (window == NULL) {
        return -1;
    }
    
//    // glad: load all OpenGL function pointers
//    // ---------------------------------------
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//    {
//        std::cout << "Failed to initialize GLAD" << std::endl;
//        return -1;
//    }
    
    // 作成したウィンドウを OpenGL の処理対象にする
    glfwMakeContextCurrent(window);
    
    // 背景色を指定する
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    
     // ウィンドウが開いている間繰り返す
    while (glfwWindowShouldClose(window) == GL_FALSE)
    {
        // ウィンドウを消去する
        glClear(GL_COLOR_BUFFER_BIT);
        
        //
        // ここで描画処理を行う
        //
        
         // カラーバッファを入れ替える
        glfwSwapBuffers(window);
         // イベントを取り出す
        glfwWaitEvents();
    }
}

#endif
