//
//  Object.cpp
//  glfwcpp
//
//  Created by inman on 2020/04/29.
//  Copyright © 2020 inman. All rights reserved.
//

#include "Object.hpp"

Object::Object(GLint size, GLsizei vertexcount, const Vertex* vertex)
{
    //
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    
    //
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vertexcount * sizeof(Vertex), vertex, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, size, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);
}

Object::~Object()
{
    //
    glDeleteVertexArrays(1, &vao);
    
    //
    glDeleteBuffers(1, &vbo);
}

void Object::bind() const
{
    glBindVertexArray(vao);
}