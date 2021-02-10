#ifndef CBOMB_H
#define CBOMB_H
#include"CCharacter.h"
#include"CCollider.h"

class CBomb :public CCharacter{
public:

	CBomb(CModel*model, CVector position, CVector rotation, CVector scale);
	CCollider mBomb;

	void Update();
	
};
#endif