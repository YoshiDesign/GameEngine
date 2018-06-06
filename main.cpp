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
	/*glClearColor(1.0f, 1.0f, 1.0f, 1.0f);*/

	GLfloat vertices[] =
	{
		0,0,0,
		8,0,0,
		0,3,0,
		0,3,0,
		8,3,0,
		8,0,0,	
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);	// False = normalized // 3 because there are 3 components to each vertex (above vertices)
	glEnableVertexAttribArray(0);
	
	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);	// L R B T N F

	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);
	shader.setUniformMat4("ml_matrix", mat4::translation(vec3(4,3,0)));

	shader.setUniform2f("light_pos", vec2(4.0f, 1.5f));
	shader.setUniform4f("color_u", vec4(0.2f, 0.3f, 0.8f, 1.0f));

	
	while (!window.closed())
	{
		window.clear();
		double x, y;
		window.getMousePosition(x, y);
		shader.setUniform2f("light_pos", vec2((float)(x * 18.0f / 1600.0f), (float)(9.0f - y * 25.0f / 1200.0f)));
		glDrawArrays(GL_TRIANGLES, 0, 6);
		window.update();
	}

	return 0;
}