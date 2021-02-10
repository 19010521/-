#ifndef CSCENEGAME_H
#define CSCENEGAME_H
#include "CScene.h"
#include"CXPlayer.h"
#include"CXEnemy.h"
#include"CXEnemy1.h"
#include"CXEnemy2.h"
#include "CXPlayer.h"
#include "CMap.h"
#include"CPuddle.h"
#include"CPuddle1.h"
#include"CPuddle2.h"
#include"CPuddle3.h"
#include"CEye.h"
#include"CAmount.h"
#include"CBomb.h"



/*
ゲームのシーン
*/
class CSceneGame : public CScene {
public:

	char buf[10];

	CXPlayer mPlayer;
	//敵のインスタンス
	CXEnemy *mEnemy;
	CXEnemy1*mEnemy1;
	CXEnemy2*mEnemy2;
	CAmount *Amount;
	int mMouseX;
	int mMouseY;
	int mExplosinCount = 30;
	//壁
	CCollider mCollider[14];


	CEye mEye;
	CMap *mMap;

	CModel mRock;
	CModel mCube;
	CModel mBomb;
	static CModel mGun;
	
	CModel Puddle;
	CModel MudPuddle;

	CModel Puddle1;
	CModel MudPuddle1;

	CModel Puddle2;
	CModel MudPuddle2;

	CModel Puddle3;
	CModel MudPuddle3;

	CPuddle *mpPuddle;
	//CPuddle1 *mpPuddle1;
	//CPuddle2 *mpPuddle2;
	//CPuddle3 *mpPuddle3;
	EScene GetNextScene();

	int DesuCount=30;
	static int frame;//フレーム数のカウント
	static int score;//スコア
	static int Time;

	static bool Countf;
	CSceneGame(){};
	~CSceneGame();
	static bool mEnd;
	//初期化処理のオーバーライド
	void Init();
	//更新処理のオーバーライド
	void Update();

};

#endif
