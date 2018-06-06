#pragma once
#pragma once

#include <GL/glew.h>

namespace sparx { namespace graphics {
		// Add a bunch of data to a buffer, and generate an OpenGL buffer
	class IndexBuffer
	{
	private:
		GLuint m_BufferID;
		GLuint m_Count;		// Track how many components are being transmitted to the shaders via a vertex attribute pointer

	public:
		IndexBuffer(GLushort* data, GLsizei count);		// Intentionally unsigned short 0 > 65535 (2 bytes) indices

		void bind() const;
		void unbind() const;

		GLuint getCount() const { return m_Count; }

	};



} }