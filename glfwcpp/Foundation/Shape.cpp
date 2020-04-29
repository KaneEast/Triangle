//
//  Shape.cpp
//  glfwcpp
//
//  Created by inman on 2020/04/29.
//  Copyright © 2020 inman. All rights reserved.
//

#include "Shape.hpp"
#include "Object.hpp"

Shape::Shape(GLint size, GLsizei vertexcount, const Vertex * vertex)
:object(new Object(size, vertexcount, vertex))
,vertexcount(vertexcount)
{
    
}

void Shape::draw() const
{
    // 頂点配列オブジェクトを結合する
    this->object->bind();
    // 描画を実行する
    execute();
}

// 描画の実行
void Shape::execute() const
{
    // 頂点配列を用いて図形を描画
    // param1: 描画する基本図形の種類
    // param2: 描画する頂点の先頭の番号。頂点バッファオブジェクトの先頭の頂点から描画するなら 0。
    // param3: 描画する頂点の数。たとえば四角形なら 4
    
    
    // 折れ線で描画する
    glDrawArrays(GL_LINE_LOOP, 0, vertexcount);
    
    // 面が描画できる
    // glDrawArrays(GL_TRIANGLE_STRIP, 0, vertexcount);
}
