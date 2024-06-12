#version 460 core
out vec4 FragColor;


// Inputs the color from the Vertex Shader
in vec4 color;
// Inputs the texture coordinates from the Vertex Shader
in vec2 texCoord;

// Gets the Texture Unit from the main function
uniform sampler2D tex0;


void main()
{
	FragColor = color;
}