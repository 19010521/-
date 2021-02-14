
#include <Windows.h>
#include "CSceneGame.h"
//
#include"CXCharacter.h"
#include "CCamera.h"
//
#include "CText.h"
#include"CRes.h"
#include"CMaterial.h"
#include"CCollisionManager.h"
#include"CInput.h"
#include"CObj.h"
#include"CKey.h"
#include"CRock.h"
#include"CRock2.h"

CMatrix Matrix;
CModel mSky;
CModel mPlane;
bool CSceneGame::Countf = false;
int CSceneGame::frame = 0;
int CSceneGame::score = 0;
int CSceneGame::Time = 60 * 60;
bool CSceneGame::mEnd = false;
CModel CSceneGame::mGun;

std::shared_ptr<CTexture>TextureExp1(new CTexture());

//キャラクタのインスタンス
//CXCharacter mPlayer;
CSceneGame::~CSceneGame() {
	delete[] CXEnemy::mPoint;
}

//次のシーンの取得
CScene::EScene CSceneGame::GetNextScene() {
	return mScene;
}

void CSceneGame::Init() {

	mScene = EGAME;
	


	mEnd = false;

	CXEnemy::mPointSize = 4;//ポイント数の設定
	CXEnemy::mPoint = new CPoint[CXEnemy::mPointSize];
	
	CXEnemy::mPoint[0].Set(CVector(30.0f, 5.0f, -70.0f), 5.0f);
	CXEnemy::mPoint[1].Set(CVector(95.0f, 5.0f, -110.0f), 5.0f);
	CXEnemy::mPoint[2].Set(CVector(95.0f, 5.0f, -30.0f), 5.0f);
	CXEnemy::mPoint[3].Set(CVector(55.0f, 5.0f, -30.0f), 5.0f);


	mRock.Load("Rock1.obj", "Rock1.mtl");
	
	mSky.Load("sky.obj", "sky.mtl");
	mCube.Load("Cube.obj", "Cube.mtl");
	Puddle.Load("sphere.obj", "sphere.mtl");
	MudPuddle.Load("sphere2.obj", "sphere2.mtl");
	mGun.Load("sphere.obj", "sphere.mtl");
	mBomb.Load("sphere.obj", "sphere.mtl");

	TextureExp1->Load("exp.tga");



	mpPuddle = new CPuddle(&Puddle, &MudPuddle, CVector(-80.0f, 0.0f, 90.0f), CVector(), CVector(0.9f, 0.1f, 0.9f));

	mpPuddle = new CPuddle(&Puddle,&MudPuddle, CVector(30.0f, 0.0f, -5.0f), CVector(), CVector(0.9f, 0.1f, 0.9f));
	
	mpPuddle = new CPuddle(&Puddle, &MudPuddle, CVector(-0.5f, 0.0f, -90.0f), CVector(), CVector(0.9f, 0.1f, 0.9f));
	//mpPuddle->mTag = mpPuddle->EMUDPUDDLE;
	
	mpPuddle->mpModel = &MudPuddle;


	mpPuddle = new CPuddle(&Puddle, &MudPuddle, CVector(-0.5f, 0.0f, -30.0f), CVector(), CVector(0.9f, 0.1f, 0.9f));
	//mpPuddle->mTag = mpPuddle->EMUDPUDDLE;
	//mpPuddle->mpModel = &MudPuddle;
	
	
	
	CRes::sModelX.Load(MODEL_FILE);
	CRes::sKnight.Load(MODEL_FILE2);
	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//1:移動
	CRes::sKnight.SeparateAnimationSet(0, 1530, 1830, "idle1");//2:待機
	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//3:ダミー
	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//4:ダミー
	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//5:ダミー
	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//6ダミー
	CRes::sKnight.SeparateAnimationSet(0, 440, 520, "attack1");//7Attack1
	CRes::sKnight.SeparateAnimationSet(0, 520, 615, "attack2");//7Attack2
	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//9ダミー
	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//10ダミー
	CRes::sKnight.SeparateAnimationSet(0, 1160, 1260, "death1");//11:ダウン

	//壊せる壁
	new CRock(&mRock, CVector(56.0f, 0.0f, -18.0f), CVector(), CVector(6.0f, 6.0f, 6.0f));
	
	//壁
	new CObj(&mCube, CVector(85.0f, 0.0f, -20.0f), CVector(), CVector(20.0f, 2.0f, 1.0f));
	
	new CRock2(&mRock, CVector(85.0f, 0.0f, -20.0f), CVector(), CVector(13.0f, 5.0f, 1.5f));
	new CObj(&mCube, CVector(30.0f, 0.0f, -20.0f), CVector(), CVector(15.0f, 2.0f, 1.0f));
	new CRock2(&mRock, CVector(32.0f, 0.0f, -20.0f), CVector(), CVector(11.0f, 5.0f, 1.5f));
	new CObj(&mCube, CVector(65.0f, 0.0f, 5.0f), CVector(), CVector(1.0f, 2.0f, 25.0f));
	new CRock2(&mRock, CVector(65.0f, 0.0f, 5.0f), CVector(), CVector(1.5f, 5.0f, 15.0f));
	new CObj(&mCube, CVector(45.0f, 0.0f, 5.0f), CVector(), CVector(1.0f, 2.0f, 25.0f));
	new CRock2(&mRock, CVector(45.0f, 0.0f, 5.0f), CVector(), CVector(1.5f, 5.0f, 15.0f));
	new CObj(&mCube, CVector(-30.0f, 0.0f, -20.0f), CVector(), CVector(25.0f, 2.0f, 1.0f));
	new CRock2(&mRock, CVector(-14.0f, 0.0f, -20.0f), CVector(), CVector(9.0f, 5.0f, 1.5f));
	new CObj(&mCube, CVector(100.0f, 0.0f, -70.0f), CVector(), CVector(1.0f, 2.0f, 60.0f));
	new CRock2(&mRock, CVector(100.0f, 0.0f, -78.0f), CVector(), CVector(1.5f, 5.0f, 40.0f));
	new CObj(&mCube, CVector(40.0f, 0.0f, -120.0f), CVector(), CVector(80.0f, 2.0f, 1.0f));
	new CRock2(&mRock, CVector(40.0f, 0.0f, -120.0f), CVector(), CVector(80.0f, 5.0f, 1.5f));
	new CObj(&mCube, CVector(-30.0f, 0.0f, -70.0f), CVector(), CVector(1.0f, 2.0f, 60.0f));
	new CRock2(&mRock, CVector(-30.0f, 0.0f, -70.0f), CVector(), CVector(1.5f, 5.0f, 40.0f));

	new CObj(&mCube, CVector(15.0f, 0.0f, 0.0f), CVector(), CVector(1.0f, 2.0f, 20.0f));
	new CRock2(&mRock, CVector(15.0f, 0.0f, 0.0f), CVector(), CVector(1.5f, 5.0f, 13.0f));
	new CObj(&mCube, CVector(-5.0f, 0.0f, -10.0f), CVector(), CVector(1.0f, 2.0f, 10.0f));
	new CRock2(&mRock, CVector(-5.0f, 0.0f, -10.0f), CVector(), CVector(1.5f, 5.0f, 7.0f));

	new CObj(&mCube, CVector(-10.0f, 0.0f, 20.0f), CVector(), CVector(25.0f, 2.0f, 1.0f));
	new CRock2(&mRock, CVector(-8.0f, 0.0f, 20.0f), CVector(), CVector(18.0f,5.0f, 1.5f));
	new CObj(&mCube, CVector(-65.0f, 0.0f, 3.0f), CVector(0.0f, 3.0f, 0.0f), CVector(60.0f, 2.0f, 1.0f));
	new CRock2(&mRock, CVector(-70.0f, 0.0f, 3.0f), CVector(0.0f, 3.0f, 0.0f), CVector(50.0f, 5.0f, 1.5f));

	new CObj(&mCube, CVector(-30.0f, 0.0f, 50.0f), CVector(0.0f,10.0f,0.0f), CVector(1.0f, 2.0f, 30.0f));
	new CRock2(&mRock, CVector(-30.0f, 0.0f, 51.0f), CVector(0.0f, 10.0f, 0.0f), CVector(1.5f, 5.0f, 19.0f));
	new CObj(&mCube, CVector(-45.0f, 0.0f, 50.0f), CVector(0.0f, 10.0f, 0.0f), CVector(1.0f, 2.0f, 30.0f));
	new CRock2(&mRock, CVector(-45.0f, 0.0f, 50.0f), CVector(0.0f, 10.0f, 0.0f), CVector(1.5f, 5.0f, 19.0f));
	new CObj(&mCube, CVector(-75.0f, 0.0f, 22.0f), CVector(0.0f, 5.0f, 0.0f), CVector(25.0f, 2.0f, 1.0f));
	new CRock2(&mRock, CVector(-75.0f, 0.0f, 22.0f), CVector(0.0f, 5.0f, 0.0f), CVector(18.0f, 5.0f, 1.5f));

	new CObj(&mCube, CVector(-105.0f, 0.0f, 43.0f), CVector(0.0f, -10.0f, 0.0f), CVector(1.0f, 2.0f, 20.0f));
	new CRock2(&mRock, CVector(-105.0f, 0.0f, 43.0f), CVector(0.0f, -10.0f, 0.0f), CVector(1.5f, 5.0f, 14.0f));
	new CObj(&mCube, CVector(-120.0f, 0.0f, 50.0f), CVector(0.0f, 3.0f, 0.0f), CVector(1.0f, 2.0f, 45.0f));
	new CRock2(&mRock, CVector(-120.0f, 0.0f, 50.0f), CVector(0.0f, 3.0f, 0.0f), CVector(1.5f, 5.0f, 40.0f));

	new CObj(&mCube, CVector(-75.0f, 0.0f, 70.0f), CVector(0.0f, -12.0f, 0.0f), CVector(35.0f, 2.0f, 1.0f));
	new CRock2(&mRock, CVector(-75.0f, 0.0f, 70.0f), CVector(0.0f, -12.0f, 0.0f), CVector(20.0f, 5.0f, 1.5f));

	new CObj(&mCube, CVector(10.0f, 0.0f, 70.0f), CVector(0.0f, 20.0f, 0.0f), CVector(35.0f, 2.0f, 1.0f));
	new CRock2(&mRock, CVector(10.0f, 0.0f, 70.0f), CVector(0.0f, 20.0f, 0.0f), CVector(25.0f, 5.0f, 1.5f));

	new CObj(&mCube, CVector(112.0f, 0.0f, 45.0f), CVector(0.0f, 12.0f, 0.0f), CVector(1.0f, 2.0f, 60.0f));
	new CRock2(&mRock, CVector(112.0f, 0.0f, 45.0f), CVector(0.0f, 12.0f, 0.0f), CVector(1.5f, 5.0f, 45.0f));
	new CObj(&mCube, CVector(70.0f, 0.0f, 110.0f), CVector(0.0f, 15.0f, 0.0f), CVector(60.0f, 2.0f, 1.0f));
	new CRock2(&mRock, CVector(70.0f, 0.0f, 110.0f), CVector(0.0f, 15.0f, 0.0f), CVector(60.0f, 5.0f, 1.5f));
	new CObj(&mCube, CVector(-50.0f, 0.0f, 110.0f), CVector(0.0f, -15.0f, 0.0f), CVector(70.0f, 2.0f, 1.0f));
	new CRock2(&mRock, CVector(-50.0f, 0.0f, 110.0f), CVector(0.0f, -15.0f, 0.0f), CVector(70.0f, 5.0f, 1.5f));

	new CBomb(&mBomb, CVector(80.0f, 0.0f, -70.0f), CVector(), CVector(2.0f, 2.0f, 2.0f));


	//キャラクターにモデルを設定する

	mPlayer.Init(&CRes::sModelX);
	mPlayer.mPosition = CVector(0.0f, 0.0f, -80);
	
	
	//テキストフォントの読み込みと設定
	CText::mFont.Load("FontG.tga");
	CText::mFont.SetRowCol(1, 4096 / 64);

	//new CEye(&mCube, CVector(0.0f, 0.0f, 0.0f), CVector(), CVector(0.0f, 0.0f, 0.0f));

	Amount = new CAmount();

	mMap = new CMap();

	

}


