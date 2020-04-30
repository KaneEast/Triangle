#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D ourTexture;

void main()
{
    // test step 1
    //FragColor = texture(ourTexture, TexCoord);
    
    // test step 2
    FragColor = texture(ourTexture, TexCoord) * vec4(ourColor, 1.0);
}
