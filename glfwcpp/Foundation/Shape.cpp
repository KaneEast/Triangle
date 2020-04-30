//
//  Shape.cpp
//  glfwcpp
//
//  Created by inman on 2020/04/29.
//  Copyright © 2020 inman. All rights reserved.
//

#include "Shape.hpp"
#include "Object.hpp"

Shape::Shape(GLint size, GLsizei vertexcount, const Vertex * vertex, const unsigned int indices[], GLsizei indicecount, bool isFill)
:object(new Object(size, vertexcount, vertex, indices, indicecount))
,vertexcount(vertexcount)
,isFill(isFill)
,indiceCount(indicecount)
{
    if (isFill) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    } else {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
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
    
    if (indiceCount > 0) {
//        GLuint vao = object->getVAO()
        
//        glBindVertexArray(object->getVAO());
        glDrawElements(GL_TRIANGLES, indiceCount, GL_UNSIGNED_INT, 0);
    } else if (isFill) {
        glDrawArrays(GL_TRIANGLES, 0, vertexcount);
    } else {
        // 折れ線で描画する
        glDrawArrays(GL_LINE_LOOP, 0, vertexcount);
    }
}


//Triangle::Triangle(GLint size, GLsizei vertexcount, const Vertex * vertex, const int indices[])
//:Shape(size, vertexcount, vertex, indices)
//{
//}
//
//void Triangle::execute() const
//{
//    if (vertexcount == 3) {
//        glDrawArrays(GL_TRIANGLES, 0, vertexcount);
//    } else {
//        Shape::execute();
//    }
//}
