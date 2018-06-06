#pragma once

#include <iostream>
#include <vector>
#include <GL/glew.h>

#include "../utils/fileutils.h"

// Load shader, transfer data to shader, unload shader, enable / disable shader, uniform locations 

namespace sparx { namespace graphics {

		class Shader
		{
		private:
			GLuint m_ShaderID;
			const char *m_VertPath, *m_FragPath;					// helpful for debug
		public:
			Shader(const char* fragPath, const char* vertPath ); // path to vertex shader and fragment shader
			~Shader();

			void enable() const;
			void disable() const;
		private:
			GLuint load();
		};
} }