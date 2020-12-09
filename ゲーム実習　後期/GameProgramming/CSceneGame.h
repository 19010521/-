#ifndef CSCENEGAME_H
#define CSCENEGAME_H
#include "CScene.h"
#include"CXPlayer.h"
#include"CXEnemy.h"
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
	 
	int mMouseX;
	int mMouseY;
	CEye mEye;
	CMap *mMap;
	
	CModel mCube;
	CModel Puddle;
	//CPuddle *mPuddle;
	//CPuddle1 *mPuddle1;
	//CPuddle2 *mPuddle2;
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
