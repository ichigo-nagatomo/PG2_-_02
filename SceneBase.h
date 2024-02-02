#pragma once

class SceneBase {
private:
	

public:
	// コンストラクタ
	SceneBase() {}

	// 仮想デストラクタ
	virtual ~SceneBase() {}

	// 純粋仮想関数
	virtual void Init() = 0;
	virtual void Update(char* keys, char* preKeys) = 0;
	virtual void Draw() = 0;
};
