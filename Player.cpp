#include "Player.h"

Player::Player() {
	Init();
}

Player::~Player() {

}

void Player::Init() {
	pos_ = {640.0f, 500.0f};
	velocity_ = {8.0f, 8.0f};
	radius_ = 24.0f;
	color_ = 0xffffffff;
	isAlive_ = true;

	bullet_ = new Bullet();
}

void Player::Update(char *keys , char *preKeys) {
	if (keys[DIK_D]) {
		pos_.x += velocity_.x;
	}

	if (keys[DIK_A]) {
		pos_.x -= velocity_.x;
	}

	if (keys[DIK_W]) {
		pos_.y -= velocity_.y;
	}

	if (keys[DIK_S]) {
		pos_.y += velocity_.y;
	}

	bullet_->Update(keys, preKeys);
	if (bullet_->GetIsShoot()) {

	} else {
		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
			bullet_->SetIsShoot(true);
			bullet_->SetPos(pos_);
		}
	}
}

void Player::Draw() {
	bullet_->Draw();

	if (isAlive_) {
		Novice::DrawEllipse(
			static_cast<int>(pos_.x) , static_cast<int>(pos_.y) ,
			static_cast<int>(radius_) , static_cast<int>(radius_) ,
			0.0f ,
			0xFFFFFFFF ,
			kFillModeSolid
		);
	}
}
