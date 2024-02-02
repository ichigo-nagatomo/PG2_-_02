#pragma once
#include <Novice.h>
#include "SceneBase.h"

class SceneTitle : public SceneBase{
private:
	int titleGh_;
	int count_;

public:
	// コンストラクタ
	SceneTitle();

	// デストラクタ
	~SceneTitle();

	void Init()override;
	void Update(char* keys, char* preKeys)override;
	void Draw()override;
};

