#ifndef CITEM_H
#define CITEM_H

#include"CCharacter.h"
#include"CCollider.h"

class CItem :public CCharacter{
private:

	CCollider mCollider;
	CCollider mCollider2;

	void Update();
	//衝突処理
	void Collision(CCollider*m, CCollider*y);

	bool Recoveryflag;//回収

public:
	
	
	//コンストラクタ
	CItem();

	
};
#endif