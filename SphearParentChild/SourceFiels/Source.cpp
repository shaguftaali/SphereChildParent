#include <GL/glew.h>
#include <GLFW/glfw3.h> 

#include "..\Includes\Shader.h"
#include <iostream>
#include "../Includes/Shapes/Grid.h"
#include "../Includes/3D/Camera.h"
#include "../Includes/Maths/Transform.h"
#include "../Includes/Shapes/Sphere.h"
#include "../Includes/Shapes/Circle.h"
#include "Shapes/Cube.h"
#include "Shapes/Torus.h"
#include "Physics/PhysicsObject.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);


// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 800;


int main(int argc, char* argv[])
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	glewInit();

	Shader ourShader("D:/Shagufta/OpenGL_Workspace/SphearParentChild/SphearParentChild/Shaders/LightVertexShader.vs", "D:/Shagufta/OpenGL_Workspace/SphearParentChild/SphearParentChild/Shaders/LightFragmentShader.fs");

	//Shader ourShader("D:/Shagufta/OpenGL_Workspace/BouncingBall/BouncingBall/Shader/LightVertexShader.vs", "D:/Shagufta/OpenGL_Workspace/BouncingBall/BouncingBall/Shader/LightFragmentShader.fs");
	glEnable(GL_DEPTH_TEST);

	PhysicsObject::Test();
	
	
	Camera camera(Vector3(0,0,-50), Vector3(0,0,0), 500, .005f, 60);
	float angle=0;


	//std::cout<<data.GetDoesIntersect()<<std::endl;
	
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);
		angle+=.1f/10.0f;
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	
//	grid.DeleteDrawingData();

	
}

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that gridSize and 
	// cellCount will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}