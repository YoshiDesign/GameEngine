#include "vec2.h"


namespace sparx { namespace maths {

		// empty constructor
		vec2::vec2()
		{
			x = 0.0f;
			y = 0.0f;
		}

		vec2::vec2(const float& x, const float& y)
		{
			this->x = x;
			this->y = y;
		}

		vec2& vec2::add(const vec2& other)		// keep it const, dont create copy, this is safe and efficient. 
		{
			x += other.x;
			y += other.y;
			return *this;						// *this will be our left hand operand
		}

		vec2& vec2::subtract(const vec2& other)
		{
			x -= other.x;
			y -= other.y;
			return *this;
		}

		vec2& vec2::multiply(const vec2& other)
		{
			x *= other.x;
			y *= other.y;
			return *this;
		}

		vec2& vec2::divide(const vec2& other)
		{
			x /= other.x;
			y /= other.y;
			return *this;
		}

		vec2 operator+(vec2 left, const vec2& right)
		{
			return left.add(right);
		}
		vec2 operator-(vec2 left, const vec2& right)
		{
			return left.subtract(right);
		}
		vec2 operator*(vec2 left, const vec2& right)
		{
			return left.multiply(right);
		}
		vec2 operator/(vec2 left, const vec2& right)
		{
			return left.divide(right);
		}

		// Comparison overloads
		bool vec2::operator!=(const vec2& other)
		{
			return  x != other.x || y != other.y;			// Using what we have already oveloaded.
		}

		bool vec2::operator==(const vec2& other)
		{
			return !(*this != other);						// I hope this is safe
		}
		
		// Note that the other overloaded operators dont return references; hence a simple return statement
		vec2& vec2::operator+=(const vec2& other)
		{
			return add(other);							// 'this' must follow the functiond up the callstack
		}
			
		vec2& vec2::operator-=(const vec2& other)
		{
			return subtract(other);
		}
		vec2& vec2::operator*=(const vec2& other)
		{
			return multiply(other);
		}
		vec2& vec2::operator/=(const vec2& other)
		{
			return divide(other);
		}


		std::ostream& operator<<(std::ostream& stream, const vec2& vector)
		{
			stream << "vec2: (" << vector.x << ", " << vector.y << ")";
			return stream;
		}

} }