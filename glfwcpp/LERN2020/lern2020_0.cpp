#ifdef k_DEF_LERN2020_0

#include "all.h"

// 八面体の頂点の位置
Vertex octahedronVertex[] = {
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
    Window::wd_init();
    Window window = Window(800, 600, "GAME2020_0");
    Window::wd_glewInit();
    
    glViewport(100, 50, 300, 300);
    
    Shader shader;
    std::string verextCode = readFileToCstr("L2020_0.vs");
    std::string fragCode = readFileToCstr("L2020_0.fs");
    shader.Compile(verextCode.c_str(), fragCode.c_str());
    
    // 描画する対象
    std::unique_ptr<const Shape> shape(new Shape(3, 12, octahedronVertex));
    
    while (window)
    {
        // ウィンドウを消去する
        glClear(GL_COLOR_BUFFER_BIT);
        
        // ここで描画処理を行う
        // uniform変数に値を設定する
        shader.SetVector2f("size", window.getsize()[0], window.getsize()[1], true);
        shader.SetFloat("scale", window.getScale(), true);
        // 図形を描画する
        shape->draw();
        
         // カラーバッファを入れ替える
        window.swapBuffers();
         // イベントを取り出す
        glfwWaitEvents();
    }
}

#endif
