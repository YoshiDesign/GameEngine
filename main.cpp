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
		0, 0, 10,
		15, 0, 0,
		0, 15, 0		
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);	// False = normalized // 3 because there are 3 components to each vertex (above vertices)
	glEnableVertexAttribArray(0);
	
	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.enable();
	glUniformMatrix4fv(glGetUniformLocation(shader.m_ShaderID, "pr_matrix"), 1, GL_FALSE, ortho.elements);

	while (!window.closed())
	{
		window.clear();

		glDrawArrays(GL_TRIANGLES, 0, 6);

		window.update();
	}

	return 0;
}