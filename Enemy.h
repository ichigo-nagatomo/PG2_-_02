#pragma once
#include <Novice.h>
#include "Object.h"

class Enemy : public Object{
private:
	int respawnTimer_;

public:
	Enemy();
	~Enemy();

	void Init()override;
	void Update(char *keys , char *preKeys)override;
	void Draw()override;

	bool GetIsAlive()override { return isAlive_; }
	void SetIsAlive(bool isAlive)override { isAlive_ = isAlive; }
};

