#include <GLFW/glfw3.h>
#include <GL/glu.h>
#include <iostream>
GLfloat escala = 1.0;
GLfloat angulo = 0.0;
GLfloat dx = 0.0;
GLfloat dy = 0.0;
int contador = 0;
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action != GLFW_PRESS)
        return;
    switch(key) {
        case GLFW_KEY_1:
            contador++;
            angulo += 2;
            std::cout << contador << "- Aplicado transformação de rotação\n";
            break;
        case GLFW_KEY_2:
            contador++;
            escala += 0.1;
            std::cout << contador << "- Aplicado transformação de escala\n";
            break;
        case GLFW_KEY_3:
            contador++;
            dx += 0.2;
            dy += 0.2;
            std::cout << contador << "- Aplicado transformação de translação\n";
            break;
        case GLFW_KEY_4:
            contador++;
            angulo += 2;
            escala += 0.1;
            std::cout << contador << "- Aplicado composição de transformações: rotação e escala\n";
            break;
        case GLFW_KEY_5:
            contador++;
            angulo += 2;
            dx += 0.2;
            dy += 0.2;
            std::cout << contador << "- Aplicado composição de transformações: rotação e translação\n";
            break;
        case GLFW_KEY_6:
            contador++;
            angulo += 2;
            escala += 0.1;
            dx += 0.2;
            dy += 0.2;
            std::cout << contador << "- Aplicado composição de transformações: rotação, escala e translação\n";
            break;
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
void desenharQuadrado()
{
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-2.5, -2.5, 0.0);
    glVertex3f(2.5, -2.5, 0.0);
    glVertex3f(2.5, 2.5, 0.0);
    glVertex3f(-2.5, 2.5, 0.0);
	glEnd();
}
int main(void)
{
	const int LARGURA = 800;
	const int ALTURA = 600;
	glfwInit();
	GLFWwindow *window = glfwCreateWindow(LARGURA, ALTURA, "Computação Gráfica - transformações 2D", NULL, NULL);
	glfwMakeContextCurrent(window);
	glClearColor(0.12, 0.29, 0.52, 1.0); // cor de fundo
	glEnable(GL_DEPTH_TEST);
	glfwSetKeyCallback(window, key_callback);
    glfwSetWindowSizeCallback(window, redimensiona);
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		desenha();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}