void CSceneGame::Update() {


	if (Time > 0){
		Time--;
	}
	
	
	if (mEnd == false){
		CTaskManager::Get()->Update();

		//衝突処理
	}

	if (mEnd == true){
		if (CKey::Once(VK_RETURN)){
			mScene = ETITLE;
		}
	}
	//キャラクタークラスの更新
	

	
	CCollisionManager::Get()->Collision();

	mEye.mPosition = mPlayer.mPosition;
	
	//カメラのパラメータを作成する
	CVector e, c, u;//視点、注視点、上方向
	e =  CVector(0.0f, 5.0f, -10.0f)*mEye.mMatrix;

	c = mEye.mPosition + CVector(0.0f, 2.0f, 0.0f);

	//上方向を求める
	u = CVector(0.0f, 1.0f, 0.0f)*mEye.mMatrixRotate;
	
	if (CKey::Push('M')){


		//視点を求める
		e = CVector(0.0f, 200.0f, -1.0f);
		//注視点を求める
		c = CVector();
		//上方向を求める
		u = CVector(0.0f, 1.0f, 0.0f);
		//カメラの設定
	}
	
	Camera3D(e.mX, e.mY, e.mZ, c.mX, c.mY, c.mZ, u.mX, u.mY, u.mZ);
	Camera.mEye = e;
	

	CTaskManager::Get()->Delete();
	CTaskManager::Get()->Render();

	//コライダの描画
	CCollisionManager::Get()->Render();



	mSky.Render();
	
	//mEye.Render();


	//テクスチャテスト
	//CRes::sModelX.mMaterial[0]->mpTexture->DrawImage(-5, 5, -5,5, 0, 128, 128, 0);


	//2D描画開始
	Start2D(-400, 400, -300, 300);
	//CText::DrawString("SCORE", -350 , 250, 16, 16);
	sprintf(buf, "%d", score);//スコア
	CText::DrawString(buf, -350 , 250, 16, 16);

	sprintf(buf, "%d", Time / 60);
	CText::DrawString(buf, 300, 250, 16, 16);
	

	/*if (CPuddle::mPuddle->mPuddle0.mTag == CCollider::EPUDDLE0){

		CText::DrawString("GAME CLEAR", -100, 0, 20, 20);
		mEnd = true;
	}
	*/
	if (CXPlayer::mpxPlayer->mstate==CXPlayer::mpxPlayer->EDESU){
		if (DesuCount > 0){
			DesuCount--;
		}
		else{
			CText::DrawString("GAME OVER", -100, 0, 20, 20);
			mEnd = true;
		}
		

	}

	sprintf(buf, "%d", CXPlayer::mpxPlayer->mHPNow);
	CText::DrawString(buf, -280, -180, 20, 20);

	Amount->x = -350;
	Amount->y = -260 + Amount->h;
	Amount->h = CXPlayer::mpxPlayer->mWaterCount/ CXPlayer::mpxPlayer->mWaterCountMax * 100;
	Amount->w = 16;
	Amount->mEnabled = true;
	Amount->Render();

	//2D描画終了
	End2D();

	return;

}

