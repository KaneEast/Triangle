#ifdef k_DEF_LERN2020_0

#include "all.h"
#include "Shape.hpp"
#include "shader_s.h"

//constexpr Object::Vertex rectangleVertex[] =
//{
//    {-0.5f, -0.5f},
//    {.5f, -.5f},
//    {.5f, .5f},
//    {-0.5f, .5f},
//};
// 八面体の頂点の位置
constexpr Object::Vertex octahedronVertex[] = {
    { 0.0f, 1.0f, 0.0f },
    { -1.0f, 0.0f, 0.0f },
    { 0.0f, -1.0f, 0.0f },
    { 1.0f, 0.0f, 0.0f },
    { 0.0f, 1.0f, 0.0f },
    { 0.0f, 0.0f, 1.0f },
    { 0.0f, -1.0f, 0.0f },
    { 0.0f, 0.0f, -1.0f },
    { -1.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 1.0f },
    { 1.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, -1.0f }
 };

int main()
{
    ne_glfwinit();
    Window window = Window(800, 600, "GAME2020_0");
    
    // GLEW を初期化する
    if (!ne_glewInit()) {
        return -1;
    }
    
    // 垂直同期のタイミングを待つ
    glfwSwapInterval(1);
    
    // 背景色を指定する
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    
    glViewport(100, 50, 300, 300);
    
//    const GLuint program(loadProgram("point.vert", "point.frag"));
    Shader_s ourShader = Shader_s("L2020_0.vs", "L2020_0.fs");
    
    std::unique_ptr<const Shape> shape(new Shape(3, 12, octahedronVertex));
    
    // ウィンドウが開いている間繰り返す
    while (window)
    {
        // ウィンドウを消去する
        glClear(GL_COLOR_BUFFER_BIT);
        
        // ここで描画処理を行う
        ourShader.use();
        
        // uniform変数に値を設定する
        ourShader.setVec2("size", window.getsize()[0], window.getsize()[1]);
        ourShader.setFloat("scale", window.getScale());
        
        // 図形を描画する
        shape->draw();
        
         // カラーバッファを入れ替える
        window.swapBuffers();
         // イベントを取り出す
        glfwWaitEvents();
    }
}

#endif
