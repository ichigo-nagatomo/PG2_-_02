#include "Object.h"

void Object::SetPos(Vector2 pos){
	pos_ = pos;
}

void Object::SetVelocity(Vector2 velocity){
	velocity_ = velocity;
}

void Object::SetColor(unsigned int color){
	color_ = color;
}

void Object::SetIsAlive(bool isAlive){
	isAlive_ = isAlive;
}

