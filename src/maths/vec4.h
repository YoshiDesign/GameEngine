#pragma once
#include <iostream>

// + and << are overloaded in vec4

namespace sparx { namespace maths {

	struct vec4		// Case matches GLSL convention. Use of friend is arbitrary reassurance
	{
		float x, y, z, w;

		vec4() = default;	// Irrelevant to >= C++17. Fixes Union Error
		vec4(const float& x, const float& y, const float& z, const float& w);
		
		// These return a reference to current vec4 object lol?
		vec4& add(const vec4& other);
		vec4& subtract(const vec4& other);
		vec4& multiply(const vec4& other);
		vec4& divide(const vec4& other);

		// reading from right, hence ref // THIS IS WHERE WE WERE ACCIDENTALLY READING LOCAL REFS
		friend vec4 operator+(vec4 left, const vec4& right);
		friend vec4 operator-(vec4 left, const vec4& right);
		friend vec4 operator*(vec4 left, const vec4& right);
		friend vec4 operator/(vec4 left, const vec4& right);

		// override comparison
		bool operator==(const vec4& other);
		bool operator!=(const vec4& other);

		// Const because we are not changing b, when we do a+=b
		// Not friend
		vec4& operator+=(const vec4& other);
		vec4& operator-=(const vec4& other);
		vec4& operator*=(const vec4& other);
		vec4& operator/=(const vec4& other);

		friend std::ostream& operator<<(std::ostream& stream, const vec4& vector);
	};


	// Lets make an output string operator



} }