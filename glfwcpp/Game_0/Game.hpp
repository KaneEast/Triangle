//
//  Game.hpp
//  glfwcpp
//
//  Created by USER on 2020/05/01.
//  Copyright © 2020 inman. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

#include "GameLevel.hpp"
#include <learnopengl/sprite_renderer.h>


enum GameState {
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
};

// Initial size of the player paddle
const glm::vec2 PLAYER_SIZE(100, 20);
// Initial velocity of the player paddle
const GLfloat PLAYER_VELOCITY(500.0f);

// Game holds all game-related state and functionality.
// Combines all game-related data into a single class for
// easy access to each of the components and manageability.
class Game
{
public:
    // Game state
    GameState              State;
    GLboolean              Keys[1024];
    GLuint                 Width, Height;
    std::vector<GameLevel> Levels;
    GLuint                 Level;
    // Constructor/Destructor
    Game(GLuint width, GLuint height);
    ~Game();
    // Initialize game state (load all shaders/textures/levels)
    void Init();
    // GameLoop
    void ProcessInput(GLfloat dt);
    void Update(GLfloat dt);
    void Render();
};

#endif /* Game_hpp */
