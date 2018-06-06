#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

namespace sparx { namespace maths {

	// source of err:C4244
	inline float toRadians(float degrees)
	{
		return degrees * (M_PI / 180.0f);
	}

} }