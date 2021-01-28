#ifndef CPUDDLE1_H
#define CPUDDLE1_H
#include"CCharacter.h"
#include"CCollider.h"

class CPuddle1 :public CCharacter{
public:
	CCollider mPuddle1;
	static CPuddle1*mPuddle01;
	CPuddle1(CModel*model, CVector position, CVector rotation, CVector scale);
	
	void Set(const CVector &pos, float r);

	int UseCount;//使用回数
	int CountRetention;//カウント保持

	void Collision(CCollider*m, CCollider*y);
	float x, y, z;
	float mx, mz;
	void Update();

};
#endif
