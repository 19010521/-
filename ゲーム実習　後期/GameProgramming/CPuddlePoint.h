#ifndef CPUDDLEPOINT_H
#define CPUDDLEPOINT_H
#include "CCollider.h"
#include"CCharacter.h"
/*
�G�@�Ȃǂ̖ڕW
*/
class CPuddlePoint :public CCharacter{
private:
	CCollider mCollider;
	CCollider mCollider2;



public:

	CPuddlePoint();
	//�ݒ�
	//Set(�ʒu�A���a)
	void Set(const CVector &pos, float r);

	

};
#endif