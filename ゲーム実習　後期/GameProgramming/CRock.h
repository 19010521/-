#ifndef CROCK_H
#define CROCK_H
#include"CCharacter.h"
#include"CCollider.h"

class CRock :public CCharacter{
public:
	static CRock *mpRock;
	CRock(CModel*model, CVector position, CVector rotation, CVector scale);
	CCollider mColBody;
	CCollider mColBody2;
	
	void Collision(CCollider*m, CCollider*y);
	

};
#endif