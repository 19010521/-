#ifndef CPOINT_H
#define CPOINT_H
#include "CCollider.h"
#include"CCharacter.h"
/*
�G�@�Ȃǂ̖ڕW
*/
class CPoint :public CCharacter{
public:
	CCollider mCollider;

	static CPoint*mpPoint;//�ڎw���|�C���g
	CPoint();
	//�ݒ�
	//Set(�ʒu�A���a)
	void Set(const CVector &pos, float r);
};
#endif