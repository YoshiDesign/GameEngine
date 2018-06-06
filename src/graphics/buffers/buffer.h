#pragma once

#include <GL/glew.h>

namespace sparx { namespace graphics {
	// Add a bunch of data to a buffer, and generate an OpenGL buffer
	class Buffer
	{
	private:
		GLuint m_BufferID;
		GLuint m_ComponentCount;		// Track how many components are being transmitted to the shaders via a vertex attribute pointer

	public:
		Buffer(GLfloat* data, GLsizei count, GLuint componentCount);

		void bind() const;
		void unbind() const;

		inline GLuint getComponentCount() const { return m_ComponentCount; }

	};



} }