#ifndef CSCENEGAME_H
#define CSCENEGAME_H
#include "CScene.h"
#include"CXPlayer.h"
#include"CXEnemy.h"

#include "CXPlayer.h"
#include "CMap.h"
#include"CPuddle.h"
#include"CEye.h"
#include"CAmount.h"
#include"CBomb.h"

#include"CPuddlePoint.h"



/*
ゲームのシーン
*/
class CSceneGame : public CScene {
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

	CSceneGame(){};
	~CSceneGame();

	static CModel mGun;
	
	static CModel mItem;

	static int Combo;//コンボ

	static int ComboMax;//コンボ最大

	static int score;//スコア

	static int Defeats;//撃破数
    

	static bool Countf;
	
	
	
};
/*
ゲームのシーン
*/
class CSceneGame2 : public CScene {
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

	CSceneGame2(){};
	~CSceneGame2();

	static CModel mGun;

	static CModel mItem;

	static int Combo;//コンボ

	static int ComboMax;//コンボ最大

	static int score;//スコア

	static int Defeats;//撃破数


	static bool Countf;



};


#endif
