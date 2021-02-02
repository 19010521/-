#ifndef CPUDDLE3_H
#define CPUDDLE3_H
#include"CCharacter.h"
#include"CCollider.h"

class CPuddle3 :public CCharacter{
public:
	CCollider mPuddle3;
	static CPuddle3*mPuddle03;
	CPuddle3(CModel*model, CVector position, CVector rotation, CVector scale);

	void Set(const CVector &pos, float r);

	int UseCount;//�g�p��
	int CountRetention;//�J�E���g�ێ�

	void Collision(CCollider*m, CCollider*y);
	float x, y, z;
	float mx, mz;
	void Update();

};
#endif
