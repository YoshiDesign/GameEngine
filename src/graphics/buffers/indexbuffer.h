#pragma once
#pragma once

#include <GL/glew.h>

// Similar to buffer.h but uses GL_ELEMENT_ARRAY_BUFFER in order to access indices
namespace sparx { namespace graphics {
	// Generate and bind to OpenGL buffer with our data
	class IndexBuffer
	{
	private:
		GLuint m_BufferID;
		GLuint m_Count;		// Track how many components are being transmitted to the shaders via a vertex attribute pointer

	public:
		IndexBuffer(GLushort* data, GLsizei count);		// Intentionally unsigned short 0 > 65535 (2 bytes) indices

		void bind() const;
		void unbind() const;

		inline GLuint getCount() const { return m_Count; }

	};

} }