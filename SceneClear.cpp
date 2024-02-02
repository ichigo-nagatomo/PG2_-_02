#include "SceneClear.h"
SceneClear::SceneClear() {
	Init();
}

SceneClear::~SceneClear() {

}

void SceneClear::Init() {
	clearGh_ = Novice::LoadTexture("white1x1.png");
	count_ = 0;
}

void SceneClear::Update(char *keys , char *preKeys) {
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		count_ += 1;
	}
}

void SceneClear::Draw() {
	Novice::ScreenPrintf(
		20 , 20 , "Scene : Clear"
	);

	Novice::ScreenPrintf(
		20 , 40 , "Count : %d" , count_
	);
}