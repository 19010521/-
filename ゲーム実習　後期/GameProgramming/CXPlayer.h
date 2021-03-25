#ifndef CXPLAYER_H
#define CXPLAYER_H


#include "CXCharacter.h"
#include "CCollider.h"
#include"CCamera.h"


class CXPlayer :public CXCharacter{
private:

	//更新処理
	void Update();

	void TaskCollision();


	

	float mWaterCountStop;

	float mVelovcityJump;
	float mSpeed;
	int mBulletCount;
	int mBulletCountMax;

	int mComboCount;//コンボのカウント
	int mComboCountMax;//コンボのカウント最大

	int mComboMemory;//コンボ記憶させておく


	int mInvincibleCount;
	int mInvincibleCountMax;
	int mMudCount;
	int mDrawCount;//描画カウント

	bool jflag;//ジャンプフラグ
	bool waterflag;//水打つフラグ
	
	
	

	CVector mTunRotation; //軸
	float mTurn; //回転



	//デフォルトコンストラクタ

	CMatrix Matrix;

	//コライダの宣言
	CCamera mCamera;
	CCollider mColSphereBody;   //体
	CCollider mColSphereHead;   //頭
	CCollider mColSphereSword;  //剣
	CCollider mColSphereLeg0;   //足
	CCollider mColSphereLeg1;   //足
	CCollider mSearch;
	CCollider mColBody;






	void Collision(CCollider*mc, CCollider*yc);
	void Render()override;


public:

	enum Estate
	{
		ENORMAL,//ノーマル

		EMUD,  //泥

		EDESU, //死んだ

		EINVINCIBLE, //無敵

	};
	Estate mstate;

	static CXPlayer *mpxPlayer;

	static float mWaterCount;
	static float mWaterCountMax;
	

	CXPlayer();

	void Init(CModelX*model);




	int mClean_up;//水浄化アイテム
	int mHPNow;//プレイヤーのHP

	bool touchflag;//触れる
	bool touchflag2;//触れる
	bool Comboflag;//コンボの時間
	bool Damege;//ダメージ

};
#endif