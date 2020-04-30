#ifdef k_DEF_LERN2020_0

#include "all.h"

// 1 ---------------------
constexpr Vertex cubeVertex[] = {
    {-1.f,-1.f,-1.f,  0.0f,0.0f,0.0f},
    {-1.f,-1.f,1.f,   0.0f,0.0f,0.8f},
    {-1.f,1.f,1.f,   0.0f,0.8f,0.f},
    {-1.f,1.f,-1.f,   0.0f,0.8f,0.8f},
    
    {1.f,1.f,-1.f,   0.8f,0.f,0.8f},
    {1.f,-1.f,-1.f,   0.8f,0.0f,0.8f},
    {1.f,-1.f,1.f,   0.8f,0.8f,0.f},
    {1.f,1.f,1.f,   0.8f,0.8f,0.8f},
};

//// 矩形の頂点の位置
//constexpr Vertex rectangleVertex[] = {
//    { -0.5f, -0.5f },
//    { 0.5f, -0.5f },
//    { 0.5f, 0.5f },
//    { -0.5f, 0.5f }
//};
//
//// 八面体の頂点の位置
//Vertex octahedronVertex[] = {
//    { 0.0f, 1.0f, 0.0f },
//    { -1.0f, 0.0f, 0.0f },
//    { 0.0f, -1.0f, 0.0f },
//    { 1.0f, 0.0f, 0.0f },
//    { 0.0f, 1.0f, 0.0f },
//    { 0.0f, 0.0f, 1.0f },
//    { 0.0f, -1.0f, 0.0f },
//    { 0.0f, 0.0f, -1.0f },
//    { -1.0f, 0.0f, 0.0f },
//    { 0.0f, 0.0f, 1.0f },
//    { 1.0f, 0.0f, 0.0f },
//    { 0.0f, 0.0f, -1.0f }
// };

// 4 -----------------------
Vertex vertices4[] = {
    {0.5f, 0.5f, 0.0f},   // 右上角
    {0.5f, -0.5f, 0.0f},  // 右下角
    {-0.5f, -0.5f, 0.0f},// 左下角
    {-0.5f, 0.5f, 0.0f}   // 左上角
};

unsigned int indices4[] = { // 注意索引从0开始!
    0, 1, 3, // 第一个三角形
    1, 2, 3  // 第二个三角形
};

int main()
{
    Window::wd_init();
    Window window = Window(400, 300, "GAME2020_0");
    Window::wd_glewInit();
    
    Shader shader;
    std::string verextCode = readFileToCstr("L2020_0.vs");
    std::string fragCode = readFileToCstr("L2020_0.fs");
    shader.Compile(verextCode.c_str(), fragCode.c_str());
    
    // 描画する対象
//    std::unique_ptr<const Shape> shape(new Shape(3, 12, octahedronVertex));
//    std::unique_ptr<const Shape> shape(new Shape(4, 4, rectangleVertex));
//    std::unique_ptr<const Shape> shape(new Shape(3, 3, vertices, nullptr, 0));
    std::unique_ptr<const Shape> shape(new Shape(3, 4, vertices4, indices4, 6));
    
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
    }
}

#endif
