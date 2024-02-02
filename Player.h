#pragma once
#include <Novice.h>
#include "Object.h"
#include "Bullet.h"

class Player : public Object{
private:
	bool isShoot_;
	
public:
	Bullet *bullet_;

	Player();
	~Player();

	void Init()override;
	void Update(char *keys , char *preKeys)override;
	void Draw()override;

	float GetPlayerBulletPosX() { return bullet_->GetPosX(); };
	float GetPlayerBulletPosY() { return bullet_->GetPosY(); };
	float GetPlayerBulletRadius() { return bullet_->GetRadius(); };
};

