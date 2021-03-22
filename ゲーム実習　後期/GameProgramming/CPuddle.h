#ifndef CPUDDLE_H
#define CPUDDLE_H
#include"CCharacter.h"
#include"CCollider.h"
#include"CXEnemy.h"
#include"CClean.h"
class CPuddle :public CCharacter{
private:

	CCollider mPuddle;

	CModel *Puddle;
	CModel *MudPuddle;

	CCollider*mpCollider;
	CXEnemy *mEnemy;

	CXEnemy2 *mEnemy2;
	//static変数の作成
	int frame;//フレーム数のカウント
	int frame1;//フレーム数のカウント
	int EnemyCount;//エネミーの出現数
	int EnemyCount1;//エネミーの出現数その2
	int mCount;//水の回復
	int mCountMax;//水の回復
	int mnumber;
	int mClean_upCount;//水浄化までのカウント
	int mClean_upCountMax;//水浄化までのカウント
	
	bool usefrag;
	bool rock;

	
	
	void Set(const CVector &pos, float r);

	void Collision(CCollider*m, CCollider*y);
	float x, y, z;
	float mx, mz;//減らすｘとｚ
	float mxMax, mzMax;//最大値のｘとｚ
	void Update();

public:

	
	
	static CPuddle*mpPuddle;

	
	static 	bool mClean_upCountflag;
	
	//敵の出現
	static bool Enemy;
	static bool Enemy2;

	CPuddle(CModel*model, CModel*model2, CVector position, CVector rotation, CVector scale);

	static int mclearcount;
	
	
	
	
	//void Render();

};
#endif
