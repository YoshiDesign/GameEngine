#pragma once

#include <iostream>
#include <vector>
#include <GL/glew.h>

#include "../maths/maths.h"
#include "../utils/fileutils.h"

// Load shader, transfer data to shader, unload shader, enable / disable shader, uniform locations 

namespace sparx { namespace graphics {

		class Shader
		{
		private:
			GLuint m_ShaderID;
			const char *m_VertPath, *m_FragPath;					// helpful for debug
			
		public:
			Shader(const char* vertPath, const char* fragPath); // path to vertex shader and fragment shader
			~Shader();

			

			void setUniform1f(const GLchar* name, float value);
			void setUniform1i(const GLchar* name, int value);
			void setUniform2f(const GLchar* name, const maths::vec2& vector);
			void setUniform3f(const GLchar* name, const maths::vec3& vector);
			void setUniform4f(const GLchar* name, const maths::vec4& vector);
			void setUniformMat4(const GLchar* name, const maths::mat4& matrix);

			void enable() const;
			void disable() const;
		private:
			GLuint load();
			GLint getUniformLocation(const GLchar* name);		// Needed for all of the enumerated uniforms // OpenGL has one of these, this is our definition
		};
} }