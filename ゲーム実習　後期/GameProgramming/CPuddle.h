#ifndef CPUDDLE_H
#define CPUDDLE_H
#include"CCharacter.h"
#include"CCollider.h"

class CPuddle :public CCharacter{
public:
	CCollider mPuddle0;
	
	CPuddle(CModel*model, CVector position, CVector rotation, CVector scale);
	
	void Set(const CVector &pos, float r);
	
	void Collision(CCollider*m, CCollider*y);

	//void Update();

};
#endif
