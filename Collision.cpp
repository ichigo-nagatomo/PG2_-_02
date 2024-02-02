#include "Collision.h"

Collision::Collision() {
	Init();
}

void Collision::Init() {
	
}

bool Collision::IsHit(float posX, float posY, float posX2, float posY2, float radius, float radius2) {
	if (Length(posX - posX2 , posY - posY2) <= radius + radius2) {
		return true;
	}
	return false;
}
