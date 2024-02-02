#pragma once
#include <Novice.h>
#include "SceneBase.h"
#include "Player.h"
#include "Enemy.h"
#include "Collision.h"

class SceneGame : public SceneBase{
private:
	int count_;
	Player *player_;
	Enemy *enemy_;
	Collision *collision_;

public:
	// コンストラクタ
	SceneGame();

	// デストラクタ
	~SceneGame();

	void Init()override;
	void Update(char* keys, char* preKeys)override;
	void Draw()override;

	bool GetPlayerIsAlive() { return player_->GetIsAlive(); };
	bool GetEnemyIsAlive() { return enemy_->GetIsAlive(); };
};

