#ifndef CPOINT_H
#define CPOINT_H
#include "CCollider.h"
#include"CCharacter.h"
/*
敵機などの目標
*/
class CPoint :public CCharacter{
private:
	CCollider mCollider;


public:
	
	CPoint();
	//設定
	//Set(位置、半径)
	void Set(const CVector &pos, float r);

	static CPoint*mpPoint;//目指すポイント
	
};
#endif