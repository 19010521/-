#ifndef CPUDDLEPOINT_H
#define CPUDDLEPOINT_H
#include "CCollider.h"
#include"CCharacter.h"
/*
敵機などの目標
*/
class CPuddlePoint :public CCharacter{
private:
	CCollider mCollider;
	CCollider mCollider2;



public:

	CPuddlePoint();
	//設定
	//Set(位置、半径)
	void Set(const CVector &pos, float r);

	

};
#endif