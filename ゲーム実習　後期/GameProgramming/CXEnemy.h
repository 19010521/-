#ifndef CXENEMY_H
#define CXENEMY_H

#include "CXCharacter.h"
#include"CCollider.h"
#include"CPoint.h"
#include"CItem.h"


class CXEnemy :public CXCharacter{
private:

	int Randam;
	
	void Update();
	CCollider mColSphereBody;//体

	CCollider mColSphereHead;   //頭
	CCollider mColSphereSword0;  //剣
	CCollider mColSphereSword1;  //剣1
	CCollider mColSphereSword2;  //剣2
	CCollider mColSphereLeg0;   //足
	CCollider mColSphereLeg1;   //足
	CCollider mSearch;

	float mVelovcityJump;
	float mSpeed;
	int mnearCount;
	int mnearCountMax;
	int mCount;
	int mCountMax;
	int fCount;
	int fCountMax;
	int mAttaccount;
	int mAttaccountMax;
	
	bool nflag;//気づいたフラグ
	bool jflag;//ジャンプフラグ
	bool lflag;//後転フラグ
	bool aflag;//攻撃フラグ
	bool mflag;//動くフラグ

	float mHPMax;//敵のHP
	float mHPNow;

	

	//衝突処理
	void Collision(CCollider*m, CCollider*y);

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

		EDESU,//死
	};
	Estate mstate;

	CXEnemy();
	void Init(CModelX*model);

	static int mPointSize;//ポイントの数
	CPoint*mpPoint;//目指すポイント
	int mPointCnt;//ポイントのカウンタ

	//誘導ポイント
	static CPoint *mPoint;


	CItem *mItem;
	//CEnemy(モデル,位置,回転,拡縮)

	
	

	static bool Attackflag;
	static bool Call;//仲間を呼ぶ
	static bool Desuflag;//死んだフラグ
};

class CXEnemy2 :public CXCharacter{
private:

	int Randam;

	void Update();
	CCollider mColSphereBody;//体

	CCollider mColSphereHead;   //頭
	CCollider mColSphereSword0;  //剣
	CCollider mColSphereSword1;  //剣1
	CCollider mColSphereSword2;  //剣2
	CCollider mColSphereLeg0;   //足
	CCollider mColSphereLeg1;   //足
	CCollider mSearch;

	float mVelovcityJump;
	float mSpeed;
	int mnearCount;
	int mnearCountMax;
	int mCount;
	int mCountMax;
	int fCount;
	int fCountMax;
	int mAttaccount;
	int mAttaccountMax;
	
	bool nflag;//気づいたフラグ
	bool jflag;//ジャンプフラグ
	bool lflag;//後転フラグ
	bool aflag;//攻撃フラグ
	bool mflag;//動くフラグ

	float mHPMax;//敵のHP
	float mHPNow;



	//衝突処理
	void Collision(CCollider*m, CCollider*y);

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

		EDESU,//死
	};
	Estate mstate;

	CXEnemy2();
	void Init(CModelX*model);

	static int mPointSize;//ポイントの数
	CPoint*mpPoint;//目指すポイント
	int mPointCnt;//ポイントのカウンタ

	//誘導ポイント
	static CPoint *mPoint;


	CItem *mItem;
	//CEnemy(モデル,位置,回転,拡縮)

	

	static bool Attackflag;
	static bool Call;//仲間を呼ぶ
	static bool Desuflag;//死んだフラグ
};
#endif
