#ifndef CSCENEGAME_H
#define CSCENEGAME_H
#include "CScene.h"
#include"CXPlayer.h"
#include"CXEnemy.h"
#include"CXEnemy1.h"
#include "CXPlayer.h"
#include "CMap.h"
#include"CPuddle.h"
#include"CPuddle1.h"
#include"CPuddle2.h"
#include"CEye.h"


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

	int mMouseX;
	int mMouseY;

	//壁
	CCollider mCollider[14];


	CEye mEye;
	CMap *mMap;

	CModel mRock;
	CModel mCube;
	
	CModel Puddle;
	CModel MudPuddle;

	CModel Puddle1;
	CModel MudPuddle1;

	CModel Puddle2;
	CModel MudPuddle2;

	CPuddle *mpPuddle;
	CPuddle1 *mpPuddle1;
	CPuddle2 *mpPuddle2;
	EScene GetNextScene();
	static int frame;//フレーム数のカウント
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
