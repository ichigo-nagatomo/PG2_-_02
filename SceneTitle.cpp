#include "SceneTitle.h"

SceneTitle::SceneTitle() {
	Init();
}

SceneTitle::~SceneTitle() {

}

void SceneTitle::Init() {
	titleGh_ = Novice::LoadTexture("white1x1.png");
	count_ = 0;
}

void SceneTitle::Update(char *keys , char *preKeys) {
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		count_ += 1;
	}
}

void SceneTitle::Draw() {
	Novice::ScreenPrintf(
		20 , 20 , "Scene : Title"
	);

	Novice::ScreenPrintf(
		20 , 40 , "Count : %d" , count_
	);
}
