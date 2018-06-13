#include "shader.h"

namespace sparx { namespace graphics {
	
	Shader::Shader(const char* vertPath, const char* fragPath)
		: m_VertPath(vertPath), m_FragPath(fragPath)
	{
		m_ShaderID = load();
	}

	Shader::~Shader()
	{
		glDeleteProgram(m_ShaderID);
	}

	GLuint Shader::load()
	{
		GLuint program	= glCreateProgram();
		GLuint vertex	= glCreateShader(GL_VERTEX_SHADER);
		GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);


		std::string vertSourceString = FileUtils::read_file(m_VertPath);
		std::string fragSourceString = FileUtils::read_file(m_FragPath);

		const char *vertSource = vertSourceString.c_str();					// The shader source codes
		const char *fragSource = fragSourceString.c_str();

		glShaderSource(vertex, 1, &vertSource, NULL);						// These functions remove any existing strings from specified buffer (vertex, here)
		glCompileShader(vertex);											// Compile vert

		GLint result;														// ERROR_STATUS

		glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);					// Set result to COMPILE_STATUS
		// Check 1 vectorshader
		if (result == GL_FALSE)
		{
			GLint length;
			glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);

			std::vector<char> error(length);
			glGetShaderInfoLog(vertex, length, &length, &error[0]);
			std::cout << "Failed to compile Vertex Shader" << std::endl << &error[0] << std::endl;

			glDeleteShader(vertex);
			return 0;														// Should always return uint
		}

		glShaderSource(fragment, 1, &fragSource, NULL);						// Compile Frag
		glCompileShader(fragment);
																
		glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);				// Set result to COMPILE_STATUS
		// Check 2 fragment shader
		if (result == GL_FALSE)
		{
			GLint length = 0;
			glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> error(length);
			glGetShaderInfoLog(fragment, length, &length, &error[0]);
			std::cout << "Failed to compile Fragment Shader" << std::endl << &error[0] << std::endl;
			glDeleteShader(fragment);
			glDeleteShader(vertex);
			return 0;
		}

		// Attach shader to our program
		glAttachShader(program, vertex);
		glAttachShader(program, fragment);

		glLinkProgram(program);

		GLint isLinked = 0;
		glGetProgramiv(program, GL_LINK_STATUS, (int*)&isLinked);			// Set result to LINK_STATUS
		// Check 3 Link to program
		if (isLinked == GL_FALSE)
		{
			GLint length = 0;
			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> error(length);
			glGetProgramInfoLog(program, length, &length, &error[0]);
			std::cout << "Failed to link to program: " << &error[0] << std::endl;
			
			glDeleteShader(fragment);
			glDeleteShader(vertex);
			return 0;

		}
		// Successful compile & link
		glValidateProgram(program);					

		glDetachShader(program, vertex);			// This does not delete the shaders we just compiled. Rather, it removes them from program object store.
		glDetachShader(program, fragment);

		return program;
	}
	// Slight abstract of otherwise OpenGL functions
	GLint Shader::getUniformLocation(const GLchar* name)	
	{
		return glGetUniformLocation(m_ShaderID, name);
	}

	void Shader::setUniform1f(const GLchar* name, float value)
	{
		glUniform1f(getUniformLocation(name), value);
	}
	void Shader::setUniform1i(const GLchar* name, int value)
	{
		glUniform1i(getUniformLocation(name), value);
	}
	void Shader::setUniform2f(const GLchar* name, const maths::vec2& vector)
	{
		glUniform2f(getUniformLocation(name), vector.x, vector.y);
	}
	void Shader::setUniform3f(const GLchar* name, const maths::vec3& vector)
	{
		glUniform3f(getUniformLocation(name), vector.x, vector.y, vector.z);
	}
	void Shader::setUniform4f(const GLchar* name, const maths::vec4& vector)
	{
		glUniform4f(getUniformLocation(name), vector.x, vector.y, vector.z, vector.w);
	}
	void Shader::setUniformMat4(const GLchar* name, const maths::mat4& matrix)
	{
		glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, matrix.elements);
	}

	void Shader::enable() const
	{
		glUseProgram(m_ShaderID);
	}

	void Shader::disable() const
	{
		glUseProgram(0);
	}

}}