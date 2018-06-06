#include "src/graphics/window.h"
#include "src/maths/maths.h"

int main()
{
	using namespace sparx;
	using namespace graphics;
	using namespace maths;

	Window window("Sparx!", 960, 540);
	glClearColor(0.2f, 0.2f, 0.1f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	mat4 position = mat4::translation(vec3(2, 3, 4));
	position *= mat4::identity();

	position.elements[12] = 2.0f;

	

	std::cout << &position.elements[12] << std::endl;
	std::cout << &position.columns[3].x << std::endl;


	while (!window.closed())
	{
		window.clear();

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