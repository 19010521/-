#ifndef CWORKBENCH_H
#define CWORKBENCH_H
#include"CCharacter.h"
#include"CCollider.h"

class CWorkbench :public CCharacter{
private:
	
	CCollider mCollider;

public:
	
	CWorkbench(CModel*model, CVector position, CVector rotation, CVector scale);

	//void Collision(CCollider*m, CCollider*y);


};
class CWorkbench2 :public CCharacter{
private:

	CCollider mCollider;

public:
	
	CWorkbench2(CModel*model, CVector position, CVector rotation, CVector scale);

	//void Collision(CCollider*m, CCollider*y);


};
#endif