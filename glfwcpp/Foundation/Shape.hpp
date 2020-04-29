//
//  Shape.hpp
//  glfwcpp
//
//  Created by inman on 2020/04/29.
//  Copyright © 2020 inman. All rights reserved.
//

#ifndef Shape_hpp
#define Shape_hpp

#include "Object.hpp"

class Shape
{
    std::shared_ptr<const Object> object;
    
protected:
    
    //
    const GLsizei vertexcount;
    
public:
    Shape(GLint size, GLsizei vertexcount, const Object::Vertex * vertex);
    
    void draw() const;
    
    virtual void execute() const;
};

#endif /* Shape_hpp */
