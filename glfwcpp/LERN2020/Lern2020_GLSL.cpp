#ifdef k_DEF_LERN2020GLSL

#define STB_IMAGE_IMPLEMENTATION
#include "all.h"


//Vertex vertices[] = {
////     ---- 位置 ----       ---- 颜色 ----     - 纹理坐标 -
//    {0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f},   // 右上
//    {0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f},   // 右下
//    {-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f},   // 左下
//    {-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f}    // 左上
//};


Vertex vertices[] = {
//     ---- 位置 ----       ---- 颜色 ----     - 纹理坐标 -
    {0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f},   // 右上
    {0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f},   // 右下
    {-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f},   // 左下
    {-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f}    // 左上
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
//    std::string verextCode = readFileToCstr("GLERN2020/lern2020_0.vs");
//    std::string fragCode = readFileToCstr("GLERN2020/lern2020_0.fs");
    std::string verextCode = readFileToCstr("GLERN2020/lern2020_1.vs");
    std::string fragCode = readFileToCstr("GLERN2020/lern2020_1.fs");
    shader.Compile(verextCode.c_str(), fragCode.c_str());
    
    // 描画する対象
    std::unique_ptr<const Shape> shape(new Shape(3, 4, vertices, indices4, 6));
    
    
    // TODO:k make texture code esay 2020 0430
    
    // load and create a texture
    // -------------------------
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);    // set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
    int width, height, nrChannels;
    // The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
    unsigned char *data = stbi_load("textures/container.jpg", &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
    
    
    
    while (window)
    {
        // ウィンドウを消去する
        glClear(GL_COLOR_BUFFER_BIT);
        
        // ここで描画処理を行う
        // bind Texture
        glBindTexture(GL_TEXTURE_2D, texture);
        shader.Use();
        
        
        // 図形を描画する
        shape->draw();
        
         // カラーバッファを入れ替える
        window.swapBuffers();
        
        std::cout << "Frame runs" << glfwGetTime() << std::endl;
    }
}

#endif
