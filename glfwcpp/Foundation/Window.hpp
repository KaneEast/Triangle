//
//  Window.hpp
//  glfwcpp
//
//  Created by inman on 2020/04/29.
//  Copyright © 2020 inman. All rights reserved.
//

#ifndef Window_hpp
#define Window_hpp

#include "all.h"

class Window
{
    // ウィンドウのハンドル
    GLFWwindow * const window;
    
    // ウィンドウのサイズ
    GLfloat size[2];
    
    // ワールド座標系に対するデバイス座標系の拡大率
    GLfloat scale;
    
public:
    Window(int width = 640, int height = 480, const char* title = "Hello")
    :window(glfwCreateWindow(width, height, title, NULL, NULL))
    ,scale(100.f)
    {
        if (window == NULL)
        {
            std::cerr << "Can't create GLFW window." << std::endl;
            exit(1);
        }
        
        // 作成したウィンドウを OpenGL の処理対象にする
        glfwMakeContextCurrent(window);
        
        glewExperimental = GL_TRUE;
        if (glewInit() != GLEW_OK)
        {
            std::cerr << "Can't initialize GLEW" << std::endl;
            exit(1);
        }
        
        // 垂直同期のタイミングを待つ
        glfwSwapInterval(1);
        
        // このインスタンスのthisポインタを記録しておく
        glfwSetWindowUserPointer(window, this);
        
        glfwSetWindowSizeCallback(window, resize);
        resize(window, width, height);
        
        // 背景色を指定する
        glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    }
    
    virtual ~Window()
    {
        glfwDestroyWindow(window);
    }
    
    // 描画ループの継続判定
    explicit operator bool()
    {
        // イベントを取り出す
//        glfwWaitEvents();// ループをBlockする
        glfwPollEvents();// ループをBlockしない
        
        //ウィンドウを閉じる必要がkなければtrueを返す
        return !glfwWindowShouldClose(window);
    }
    
    // ダブルバッファリング
    void swapBuffers() const
    {
        // カラーバッファを入れ替える
        glfwSwapBuffers(window);
    }
    
    static void resize(GLFWwindow* const window, int width, int height)
    {
        // フレームバッファのしサイズを調べる
        int fbWidth, fbHeight;
        glfwGetFramebufferSize(window, &fbWidth, &fbHeight);
        
        // フレームバッファ全体をビューポートに設定する
        glViewport(0, 0, fbWidth, fbHeight);
        
        // このインスタンスのthisポインタを得る
        Window* const instance = static_cast<Window*>(glfwGetWindowUserPointer(window));
        if (instance) {
            instance->size[0] = width;
            instance->size[1] = height;
        }
    }
    
    const GLfloat* getsize() const { return size; }
    GLfloat getScale() const { return scale; }
    
    static void wd_init()
    {
        // GLFW を初期化する
        glfwInit();
        // OpenGL Version 3.3 Core Profile を選択する
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
    #endif
        atexit(glfwTerminate);
    }
    
    static void wd_glewInit()
    {
        // GLEW を初期化する
        // ハードウェアやドライバには用意されているにも関わらず、プラットフォームではサポートさ れていない OpenGL の機能を有効にし、プログラムから呼び出せるようにします。
        glewExperimental = GL_TRUE;
        if (glewInit() != GLEW_OK)
        {
            // GLEW の初期化に失敗した
            std::cerr << "Can't initialize GLEW" << std::endl;
            exit(1);
        }
    }

};

#endif /* Window_hpp */
