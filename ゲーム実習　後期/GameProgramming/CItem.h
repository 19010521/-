#ifndef CITEM_H
#define CITEM_H

#include"CCharacter.h"
#include"CCollider.h"

class CItem :public CCharacter{
public:
	
	CCollider mCollider;
	CCollider mCollider2;
	//�R���X�g���N�^
	CItem();

	void Update();
	//�Փˏ���
	void Collision(CCollider*m, CCollider*y);

	bool Recoveryflag;//���

};
#endif