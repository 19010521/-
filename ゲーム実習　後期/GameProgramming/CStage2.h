#ifndef CSTAGE2_H
#define CSTAGE2_H

#include"CScene.h"
#include"CSceneGame.h"
#include"CXPlayer.h"
#include"CXEnemy.h"
#include "CXPlayer.h"
#include "CMap.h"
#include"CPuddle.h"
#include"CEye.h"
#include"CAmount.h"
#include"CBomb.h"
#include"CWorkbench.h"
#include"CPuddlePoint.h"
/*
ゲームのシーン
*/
class CStage2 : public CSceneGame{
private:

	char buf[10];
	CXPlayer mPlayer;
	//敵のインスタンス
	CXEnemy *mEnemy;

	CAmount *Amount;

	CPuddlePoint *mPuddlePoint;

	int mMouseX;
	int mMouseY;
	int mExplosinCount = 30;
	//壁
	CCollider mCollider[14];


	CEye mEye;
	CMap *mMap;

	CMatrix Matrix;
	CModel mSky;
	CModel mPlane;

	CModel mRock;
	CModel mCube;
	CModel mBomb;

	CModel Puddle;
	CModel MudPuddle;
	CModel mWorkbench;

	CPuddle *mpPuddle;

	EScene GetNextScene();

	int DesuCount = 30;


	int frame;//フレーム数のカウント

	int Time;

	bool mEnd;



	//初期化処理のオーバーライド
	void Init();
	//更新処理のオーバーライド
	void Update();

public:

	CStage2(){};
	~CStage2();

	//static CModel mGun;


	//static CModel mItem;

	static int score;//スコア


	static bool Countf;


};
#endif