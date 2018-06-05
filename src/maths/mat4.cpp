#include "mat4.h"

namespace sparx { namespace maths {

	mat4::mat4()
	{	// memset 0
		for (int i = 0; i < 4 * 4; i++)
			elements[i] = 0.0f;
	}

	mat4::mat4(float diagonal)
	{

		for (int i = 0; i < 4 * 4; i++)
			elements[i] = 0.0f;
		elements[0 + 0 * 4] = diagonal;
		elements[1 + 1 * 4] = diagonal;
		elements[2 + 2 * 4] = diagonal;
		elements[3 + 3 * 4] = diagonal;
	}

	mat4 mat4::identity()
	{
		return mat4(1.0f);
	}

	mat4& mat4::multiply(const mat4& other)	// Multiply 2 matrices together. Modifies the current matrix
	{
		mat4 result;
		// Rows
		for (int y = 0; y < 4; y++)
		{
			// Columns
			for (int x = 0; x < 4; x++)
			{
				float sum = 0.0f;
				// Elements
				for (int e = 0; e < 4; e++)
				{
					sum += elements[x + e * 4] * other.elements[e + y * 4];
				}
				elements[x + y * 4] = sum;
			}
		}
	}

	mat4 operator*(mat4 left, const mat4& right)
	{
		return left.multiply(right);
	}
	mat4& mat4::operator*=(const mat4& other)
	{
		return multiply(other);
	}

	mat4 mat4::orthographic(float left, float right, float bottom, float top, float near, float far) // statatatatic
	{
		mat4 result(1.0f);	// Construct a matrix, result

		// Diagonal
		result.elements[0 + 0 * 4] = 2.0f / (right - left);
		result.elements[1 + 1 * 4] = 2.0f / (top - bottom);
		result.elements[2 + 2 * 4] = 2.0f / (near - far);

		result.elements[0 + 3 * 4] = 2.0f / (left + right) / (left - right);
		result.elements[1 + 3 * 4] = 2.0f / (bottom + top) / (bottom - top);
		result.elements[2 + 3 * 4] = 2.0f / (far + near) / (far - near);

		return result;
	}
	mat4 mat4::perspective(float fov, float aspectRatio, float near, float far) // statatatatic
	{
		mat4 result(1.0f);

		float q = 1.0f / (float)tan(toRadians(0.5f * fov));
		float a = q / aspectRatio;

		float b = (near + far) / (near - far);
		float c = (2.0f * near * far) / (near - far);

		result.elements[0 + 0 * 4] = a;
		result.elements[1 + 1 * 4] = q;
		result.elements[2 + 2 * 4] = b;
		result.elements[3 + 2 * 4] = -1.0f;
		result.elements[2 + 3 * 4] = c;

		return c;
	}
	mat4 mat4::translation(const vec3& translation)
	{
		mat4 result(1.0f);

		result.elements[0 + 3 * 4] = translation.x;
		result.elements[1 + 3 * 4] = translation.y;
		result.elements[2 + 3 * 4] = translation.z;

		return result;
	}

	mat4 mat4::scale(const vec3& scale)
	{
		// quite similar to translation in a way or 2

		mat4 result(1.0f);

		result.elements[0 + 3 * 4] = scale.x;
		result.elements[1 + 3 * 4] = scale.y;
		result.elements[2 + 3 * 4] = scale.z;

		return result;

	}

} }