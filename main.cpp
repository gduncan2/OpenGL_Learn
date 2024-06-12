#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include <stb/stb_image.h>	
#include<Windows.h>

#include"shaderClass.h"
#include "VertexController.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"



// Vertices coordinates
GLfloat scDIM = 880.0f;
GLfloat brightness = 1.0f;
GLfloat scale = 1.0f;
GLfloat vertices[] =
{   // Positions			// Colors					//Brightness	//Scale
	-0.05f,-0.15f, 0.0f,	1.0f, 0.0f, 0.0f, 1.0f,		brightness,		scale,
	-0.05f, 0.15f, 0.0f,	1.0f, 1.0f, 0.0f, 1.0f,		brightness,		scale,
	0.25f, 0.15f, 0.0f,		0.0f, 0.0f, 1.0f, 1.0f,		brightness,		scale,
	0.25f, -0.15f, 0.0f,	0.0f, 1.0f, 0.0f, 1.0f,		brightness,		scale
};





// Indices for vertices order
GLuint indices[] =
{
	0, 1, 2,   // First triangle
	0, 2, 3    // Second triangle
};



int main()
{
	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using 
	// In this case we are using OpenGL
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFWwindow object
	GLFWwindow* window = glfwCreateWindow(scDIM, scDIM, "Yup", NULL, NULL);
	// Error check if the window fails to create
	if (!window)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	glViewport(0, 0, scDIM, scDIM);



	// Generates Shader object using shaders defualt.vert and default.frag
	Shader shaderProgram("default.vert", "default.frag");



	// Generates Vertex Array Object and binds it
	VAO VAO1;
	VAO1.Bind();

	// Generates Vertex Buffer Object and links it to vertices
	VBO VBO1(vertices, sizeof(vertices));
	// Generates Element Buffer Object and links it to indices
	EBO EBO1(indices, sizeof(indices));

	// Links VBO to VAO

	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 9 * sizeof(float), (void*)0); // 
	VAO1.LinkAttrib(VBO1, 1, 4, GL_FLOAT, 9 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO1.LinkAttrib(VBO1, 2, 1, GL_FLOAT, 9 * sizeof(float), (void*)(7 * sizeof(GLfloat)));
	VAO1.LinkAttrib(VBO1, 3, 1, GL_FLOAT, 9 * sizeof(float), (void*)(8 * sizeof(GLfloat)));

	// Unbind all to prevent accidentally modifying them
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();


	GLfloat x = 0.02f;
	GLfloat y = 0.02f;
	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		VAO1.Bind();

		// Generates Vertex Buffer Object and links it to vertices
		VBO VBO1(vertices, sizeof(vertices));
		// Generates Element Buffer Object and links it to indices
		EBO EBO1(indices, sizeof(indices));
		// Links VBO to VAO
		// Unbind all to prevent accidentally modifying them
		VAO1.Unbind();
		VBO1.Unbind();
		EBO1.Unbind();
		// Specify the color of the background
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT);
		// Tell OpenGL which Shader Program we want to use
		shaderProgram.Activate();
		// Bind the VAO so OpenGL knows to use it
		VAO1.Bind();

		moveShape(vertices, x, y, scDIM, sizeof(vertices));
		VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 9 * sizeof(float), (void*)0);
		// Draw primitives, number of indices, datatype of indices, index of indices
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		Sleep(10);
		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}



	// Delete all the objects we've created
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	shaderProgram.Delete();
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}