#ifndef CWORKBENCH_H
#define CWORKBENCH_H
#include"CCharacter.h"
#include"CCollider.h"

class CWorkbench :public CCharacter{
public:
	static CWorkbench *mpCWorkbench;
	CWorkbench(CModel*model, CVector position, CVector rotation, CVector scale);
	CCollider mCollider;
	

	//void Collision(CCollider*m, CCollider*y);


};
#endif