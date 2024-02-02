#pragma once
#include <Novice.h>
#include "Object.h"

class Bullet : public Object{
private:
	bool isShoot_;

public:
	Bullet();
	~Bullet();

	void Init()override;
	void Update(char *keys , char *preKeys)override;
	void Draw()override;

	bool GetIsShoot() { return isShoot_; };
	void SetIsShoot(bool isShoot);
};

