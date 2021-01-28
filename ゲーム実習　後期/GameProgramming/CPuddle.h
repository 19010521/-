#ifndef CPUDDLE_H
#define CPUDDLE_H
#include"CCharacter.h"
#include"CCollider.h"

class CPuddle :public CCharacter{
public:
	CCollider mPuddle0;
	static CPuddle*mPuddle;

	CPuddle(CModel*model, CVector position, CVector rotation, CVector scale);
	int UseCount;//使用回数
	int CountRetention;//カウント保持
	void Set(const CVector &pos, float r);

	void Collision(CCollider*m, CCollider*y);
	float x, y, z;
	float mx, mz;
	void Update();
	//void Render();

};
#endif
