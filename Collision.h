#pragma once
#define _USE_MATH_DEFINES
#include <math.h>

class Collision {
private:

public:
	Collision();

	void Init();
	bool IsHit(float posX, float posY, float posX2, float posY2, float radius, float radius2);
	float Length(float x, float y) {
		return sqrtf(x * x + y * y);
	}
};

