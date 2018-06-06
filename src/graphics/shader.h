#pragma once

#include <iostream>
#include <vector>
#include <GL/glew.h>

#include "../utils/fileutils.h"

// Load shader, transfer data to shader, unload shader, enable / disable shader, uniform locations 

namespace sparx { namespace graphics {

		class Shader
		{
		public:
			GLuint m_ShaderID;
			const char *m_VertPath, *m_FragPath;					// helpful for debug
		public:
			Shader(const char* vertPath, const char* fragPath); // path to vertex shader and fragment shader
			~Shader();

			void enable() const;
			void disable() const;
		private:
			GLuint load();
		};
} }