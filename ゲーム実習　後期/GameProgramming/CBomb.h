#ifndef CBOMB_H
#define CBOMB_H
#include"CCharacter.h"
#include"CCollider.h"

class CBomb :public CCharacter{
private:
	CCollider mBomb;

	void Update();

public:

	CBomb(CModel*model, CVector position, CVector rotation, CVector scale);
	
	
};
#endif