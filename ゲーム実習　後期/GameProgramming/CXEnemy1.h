#ifndef CXENEMY1_H
#define CXENEMY1_H

#include "CCharacter.h"
#include"CCollider.h"
#include"CPoint.h"


class CXEnemy1 :public CCharacter{
public:
	enum Estate
	{
		ENORMAL,//通常

		EWALK,//歩く

		ENEAR,//近ずく

		EATTACK1,//突進

		EJUNP,//ジャンプ

		ELANDING,//着地

		EBACKFLIP,//後転

		EWAIT,//待機

	};
	Estate mstate;


	static int mPointSize;//ポイントの数
	CPoint*mpPoint;//目指すポイント
	int mPointCnt;//ポイントのカウンタ

	//誘導ポイント
	static CPoint *mPoint;
	int Randam;
	//CEnemy(モデル,位置,回転,拡縮)

	CXEnemy1(CModel*model, CVector position, CVector rotation, CVector scale);
	void Update();
	CCollider mColSphereBody;//体

	CCollider mColSphereHead;   //頭
	CCollider mColSphereSword0;  //剣
	CCollider mColSphereSword1;  //剣1
	CCollider mColSphereSword2;  //剣2
	CCollider mSearch;
	CCollider mSearch2;

	//CCollider mSearch2;
	float mVelovcityJump;
	int mnearCount;
	int mnearCountMax;
	int mCount;
	int mCountMax;
	int fCount;
	int fCountMax;
	bool nflag;//気づいたフラグ
	bool jflag;//ジャンプフラグ
	bool lflag;//後転フラグ
	bool wflag;//止まるフラグ
	bool mflag;//動くフラグ
	

	static bool Attackflag;
	void Init(CModelX*model);
	//衝突処理
	void Collision(CCollider*m, CCollider*y);
};
#endif
