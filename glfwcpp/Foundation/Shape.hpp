//
//  Shape.hpp
//  glfwcpp
//
//  Created by inman on 2020/04/29.
//  Copyright © 2020 inman. All rights reserved.
//

#ifndef Shape_hpp
#define Shape_hpp

#include "all.h"
//#include "Object.hpp"
class Object;
class Vertex;

// 図形の描画
class Shape
{
public:
    // 図形データ
    std::shared_ptr<const Object> object;
    
protected:
    // 描画に使う頂点の数
    const GLsizei vertexcount;
    
    bool isFill;
    
    GLuint indiceCount = 0;
    
public:
    // コンストラクタ
    // size: 頂点の位置の次元
    // vertexcount: 頂点の数
    // indices: EBO対象
    // indicecount: EBO頂点の数
    // isFill: 内部をFillするか
    Shape(GLint size, GLsizei vertexcount, const Vertex * vertex, const unsigned int indices[] = nullptr, GLsizei indicecount = 0, bool isFill = true);
    
    // 描画
    void draw() const;
    
    // 描画の実行
    virtual void execute() const;
};

//class Triangle : public Shape
//{
//public:
//    // コンストラクタ
//    // size: 頂点の位置の次元
//    // vertexcount: 頂点の数
//    Triangle(GLint size, GLsizei vertexcount, const Vertex * vertex, const int indices[]);
//    
//    // 描画の実行
//    virtual void execute() const;
//};

#endif /* Shape_hpp */
