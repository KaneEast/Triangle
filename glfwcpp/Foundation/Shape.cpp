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
    this->object->bind();
    execute();
}

void Shape::execute() const
{
    glDrawArrays(GL_LINE_LOOP, 0, vertexcount);
}
