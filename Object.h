#pragma once
#include <Novice.h>
#include <Vector2.h>
class Object {
protected:
	Vector2 pos_;
	Vector2 velocity_;
	float radius_;
	unsigned int color_;
	bool isAlive_;

public:
	virtual void Init() = 0;
	virtual void Update(char *keys , char *preKeys) = 0;
	virtual void Draw() = 0;

	float GetPosX() { return pos_.x; }
	float GetPosY() { return pos_.y; }
	void SetPos(Vector2 pos);

	float GetVelocityX() { return velocity_.x; }
	float GetVelocityY() { return velocity_.y; }
	void SetVelocity(Vector2 velocity);

	float GetRadius() { return radius_; }
	
	void SetColor(unsigned int color);
	
	virtual bool GetIsAlive() { return isAlive_; }
	virtual void SetIsAlive(bool isAlive);
};

