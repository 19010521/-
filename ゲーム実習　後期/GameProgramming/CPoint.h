#ifndef CPOINT_H
#define CPOINT_H
#include "CCollider.h"
#include"CCharacter.h"
/*
�G�@�Ȃǂ̖ڕW
*/
class CPoint :public CCharacter{
private:
	CCollider mCollider;


public:
	
	CPoint();
	//�ݒ�
	//Set(�ʒu�A���a)
	void Set(const CVector &pos, float r);

	static CPoint*mpPoint;//�ڎw���|�C���g
	
};
#endif