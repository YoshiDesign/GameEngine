#include "src/graphics/window.h"
#include "src/maths/maths.h"

int main()
{
	using namespace sparx;
	using namespace graphics;
	using namespace maths;

	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);
	Window window("Sparx!", 960, 540);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	vec2 e(1.0f, 2.0f);
	vec2 f(1.5f, 2.0f);
	e *= f;
	
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