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

class Object
{
    // 頂点配列オブジェクト名
    GLuint vao;
    
    // 頂点バッファオブジェクト名
    GLuint vbo;
    
public:
    
    //
    struct Vertex
    {
        GLfloat position[2];
    };
    
    Object(GLint size, GLsizei vertexcount, const Vertex* vertex);
    virtual ~Object();
    
    void bind() const;
    
private:
    Object(const Object &o);
    Object &operator=(const Object &o);
};

#endif /* Object_hpp */
