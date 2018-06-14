#include "vertexarray.h"

/*
	SEE : glBindVertexArray
	What is a vertex array?
	What are our array attributes attributed to?
*/


namespace sparx { namespace graphics {

	VertexArray::VertexArray()
	{
		glGenVertexArrays(1, &m_ArrayID);
	}

	VertexArray::~VertexArray()
	{
		for (int i = 0; i < m_Buffers.size(); i++)
			delete m_Buffers[i];
	}

	void VertexArray::addBuffer(Buffer *buffer, GLuint index)			// index corresponds w/ shader "layout (location = 0) ... // We need to get this buffer to point to that same location in our shader
	{
		bind();
		buffer->bind();													// being bound to shader index
		glEnableVertexAttribArray(index);
		glVertexAttribPointer(index, buffer->getComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);	// corresponds to the shader's location attribute index. 2nd param is the size in terms of components. contains stride & offset (last 2 args)

		buffer->unbind();
		unbind();
	}

	void VertexArray::bind() const
	{
		glBindVertexArray(m_ArrayID);
	}

	void VertexArray::unbind() const
	{
		glBindVertexArray(0);
	}


} }