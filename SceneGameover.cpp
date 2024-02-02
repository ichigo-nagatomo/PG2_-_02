#include "SceneGameover.h"
SceneGameover::SceneGameover() {
	Init();
}

SceneGameover::~SceneGameover() {

}

void SceneGameover::Init() {
	gameoverGh_ = Novice::LoadTexture("white1x1.png");
	count_ = 0;
}

void SceneGameover::Update(char *keys , char *preKeys) {
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		count_ += 1;
	}
}

void SceneGameover::Draw() {
	Novice::ScreenPrintf(
		20 , 20 , "Scene : Gameover"
	);

	Novice::ScreenPrintf(
		20 , 40 , "Count : %d" , count_
	);
}