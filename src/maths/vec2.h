#pragma once
#include <iostream>

// + and << are overloaded in vec2

namespace sparx {
	namespace maths {

		struct vec2		// Using a struct because everything will be public from here. Name Matching GLSL convention
		{
			float x, y;

			vec2();
			vec2(const float& x, const float& y);

			// These return a reference to current vec2 object lol?
			vec2& add(const vec2& other);
			vec2& subtract(const vec2& other);
			vec2& multiply(const vec2& other);
			vec2& divide(const vec2& other);

			// reading from right, hence ref
			friend vec2 operator+(vec2 left, const vec2& right);
			friend vec2 operator-(vec2 left, const vec2& right);
			friend vec2 operator*(vec2 left, const vec2& right);
			friend vec2 operator/(vec2 left, const vec2& right);

			// override comparison
			
			bool operator!=(const vec2& other);
			bool operator==(const vec2& other);

			// Const because we are not changing b, when we do a+=b
			// Not friend
			vec2& operator+=(const vec2& other);
			vec2& operator-=(const vec2& other);
			vec2& operator*=(const vec2& other);
			vec2& operator/=(const vec2& other);

			friend std::ostream& operator<<(std::ostream& stream, const vec2& vector);
		};


		// Lets make an output string operator



	}
}