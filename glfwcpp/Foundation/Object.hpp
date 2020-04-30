//
//  Object.hpp
//  glfwcpp
//
//  Created by inman on 2020/04/29.
//  Copyright © 2020 inman. All rights reserved.
//

#ifndef Object_hpp
#define Object_hpp

#include "all.h"

struct Vertex
{
    GLfloat position[3];
};

// 図形データ
class Object
{
protected:
    // 頂点配列オブジェクト名
    GLuint vao = -1;
    
    // 頂点バッファオブジェクト名
    GLuint vbo = -1;
    
    // エレメンバッファオブジェクト名
    GLuint ebo = -1;
    
public:
    // コンストラクタ
    // size: 頂点の位置の次元
    // vertexcount: 頂点の数
    Object(GLint size, GLsizei vertexcount, const Vertex* vertex, const unsigned int indices[], GLsizei indicecount);
    virtual ~Object();
    
    // 頂点配列オブジェクトの結合
    void bind() const;
    
    GLuint getVAO() const;
    
private:
    // コピーコンストラクタによるコピー禁止
    Object(const Object &o);
    // 代入によるコピー禁止
    Object &operator=(const Object &o);
};

#endif /* Object_hpp */
