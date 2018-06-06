#pragma once

#include "vec3.h"
#include "vec4.h"
#include "extra_maths.h"


namespace sparx { namespace maths {
	
	// Struct = explicitly public
	struct mat4
	{
		union
		{
			// 2 ways to acquire mat4 memory locale
			float elements[4 * 4];
			vec4 columns[4];
		};

		mat4();
		mat4(float diagonal);

		vec4 getColumn(int index)
		{
			index *= 4;
			return vec4(elements[index], elements[index + 1], elements[index + 2], elements[index + 3]);
		}

		static mat4 identity();
		mat4& multiply(const mat4& other); // Multiplies the current matrix by arg. Returns the current matrix. No copies

		friend mat4 operator*(mat4 left, const mat4& right);
		mat4& operator*=(const mat4& other);

		// The clipping planes
		static mat4 orthographic(float left, float right, float bottom, float top, float near, float far);
		static mat4 perspective(float fov, float aspectRatio, float near, float far);

		static mat4 translation(const vec3& translation);
		static mat4 rotation(float angle, const vec3& axis);
		static mat4 scale(const vec3& scale);

	};

} } 
