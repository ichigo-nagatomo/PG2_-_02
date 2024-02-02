#pragma once
#include <Novice.h>
#include "SceneBase.h"

class SceneGameover : public SceneBase{
private:
	int gameoverGh_;
	int count_;

public:
	// コンストラクタ
	SceneGameover();

	// デストラクタ
	~SceneGameover();

	void Init()override;
	void Update(char* keys, char* preKeys)override;
	void Draw()override;
};
