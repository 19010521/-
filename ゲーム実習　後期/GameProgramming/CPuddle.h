#ifndef CPUDDLE_H
#define CPUDDLE_H
#include"CCharacter.h"
#include"CCollider.h"
#include"CXEnemy.h"
class CPuddle :public CCharacter{
public:
	CCollider mPuddle0;
	static CPuddle*mPuddle;
	CXEnemy *mEnemy;

	CPuddle(CModel*model, CVector position, CVector rotation, CVector scale);
	int UseCount;//�g�p��
	int CountRetention;//�J�E���g�ێ�
	void Set(const CVector &pos, float r);

	void Collision(CCollider*m, CCollider*y);
	float x, y, z;
	float mx, mz;
	void Update();
	//void Render();

};
#endif
