#pragma once
#include <vector>
#include <GL/glew.h>

#include "buffer.h"

// Note that this entire class is not necessary for the operation of OpenGL Buffers.
// This adds dynamism in the event we would like to alter memory mapping of our types

namespace sparx { namespace graphics {
		/*
			See vertex attribute pointers. Each are bound to a certain vertex array.
			We only want to modify vertex attribute ptrs for OUR array, not everyones array i.e. we (typically) dont need lighting positions for text.
			If we dont use vertex arrays to enclose our buffer arrays, we will have homogenous behavior. Lame.
			A vertex array is an array of buffers.
		 */

	// When a vertex array is given a buffer array (by reference!), it is responsible for managing it in memory.
	// Therefore the same buffer cannot exist in numerous arrays (per this implementation)
	class VertexArray
	{
	private:
		GLuint m_ArrayID;
		std::vector<Buffer*> m_Buffers;

	public:
		VertexArray();
		~VertexArray();

		void addBuffer(Buffer* buffer, GLuint index);		// ( 1. buffer to be added, 2. which vertex attribute ptr to use )

		void bind() const;
		void unbind() const;

	};



} }