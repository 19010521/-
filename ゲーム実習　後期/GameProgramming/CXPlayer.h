#ifndef CXPLAYER_H
#define CXPLAYER_H


#include "CXCharacter.h"
#include "CCollider.h"
#include"CCamera.h"


class CXPlayer :public CXCharacter{
public:
	CVector mTunRotation; //軸
	float mTurn; //回転


	enum Estate
	{
		ENORMAL,//ノーマル

		EMUD,  //泥

		EDESU, //死んだ

		EINVINCIBLE, //無敵

	};
	Estate mstate;
	//デフォルトコンストラクタ
	CXPlayer();
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
	

	static CXPlayer *mpxPlayer;

	void Init(CModelX*model);

	//更新処理
	void Update();

	void TaskCollision();
	static int mItem;
	static float mWaterCount;
	static float mWaterCountMax;
	
	int mHPNow;//プレイヤーのHP

	float mWaterCountStop;

	float mVelovcityJump;
	float mSpeed;
	int mBulletCount;
	int mBulletCountMax;
	int mClean_up;//水浄化アイテム
	int mBomb;//爆弾アイテム
	
	int mInvincibleCount;
	int mInvincibleCountMax;
	int mMudCount;
	int mDrawCount;//描画カウント

	bool jflag;//ジャンプフラグ
	bool waterflag;//水打つフラグ
	bool Damege;//ダメージ
	bool Damege2;//ダメージ2

	bool touchflag;//触れる

	

	void Collision(CCollider*mc, CCollider*yc);
	void Render()override;


};
#endif