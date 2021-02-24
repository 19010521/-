#ifndef CITEM_H
#define CITEM_H

#include"CCharacter.h"
#include"CCollider.h"

class CItem :public CCharacter{
public:
	
	CCollider mCollider;
	CCollider mCollider2;
	//コンストラクタ
	CItem();

	void Update();
	//衝突処理
	void Collision(CCollider*m, CCollider*y);

	bool Recoveryflag;//回収

};
#endif