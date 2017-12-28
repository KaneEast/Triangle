#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

// texture sampler
uniform sampler2D texture1;
uniform sampler2D texture2;
uniform float mixVal;

void main()
{
//    FragColor = texture(texture1, TexCoord);
//    FragColor = texture(texture1, TexCoord) * vec4(ourColor, 1.0);
    
    // linearly interpolate between both textures (80% container, 20% awesomeface)
    FragColor = mix(texture(texture1, TexCoord), texture(texture2, TexCoord), mixVal);
}
