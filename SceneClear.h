#pragma once
#include <Novice.h>
#include "SceneBase.h"

class SceneClear : public SceneBase{
private:
	int clearGh_;
	int count_;

public:
	// コンストラクタ
	SceneClear();

	// デストラクタ
	~SceneClear();

	void Init()override;
	void Update(char* keys, char* preKeys)override;
	void Draw()override;
};

