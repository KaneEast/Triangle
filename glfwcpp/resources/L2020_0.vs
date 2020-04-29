#version 330 core
layout (location = 0)
in vec4 position;
uniform vec2 size;
uniform float scale;
void main()
{
    gl_Position = vec4(2.0 * scale / size, 1.0, 1.0) * position;
}
