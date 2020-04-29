#ifdef k_DEF_LERN2020_0

#include "all.h"
#include "Shape.hpp"
#include "shader_s.h"
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

constexpr Object::Vertex rectangleVertex[] =
{
    {-0.5f, -0.5f},
    {0.5f, -0.5f},
    {0.5f, 0.5f},
    {-0.5f, 0.5f},
};

int main()
{
    ne_glfwinit();
    GLFWwindow* window = ne_createWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL");
    if (window == NULL) {
        return -1;
    }
    
    // 作成したウィンドウを OpenGL の処理対象にする
    glfwMakeContextCurrent(window);
    
    // GLEW を初期化する
    if (!ne_glewInit()) {
        return -1;
    }
    
    // 垂直同期のタイミングを待つ
    glfwSwapInterval(1);
    
    // 背景色を指定する
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    
//    const GLuint program(loadProgram("point.vert", "point.frag"));
    Shader_s ourShader = Shader_s("L2020_0.vs", "L2020_0.fs");
    
    std::unique_ptr<const Shape> shape(new Shape(2, 4, rectangleVertex));
    
     // ウィンドウが開いている間繰り返す
    while (glfwWindowShouldClose(window) == GL_FALSE)
    {
        // ウィンドウを消去する
        glClear(GL_COLOR_BUFFER_BIT);
        
        // ここで描画処理を行う
        ourShader.use();
        shape->draw();
        
         // カラーバッファを入れ替える
        glfwSwapBuffers(window);
         // イベントを取り出す
        glfwWaitEvents();
    }
}

#endif
