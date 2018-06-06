#include "src/graphics/window.h"
#include "src/graphics/shader.h"
#include "src/maths/maths.h"
#include "src/utils/fileutils.h"

int main()
{
	using namespace sparx;
	using namespace graphics;
	using namespace maths;

	Window window("Sparx!", 960, 540);
	glClearColor(0.0f, 1.0f, 0.1f, 1.0f);

	GLfloat vertices[] =
	{
		-0.5f, -0.5f,  0.0f, 
		-0.5f,  0.5f,  0.0f,
		 0.5f,  0.5f,  0.0f,
		 0.5f,  0.5f,  0.0f,
		 0.5f, -0.5f,  0.0f,
		-0.5f, -0.5f,  0.0f
	};

	GLuint vao, vbo;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);	// False = normalized // 3 because there are 3 components to each vertex (above vertices)
	glEnableVertexAttribArray(0);
	
	Shader shader("src/shaders/basic.frag", "src/shaders/basic.vert");
	shader.enable();

	while (!window.closed())
	{
		window.clear();

		glDrawArrays(GL_TRIANGLES, 0, 6);

		window.update();
	}

	return 0;
}