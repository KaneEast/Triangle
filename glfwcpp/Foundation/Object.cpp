//
//  Object.cpp
//  glfwcpp
//
//  Created by inman on 2020/04/29.
//  Copyright © 2020 inman. All rights reserved.
//

#include "Object.hpp"

Object::Object(GLint size, GLsizei vertexcount, const Vertex* vertex, const unsigned int indices[], GLsizei indicecount)
{
    glGenVertexArrays(1, &vao); // 頂点配列オブジェクトを作成します。
    glGenBuffers(1, &vbo);      // 頂点バッファオブジェクト
    
    glBindVertexArray(vao);// 頂点配列オブジェクトを結合して使用可能にします。
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vertexcount * sizeof(Vertex), vertex, GL_STATIC_DRAW);
    
    if (indices != NULL) {
        glGenBuffers(1, &ebo);      // エレメントバッファオブジェクト
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicecount * sizeof(unsigned int), indices, GL_STATIC_DRAW);
    }
    
    // 結合されている頂点バッファオブジェクトを in 変数から参照できるようにする
    glVertexAttribPointer(0, size, GL_FLOAT, GL_FALSE, sizeof (Vertex), static_cast<Vertex *>(0)->position);
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer(1, size, GL_FLOAT, GL_FALSE, sizeof (Vertex), static_cast<Vertex *>(0)->color);
    glEnableVertexAttribArray(1);
    
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof (Vertex), static_cast<Vertex *>(0)->texture);
    glEnableVertexAttribArray(2);
}

Object::~Object()
{
    // 頂点配列オブジェクトを削除する
    glDeleteVertexArrays(1, &vao);
    
    // 頂点バッファオブジェクトを削除する
    glDeleteBuffers(1, &vbo);
    
    // エレメントバッファオブジェクトを削除する
    glDeleteBuffers(1, &ebo);
}

void Object::bind() const
{
    // 描画する頂点配列オブジェクトを指定する
    glBindVertexArray(vao);
}

GLuint Object::getVAO() const
{
    return vao;
}

/*
 glVertexAttribPointer:説明
 TODO:K 日本語に翻訳する
 https://learnopengl-cn.github.io/01%20Getting%20started/04%20Hello%20Triangle/
 
 第一个参数指定我们要配置的顶点属性。还记得我们在顶点着色器中使用layout(location = 0)定义了position顶点属性的位置值(Location)吗？它可以把顶点属性的位置值设置为0。因为我们希望把数据传递到这一个顶点属性中，所以这里我们传入0。
 第二个参数指定顶点属性的大小。顶点属性是一个vec3，它由3个值组成，所以大小是3。
 第三个参数指定数据的类型，这里是GL_FLOAT(GLSL中vec*都是由浮点数值组成的)。
 下个参数定义我们是否希望数据被标准化(Normalize)。如果我们设置为GL_TRUE，所有数据都会被映射到0（对于有符号型signed数据是-1）到1之间。我们把它设置为GL_FALSE。
 第五个参数叫做步长(Stride)，它告诉我们在连续的顶点属性组之间的间隔。由于下个组位置数据在3个float之后，我们把步长设置为3 * sizeof(float)。要注意的是由于我们知道这个数组是紧密排列的（在两个顶点属性之间没有空隙）我们也可以设置为0来让OpenGL决定具体步长是多少（只有当数值是紧密排列时才可用）。一旦我们有更多的顶点属性，我们就必须更小心地定义每个顶点属性之间的间隔，我们在后面会看到更多的例子（译注: 这个参数的意思简单说就是从这个属性第二次出现的地方到整个数组0位置之间有多少字节）。
 最后一个参数的类型是void*，所以需要我们进行这个奇怪的强制类型转换。它表示位置数据在缓冲中起始位置的偏移量(Offset)。由于位置数据在数组的开头，所以这里是0。我们会在后面详细解释这个参数。
 */
