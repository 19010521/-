#ifndef CITEM_H
#define CITEM_H

#include"CCharacter.h"
#include"CCollider.h"

class CItem :public CCharacter{
private:

	CCollider mCollider;
	CCollider mCollider2;

	void Update();
	//�Փˏ���
	void Collision(CCollider*m, CCollider*y);

	bool Recoveryflag;//���

public:
	
	
	//�R���X�g���N�^
	CItem();

	
};
#endif