#pragma once
#include <iostream>

// + and << are overloaded in vec3

namespace sparx { namespace maths {

	struct vec3		// Using a struct because everything will be public from here. Name Matching GLSL convention
	{
		float x, y, z; // The mightiest co'ords

		vec3();
		vec3(const float& x, const float& y, const float& z);
		
		// These return a reference to current vec3 object
		vec3& add(const vec3& other);
		vec3& subtract(const vec3& other);
		vec3& multiply(const vec3& other);
		vec3& divide(const vec3& other);

		// reading from right, hence ref
		friend vec3 operator+(vec3 left, const vec3& right);
		friend vec3 operator-(vec3 left, const vec3& right);
		friend vec3 operator*(vec3 left, const vec3& right);
		friend vec3 operator/(vec3 left, const vec3& right);

		// override comparison
		bool operator==(const vec3& other);
		bool operator!=(const vec3& other);

		// Const because we are not changing b, when we do a+=b
		// Not friend
		vec3& operator+=(const vec3& other);
		vec3& operator-=(const vec3& other);
		vec3& operator*=(const vec3& other);
		vec3& operator/=(const vec3& other);

		friend std::ostream& operator<<(std::ostream& stream, const vec3& vector);
	};


	// Lets make an output string operator



} }