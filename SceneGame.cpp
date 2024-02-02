#include "SceneGame.h"

SceneGame::SceneGame() {
	Init();
}

SceneGame::~SceneGame() {

}

void SceneGame::Init() {
	count_ = 0;
	player_ = new Player();
	enemy_ = new Enemy();
	collision_ = new Collision();
}

void SceneGame::Update(char *keys , char *preKeys) {
	player_->Update(keys , preKeys);
	enemy_->Update(keys , preKeys);

	//B2E
	if (collision_->IsHit(player_->GetPlayerBulletPosX() , player_->GetPlayerBulletPosY() ,
						  enemy_->GetPosX() , enemy_->GetPosY() ,
						  player_->GetPlayerBulletRadius() , enemy_->GetRadius())) {
		enemy_->SetIsAlive(false);
	}

	//P2E
	if (collision_->IsHit(player_->GetPosX() , player_->GetPosY() ,
						  enemy_->GetPosX() , enemy_->GetPosY() ,
						  player_->GetRadius() , enemy_->GetRadius())) {
		player_->SetIsAlive(false);
	}
}

void SceneGame::Draw() {
	player_->Draw();
	enemy_->Draw();

	Novice::ScreenPrintf(
		20 , 20 , "Scene : Game"
	);

	Novice::ScreenPrintf(
		20 , 40 , "Count : %d" , count_
	);
}