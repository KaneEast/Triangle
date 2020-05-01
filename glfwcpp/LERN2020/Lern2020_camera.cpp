#ifdef k_DEF_LERN2020_CAMERA

#define STB_IMAGE_IMPLEMENTATION
#include "all.h"


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 400;
const unsigned int SCR_HEIGHT = 300;

 void framebuffer_size_callback(GLFWwindow* window, int width, int height);
 void mouse_callback(GLFWwindow* window, double xpos, double ypos);
 void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
 void processInput(GLFWwindow *window);

 // camera
 Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
 float lastX = SCR_WIDTH / 2.0f;
 float lastY = SCR_HEIGHT / 2.0f;
 bool firstMouse = true;

 // timing
 float deltaTime = 0.0f;    // time between current frame and last frame
 float lastFrame = 0.0f;

 int main()
 {
     Window::wd_init();
     Window window = Window(400, 300, "GAME2020_0");
     Window::wd_glewInit();
     
//     glfwMakeContextCurrent(window);
     glfwSetFramebufferSizeCallback(window.window, framebuffer_size_callback);
     glfwSetCursorPosCallback(window.window, mouse_callback);
     glfwSetScrollCallback(window.window, scroll_callback);
     

     // configure global opengl state
     // -----------------------------
     glEnable(GL_DEPTH_TEST);

     // build and compile our shader zprogram
     // ------------------------------------
     std::string verextCode = readFileToCstr("7.4.camera.vs");
     std::string fragCode = readFileToCstr("7.4.camera.fs");
     Shader ourShader;
     ourShader.Compile(verextCode.c_str(), fragCode.c_str());

     // configure global opengl state
     // -----------------------------
     glEnable(GL_DEPTH_TEST);

     // set up vertex data (and buffer(s)) and configure vertex attributes
     // ------------------------------------------------------------------
     float vertices[] = {
         -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
          0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
          0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
          0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
         -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

         -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
          0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
          0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
          0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
         -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
         -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

         -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

          0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
          0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
          0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
          0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
          0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
          0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

         -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
          0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
          0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
          0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

         -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
          0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
          0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
          0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
         -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
     };
     // world space positions of our cubes
     glm::vec3 cubePositions[] = {
         glm::vec3( 0.0f,  0.0f,  0.0f),
         glm::vec3( 2.0f,  5.0f, -15.0f),
         glm::vec3(-1.5f, -2.2f, -2.5f),
         glm::vec3(-3.8f, -2.0f, -12.3f),
         glm::vec3( 2.4f, -0.4f, -3.5f),
         glm::vec3(-1.7f,  3.0f, -7.5f),
         glm::vec3( 1.3f, -2.0f, -2.5f),
         glm::vec3( 1.5f,  2.0f, -2.5f),
         glm::vec3( 1.5f,  0.2f, -1.5f),
         glm::vec3(-1.3f,  1.0f, -1.5f)
     };
     unsigned int VBO, VAO;
     glGenVertexArrays(1, &VAO);
     glGenBuffers(1, &VBO);

     glBindVertexArray(VAO);

     glBindBuffer(GL_ARRAY_BUFFER, VBO);
     glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

     // position attribute
     glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
     glEnableVertexAttribArray(0);
     // texture coord attribute
     glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
     glEnableVertexAttribArray(1);


     // load and create a texture
     // -------------------------
     unsigned int texture1, texture2;
     // texture 1
     // ---------
     glGenTextures(1, &texture1);
     glBindTexture(GL_TEXTURE_2D, texture1);
     // set the texture wrapping parameters
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
     // set texture filtering parameters
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
     // load image, create texture and generate mipmaps
     int width, height, nrChannels;
     stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
     unsigned char *data = stbi_load("textures/container.jpg", &width, &height, &nrChannels, 0);
     if (data)
     {
         glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
         glGenerateMipmap(GL_TEXTURE_2D);
     }
     else
     {
         std::cout << "Failed to load texture" << std::endl;
     }
     stbi_image_free(data);
     // texture 2
     // ---------
     glGenTextures(1, &texture2);
     glBindTexture(GL_TEXTURE_2D, texture2);
     // set the texture wrapping parameters
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
     // set texture filtering parameters
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
     // load image, create texture and generate mipmaps
     data = stbi_load("textures/awesomeface.png", &width, &height, &nrChannels, 0);
     if (data)
     {
         // note that the awesomeface.png has transparency and thus an alpha channel, so make sure to tell OpenGL the data type is of GL_RGBA
         glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
         glGenerateMipmap(GL_TEXTURE_2D);
     }
     else
     {
         std::cout << "Failed to load texture" << std::endl;
     }
     stbi_image_free(data);

     // tell opengl for each sampler to which texture unit it belongs to (only has to be done once)
     // -------------------------------------------------------------------------------------------
     ourShader.Use();
     ourShader.SetInteger("texture1", 0);
     ourShader.SetInteger("texture2", 1);


     // render loop
     // -----------
     while (window)
     {
         // per-frame time logic
         // --------------------
         float currentFrame = glfwGetTime();
         deltaTime = currentFrame - lastFrame;
         lastFrame = currentFrame;

         // input
         // -----
         processInput(window.window);

         // render
         // ------
         glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

         // bind textures on corresponding texture units
         glActiveTexture(GL_TEXTURE0);
         glBindTexture(GL_TEXTURE_2D, texture1);
         glActiveTexture(GL_TEXTURE1);
         glBindTexture(GL_TEXTURE_2D, texture2);

         // activate shader
         ourShader.Use();

         // pass projection matrix to shader (note that in this case it could change every frame)
         glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
         ourShader.SetMatrix4("projection", projection, true);

         // camera/view transformation
         glm::mat4 view = camera.GetViewMatrix();
         ourShader.SetMatrix4("view", view, true);

         // render boxes
         glBindVertexArray(VAO);
         for (unsigned int i = 0; i < 10; i++)
         {
             // calculate the model matrix for each object and pass it to shader before drawing
             glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
             model = glm::translate(model, cubePositions[i]);
             float angle = 20.0f * i;
             model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
             ourShader.SetMatrix4("model", model, true);

             glDrawArrays(GL_TRIANGLES, 0, 36);
         }

         // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
         // -------------------------------------------------------------------------------
//         glfwSwapBuffers(window);
         window.swapBuffers();
         glfwPollEvents();
     }

     // optional: de-allocate all resources once they've outlived their purpose:
     // ------------------------------------------------------------------------
     glDeleteVertexArrays(1, &VAO);
     glDeleteBuffers(1, &VBO);

     // glfw: terminate, clearing all previously allocated GLFW resources.
     // ------------------------------------------------------------------
     glfwTerminate();
     return 0;
 }

 // process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
 // ---------------------------------------------------------------------------------------------------------
 void processInput(GLFWwindow *window)
 {
     if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
         glfwSetWindowShouldClose(window, true);

     if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
         camera.ProcessKeyboard(FORWARD, deltaTime);
     if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
         camera.ProcessKeyboard(BACKWARD, deltaTime);
     if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
         camera.ProcessKeyboard(LEFT, deltaTime);
     if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
         camera.ProcessKeyboard(RIGHT, deltaTime);
 }

 // glfw: whenever the window size changed (by OS or user resize) this callback function executes
 // ---------------------------------------------------------------------------------------------
 void framebuffer_size_callback(GLFWwindow* window, int width, int height)
 {
     // make sure the viewport matches the new window dimensions; note that width and
     // height will be significantly larger than specified on retina displays.
     glViewport(0, 0, width, height);
 }


 // glfw: whenever the mouse moves, this callback is called
 // -------------------------------------------------------
 void mouse_callback(GLFWwindow* window, double xpos, double ypos)
 {
     if (firstMouse)
     {
         lastX = xpos;
         lastY = ypos;
         firstMouse = false;
     }

     float xoffset = xpos - lastX;
     float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

     lastX = xpos;
     lastY = ypos;

     camera.ProcessMouseMovement(xoffset, yoffset);
 }

 // glfw: whenever the mouse scroll wheel scrolls, this callback is called
 // ----------------------------------------------------------------------
 void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
 {
     camera.ProcessMouseScroll(yoffset);
 }


#endif
