#include <GLFW/glfw3.h>
#include <GL/glu.h>

#include <iostream>
#include <stdio.h>



GLfloat escala = 1.0;
GLfloat angulo = 0.0;
GLfloat dx = 0.0; 
GLfloat dy = 0.0;

// para exibir um contador do número de trasformações aplicadas
int contador = 0;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_1 && action == GLFW_PRESS){
		contador++;

		angulo += 2;
		
		std::cout << contador << "- Aplicado transformação de rotação\n";
	}
	if (key == GLFW_KEY_2 && action == GLFW_PRESS){
		contador++;

		escala += 0.1;

		std::cout << contador << "- Aplicado transformação de escala\n";

	}
	if (key == GLFW_KEY_3 && action == GLFW_PRESS) {
		contador++;

		dx += 0.2;
		dy += 0.2;

		std::cout << contador << "- Aplicado transformação de translação\n";
	}
	if (key == GLFW_KEY_4 && action == GLFW_PRESS){
		contador++;

		angulo += 2;
		escala += 0.1;
		
		std::cout << contador << "- Aplicado composição de transformações: rotação e escala\n";
	}
	if (key == GLFW_KEY_5 && action == GLFW_PRESS){
		contador++;

		angulo += 2;
		dx += 0.2;
		dy += 0.2;
		
		std::cout << contador << "- Aplicado composição de transformações: rotação e translação\n";
	}
	if (key == GLFW_KEY_6 && action == GLFW_PRESS){
		contador++;

		angulo += 2;
		escala += 0.1;
		dx += 0.2;
		dy += 0.2;
		
		std::cout << contador << "- Aplicado composição de transformações: rotação, escala e translação\n";
	}
}

void redimensiona(int w, int h)
{
	glViewport(0, 0, w, h);

	float aspect = (float)w / (float)h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, aspect, 0.1, 500.0);

	glMatrixMode(GL_MODELVIEW);
}

void desenharQuadrado(){ 
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(-2.5, -2.5, 0.0);
	glVertex3f(2.5, -2.5, 0.0);
	glVertex3f(2.5, 2.5, 0.0);
	glVertex3f(-2.5, 2.5, 0.0);
	glEnd();
}

void desenha()
{
	glLoadIdentity();
	
	glTranslated(dx, dy, -50.0);

	glRotated(angulo, 0.0, 0.0, 1.0);

	glScaled(escala, escala, 0.0);

	desenharQuadrado();
}


int main(void)
{

	const int LARGURA = 800;
	const int ALTURA = 600;

	/* Initialize the library */
	glfwInit();

	/* Create a windowed mode window and its OpenGL context */
	GLFWwindow* window = glfwCreateWindow(LARGURA, ALTURA, "Computação Gráfica - transformações 2D", NULL, NULL);

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	// -- inicio
	glClearColor(0.12, 0.29, 0.52, 1.0); // cor de fundo
	glEnable(GL_DEPTH_TEST);

	printf("Comandos:\n 1- aplicar rotação\n 2- aplicar escala\n 3- aplicar translação\n 4- aplicar composição de transformações: rotação e escala\n 5- aplicar composição de transformações: rotação e translação\n 6- aplicar composição de transformações: rotação, escala e translação\n\n");


	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Poll for and process events */
		glfwPollEvents();
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(window, GLFW_TRUE);
		}

		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		int largura, altura;
		glfwGetFramebufferSize(window, &largura, &altura);

		redimensiona(largura, altura);

		desenha();

		glfwSetKeyCallback(window, key_callback);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}