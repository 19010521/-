#ifndef CPUDDLE_H
#define CPUDDLE_H
#include"CCharacter.h"
#include"CCollider.h"
#include"CXEnemy.h"
class CPuddle :public CCharacter{
public:


	CCollider mPuddle;
	static CPuddle*mpPuddle;

	CModel *Puddle;
	CModel *MudPuddle;

	CXEnemy *mEnemy;

	CPuddle(CModel*model,CModel*model2, CVector position, CVector rotation, CVector scale);
	//static変数の作成
	int frame ;//フレーム数のカウント
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
