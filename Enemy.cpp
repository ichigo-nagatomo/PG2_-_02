#include "Enemy.h"

Enemy::Enemy() {
	Init();
}

Enemy::~Enemy() {

}

void Enemy::Init() {
	pos_ = {640.0f, 200.0f};
	velocity_ = {8.0f, 8.0f};
	radius_ = 24.0f;
	color_ = 0xff0000ff;
	isAlive_ = true;

	respawnTimer_ = 60;
}

void Enemy::Update(char *keys , char *preKeys) {
	keys = keys;
	preKeys = preKeys;
	if (isAlive_) {
		pos_.x += velocity_.x;
		if (pos_.x >= 1280.0f - radius_ || pos_.x <= 0 + radius_) {
			velocity_.x *= -1;
		}

	} else if (!isAlive_) {
		respawnTimer_--;
		if (respawnTimer_ <= 0) {
			respawnTimer_ = 60;
			isAlive_ = true;
		}
	}
}

void Enemy::Draw() {
	if (isAlive_) {
		Novice::DrawEllipse(
			static_cast<int>(pos_.x) , static_cast<int>(pos_.y) ,
			static_cast<int>(radius_) , static_cast<int>(radius_) ,
			0.0f ,
			color_ ,
			kFillModeSolid
		);
	}
}
