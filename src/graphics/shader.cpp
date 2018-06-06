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

		const char *vertSource = vertSourceString.c_str();	// Boiler-plating
		const char *fragSource = fragSourceString.c_str();

		glShaderSource(vertex, 1, &vertSource, NULL);			// Designate shader to be compiled
		glCompileShader(vertex);

		GLint result;											// Get the vertex error log

		glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE)
		{
			GLint length;
			glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> error(length);
			glGetShaderInfoLog(vertex, length, &length, &error[0]);
			std::cout << "Failed to compile Vertex Shader" << std::endl << &error[0] << std::endl;
			glDeleteShader(vertex);
			return 0;											// Uint...
		}

		glShaderSource(fragment, 1, &fragSource, NULL);			// Designate shader to be compiled
		glCompileShader(fragment);
																
		glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);	// Get fragment the log
		if (result == GL_FALSE)
		{
			GLint length;
			glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> error(length);
			glGetShaderInfoLog(fragment, length, &length, &error[0]);
			std::cout << "Failed to compile Fragment Shader" << std::endl << &error[0] << std::endl;
			glDeleteShader(fragment);
			return 0;											// Uint!
		}

		// Attach hader to our program
		glAttachShader(program, vertex);			// Initialize them
		glAttachShader(program, fragment);

		glLinkProgram(program);						// link them
		glValidateProgram(program);					// validate them

		glDeleteShader(vertex);
		glDeleteShader(fragment);

		return program;
	}

	GLint Shader::getUniformLocation(const GLchar* name)	// Abstract of otherwise OpenGL function
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