#include "vec3.h"


namespace sparx { namespace maths {

	// empty constructor
	vec3::vec3()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	vec3::vec3(const float& x, const float& y, const float& z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	vec3& vec3::add(const vec3& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}

	vec3& vec3::subtract(const vec3& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}

	vec3& vec3::multiply(const vec3& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		return *this;
	}

	vec3& vec3::divide(const vec3& other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;
		return *this;
	}

	vec3 operator+(vec3 left, const vec3& right)
	{
		// left + right
		return left.add(right);
	}
	vec3 operator-(vec3 left, const vec3& right)
	{
		// left + right
		return left.subtract(right);
	}
	vec3 operator*(vec3 left, const vec3& right)
	{
		// left + right
		return left.multiply(right);
	}
	vec3 operator/(vec3 left, const vec3& right)
	{
		// left + right
		return left.divide(right);
	}

	// Comparison overloads
	bool vec3::operator==(const vec3& other)
	{
		return x == other.x && y == other.y && z == other.z;
	}
	bool vec3::operator!=(const vec3& other) 
	{
		return !(*this == other);			// Using what we have already oveloaded. No need to write x != other.x || y != other.y
	}

	vec3& vec3::operator+=(const vec3& other)
	{
		// since add already returns "this", we can use 1 simple line
		return add(other);
	}
	vec3& vec3::operator-=(const vec3& other)
	{
		return subtract(other);
	}
	vec3& vec3::operator*=(const vec3& other)
	{
		return multiply(other);
	}
	vec3& vec3::operator/=(const vec3& other)
	{
		return divide(other);
	}

	// Acquired << for overloading from std::
	std::ostream& operator<<(std::ostream& stream, const vec3& vector)
	{
		stream << "vec3: (" << vector.x << ", " << vector.y << ", " << vector.z << ")";
		return stream;
	}

} }