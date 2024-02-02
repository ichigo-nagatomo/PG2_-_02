#include "Bullet.h"

Bullet::Bullet() {
	Init();
}

Bullet::~Bullet() {

}

void Bullet::Init() {
	pos_ = {-100.0f, 0.0f};
	velocity_ = {12.0f, 12.0f};
	radius_ = 16.0f;
	color_ = 0xff0000ff;
	isAlive_ = true;

	isShoot_ = false;
}

void Bullet::Update(char *keys , char *preKeys) {
	keys = keys;
	preKeys = preKeys;

	if (isShoot_) {
		pos_.y -= velocity_.y;
		if (pos_.y <= -30.0f) {
			isShoot_ = false;
		}

	} else {
		pos_ = {-100.0f, 0.0f};
	}
}

void Bullet::Draw() {
	if (isShoot_) {
		Novice::DrawEllipse(
			static_cast<int>(pos_.x) , static_cast<int>(pos_.y) ,
			static_cast<int>(radius_) , static_cast<int>(radius_) ,
			0.0f ,
			0xFFFFFFFF ,
			kFillModeSolid
		);
	}
}

void Bullet::SetIsShoot(bool isShoot) {
	isShoot_ = isShoot;
}
