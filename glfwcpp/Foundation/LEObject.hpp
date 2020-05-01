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

// LE: lern
struct LEVertex
{
    GLfloat position[3];
    GLfloat color[3];
    GLfloat texture[2];
};

// 図形データ
class LEObject
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
    LEObject(GLint size, GLsizei vertexcount, const LEVertex* vertex, const unsigned int indices[], GLsizei indicecount);
    virtual ~LEObject();
    
    void configure();
    
    // 頂点配列オブジェクトの結合
    void bind() const;
    
    GLuint getVAO() const;
    
private:
    // コピーコンストラクタによるコピー禁止
    LEObject(const LEObject &o);
    // 代入によるコピー禁止
    LEObject &operator=(const LEObject &o);
};

#endif /* Object_hpp */
