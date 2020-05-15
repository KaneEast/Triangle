//
//  GameLevel.hpp
//  glfwcpp
//
//  Created by USER on 2020/05/15.
//  Copyright © 2020 inman. All rights reserved.
//

#ifndef GameLevel_hpp
#define GameLevel_hpp

#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>

#include "GameObject.hpp"
#include "sprite_renderer.h"
#include <learnopengl/ResourceManager.hpp>

class GameLevel
{
public:
    // Level state
    std::vector<GameObject> Bricks;
    // Constructor
    GameLevel() { }
    // Loads level from file
    void      Load(const GLchar *file, GLuint levelWidth, GLuint levelHeight);
    // Render level
    void      Draw(SpriteRenderer &renderer);
    // Check if the level is completed (all non-solid tiles are destroyed)
    GLboolean IsCompleted();
private:
    // Initialize level from tile data
    void      init(std::vector<std::vector<GLuint>> tileData, GLuint levelWidth, GLuint levelHeight);
};

#endif /* GameLevel_hpp */
