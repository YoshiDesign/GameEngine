#include "src/graphics/window.h"

//void cursor_pos_callback()
//{
//	std::cout << ""
//}

int main()
{
	using namespace sparx;
	using namespace graphics;

	Window window("Sparx!", 960, 540);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	while (!window.closed())
	{

		window.clear();
		double x, y;
		window.getMousePosition(x, y);
		std::cout << x << ", " << y << std::endl;


		if (window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
		{
			std::cout << "PRESSED" << std::endl;
		}
#if 1
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f( 0.0f,  0.5f);
		glVertex2f( 0.5f, -0.5f);
		glEnd();
#else
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
#endif

		window.update();
	}

	return 0;
}