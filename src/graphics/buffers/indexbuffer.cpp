#include "indexbuffer.h"

namespace sparx { namespace graphics {
	
	IndexBuffer::IndexBuffer(GLushort* data, GLsizei count)
		: m_Count(count)
	{
		
		glGenBuffers(1, &m_BufferID);		// Buffer object names are u_ints, 0 is reserved and unbinds any previously bound objects
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferID);												// Just an array
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLushort), data, GL_STATIC_DRAW);			// Size in bytes. Last arg = usage
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);														// Unbind everything

	}

	void IndexBuffer::bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferID);
	}


	void IndexBuffer::unbind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

} }