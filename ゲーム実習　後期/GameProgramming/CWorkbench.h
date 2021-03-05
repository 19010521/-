#ifndef CWORKBENCH_H
#define CWORKBENCH_H
#include"CCharacter.h"
#include"CCollider.h"

class CWorkbench :public CCharacter{
private:
	
	CCollider mCollider;

public:
	static CWorkbench *mpCWorkbench;
	
	CWorkbench(CModel*model, CVector position, CVector rotation, CVector scale);

	//void Collision(CCollider*m, CCollider*y);


};
#endif