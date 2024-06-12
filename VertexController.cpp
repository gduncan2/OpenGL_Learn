#include "VertexController.h"
#include <iostream>

void moveShape(GLfloat* vertices, GLfloat& x, GLfloat& y, float scDim, unsigned long long size)
{
	size = size / sizeof(GLfloat);
	std::cout << "Run" << std::endl;
	for (int i = 0; i < size; i += 9)
	{
		vertices[i] += x;
		vertices[i + 1] += y;
		std::cout<< vertices[i] << "x" << std::endl;
		std::cout << vertices[i + 1] << "y" << std::endl;
		if(abs(vertices[i]) >= 1.0f && abs(vertices[i + 1]) >= 1.0f)
		{
			y = -y;
			x = -x;
		}
		if(abs(vertices[i]) >= 1.0f)
		{
			x = -x;

		}
		if (abs(vertices[i + 1]) >= 1.0f)
		{
			y = -y;
		}
	}

	std::cout << std::endl;
}
