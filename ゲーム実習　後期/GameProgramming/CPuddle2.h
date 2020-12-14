#ifndef CPUDDLE2_H
#define CPUDDLE2_H
#include"CCharacter.h"
#include"CCollider.h"

class CPuddle2 :public CCharacter{
public:
	CCollider mPuddle2;
	static CPuddle2*mPuddle02;
	CPuddle2(CModel*model, CVector position, CVector rotation, CVector scale);

	void Set(const CVector &pos, float r);

	void Collision(CCollider*m, CCollider*y);

	//void Update();

};
#endif
