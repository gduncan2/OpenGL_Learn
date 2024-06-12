#version 460 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aColor;
layout (location = 2) in float aBrightness;
layout (location = 3) in float aScale;
out vec4 color;
void main()
{
   vec3 scaledPos = aPos * aScale;
   gl_Position = vec4(scaledPos, 1.0);
   color = aColor * aBrightness;
}