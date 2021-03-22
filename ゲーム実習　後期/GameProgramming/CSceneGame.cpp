
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

#define GAMEOVERA (0)
#define  PUDDLE (6)//�����܂�̐�

CMatrix Matrix;
CModel mSky;
CModel mPlane;
bool CSceneGame::Countf = false;

int CSceneGame::score = 0;
int CSceneGame::Combo = 0;
int CSceneGame::ComboMax = 0;
int CSceneGame::Defeats = 0;
CModel CSceneGame::mGun;
CModel CSceneGame::mItem;

std::shared_ptr<CTexture>TextureExp1(new CTexture());

//�L�����N�^�̃C���X�^���X
//CXCharacter mPlayer;
CSceneGame::~CSceneGame() {
	delete[] CXEnemy::mPoint;
}

//���̃V�[���̎擾
CScene::EScene CSceneGame::GetNextScene() {
	return mScene;
}

void CSceneGame::Init() {

	mScene = EGAME;

	frame = 0;
	Time = 360 * 60;

	mEnd = false;

	CXEnemy::mPointSize = 6;//�|�C���g���̐ݒ�
	CXEnemy::mPoint = new CPoint[CXEnemy::mPointSize];

	CXEnemy::mPoint[0].Set(CVector(30.0f, 5.0f, -70.0f), 5.0f);
	CXEnemy::mPoint[1].Set(CVector(95.0f, 5.0f, -110.0f), 5.0f);
	CXEnemy::mPoint[2].Set(CVector(95.0f, 5.0f, -30.0f), 5.0f);
	CXEnemy::mPoint[3].Set(CVector(30.0f, 5.0f, -30.0f), 5.0f);

	CXEnemy::mPoint[4].Set(CVector(-0.5f, 0.0f, -30.0f), 5.0f);
	CXEnemy::mPoint[5].Set(CVector(-0.5f, 0.0f, -90.0f), 5.0f);


	CXEnemy2::mPointSize = 6;//�|�C���g���̐ݒ�
	CXEnemy2::mPoint = new CPoint[CXEnemy2::mPointSize];

	CXEnemy2::mPoint[0].Set(CVector(-30.0f, 5.0f, 90.0f), 5.0f);
	CXEnemy2::mPoint[1].Set(CVector(95.0f, 5.0f, 90.0f), 5.0f);
	CXEnemy2::mPoint[2].Set(CVector(30.0f, 5.0f, 30.0f), 5.0f);
	CXEnemy2::mPoint[3].Set(CVector(95.0f, 5.0f, 30.0f), 5.0f);
	CXEnemy2::mPoint[4].Set(CVector(-60.0f, 0.0f, 30.0f), 5.0f);
	CXEnemy2::mPoint[5].Set(CVector(-80.0f, 0.0f, 90.0f), 5.0f);

	mRock.Load("Rock1.obj", "Rock1.mtl");

	mSky.Load("sky.obj", "sky.mtl");
	mCube.Load("Cube.obj", "Cube.mtl");
	Puddle.Load("sphere.obj", "sphere.mtl");
	MudPuddle.Load("sphere2.obj", "sphere2.mtl");
	mGun.Load("sphere.obj", "sphere.mtl");
	mBomb.Load("sphere.obj", "sphere.mtl");
	mWorkbench.Load("sphere.obj", "sphere.mtl");
	mItem.Load("Rock1.obj", "Rock1.mtl");

	TextureExp1->Load("exp.tga");



	mpPuddle = new CPuddle(&Puddle, &MudPuddle, CVector(-80.0f, 0.0f, 90.0f), CVector(), CVector(0.9f, 0.1f, 0.9f));

	if (mpPuddle->mpModel == &Puddle){
		
		CPuddle::mclearcount++;
	}
	
	mpPuddle = new CPuddle(&Puddle, &MudPuddle, CVector(80.0f, 0.0f, 90.0f), CVector(), CVector(0.9f, 0.1f, 0.9f));
	mpPuddle->mpModel = &MudPuddle;
	if (mpPuddle->mpModel == &Puddle){
		
		CPuddle::mclearcount++;
	}

	mpPuddle = new CPuddle(&Puddle, &MudPuddle, CVector(-60.0f, 0.0f, 30.0f), CVector(), CVector(0.9f, 0.1f, 0.9f));

	if (mpPuddle->mpModel == &Puddle){
		
		CPuddle::mclearcount++;
	}


	mpPuddle = new CPuddle(&Puddle,&MudPuddle, CVector(30.0f, 0.0f, 10.0f), CVector(), CVector(0.9f, 0.1f, 0.9f));
	
	if (mpPuddle->mpModel == &Puddle){
		
		CPuddle::mclearcount++;
	}


	mpPuddle = new CPuddle(&Puddle, &MudPuddle, CVector(-0.5f, 0.0f, -90.0f), CVector(), CVector(0.9f, 0.1f, 0.9f));

	mpPuddle->mpModel = &MudPuddle;
	if (mpPuddle->mpModel == &Puddle){
		
		CPuddle::mclearcount++;
	}
	
	mpPuddle = new CPuddle(&Puddle, &MudPuddle, CVector(-0.5f, 0.0f, -70.0f), CVector(), CVector(0.9f, 0.1f, 0.9f));

	//mpPuddle->mpModel = &MudPuddle;
	if (mpPuddle->mpModel == &Puddle){

		CPuddle::mclearcount++;
	}



	mpPuddle = new CPuddle(&Puddle, &MudPuddle, CVector(70.0f, 0.0f, -50.0f), CVector(), CVector(0.9f, 0.1f, 0.9f));
	
	mpPuddle->mpModel = &MudPuddle;
	if (mpPuddle->mpModel == &Puddle){
		
		CPuddle::mclearcount++;
	}
	
	
	
	CRes::sModelX.Load(MODEL_FILE);
	CRes::sKnight.Load(MODEL_FILE2);
	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//1:�ړ�
	CRes::sKnight.SeparateAnimationSet(0, 1530, 1830, "idle1");//2:�ҋ@
	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//3:�_�~�[
	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//4:�_�~�[
	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//5:�_�~�[
	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//6�_�~�[
	CRes::sKnight.SeparateAnimationSet(0, 440, 520, "attack1");//7Attack1
	CRes::sKnight.SeparateAnimationSet(0, 520, 615, "attack2");//7Attack2
	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//9�_�~�[
	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//10�_�~�[
	CRes::sKnight.SeparateAnimationSet(0, 1160, 1260, "death1");//11:�_�E��

	////�󂹂��
	//new CRock(&mRock, CVector(56.0f, 0.0f, -18.0f), CVector(), CVector(6.0f, 6.0f, 6.0f));

	//new CRock(&mRock, CVector(-45.0f, 0.0f, 15.0f), CVector(), CVector(6.0f, 6.0f, 6.0f));
	
	//��
	new CObj(&mCube, CVector(85.0f, 0.0f, -20.0f), CVector(), CVector(20.0f, 5.0f, 1.0f));
	
	new CRock2(&mRock, CVector(85.0f, 0.0f, -20.0f), CVector(), CVector(13.0f, 5.0f, 1.5f));
	new CObj(&mCube, CVector(30.0f, 0.0f, -20.0f), CVector(), CVector(15.0f, 5.0f, 1.0f));
	new CRock2(&mRock, CVector(32.0f, 0.0f, -20.0f), CVector(), CVector(11.0f, 5.0f, 1.5f));
	new CObj(&mCube, CVector(65.0f, 0.0f, 5.0f), CVector(), CVector(1.0f, 5.0f, 25.0f));
	new CRock2(&mRock, CVector(65.0f, 0.0f, 5.0f), CVector(), CVector(1.5f, 5.0f, 15.0f));
	new CObj(&mCube, CVector(45.0f, 0.0f, 5.0f), CVector(), CVector(1.0f, 5.0f, 25.0f));
	new CRock2(&mRock, CVector(45.0f, 0.0f, 5.0f), CVector(), CVector(1.5f, 5.0f, 15.0f));
	new CObj(&mCube, CVector(-30.0f, 0.0f, -20.0f), CVector(), CVector(25.0f, 5.0f, 1.0f));
	new CRock2(&mRock, CVector(-14.0f, 0.0f, -20.0f), CVector(), CVector(9.0f, 5.0f, 1.5f));
	new CObj(&mCube, CVector(100.0f, 0.0f, -70.0f), CVector(), CVector(1.0f, 5.0f, 60.0f));
	new CRock2(&mRock, CVector(100.0f, 0.0f, -78.0f), CVector(), CVector(1.5f, 5.0f, 40.0f));
	new CObj(&mCube, CVector(40.0f, 0.0f, -120.0f), CVector(), CVector(80.0f, 5.0f, 1.0f));
	new CRock2(&mRock, CVector(40.0f, 0.0f, -120.0f), CVector(), CVector(80.0f, 5.0f, 1.5f));
	new CObj(&mCube, CVector(-30.0f, 0.0f, -70.0f), CVector(), CVector(1.0f, 5.0f, 60.0f));
	new CRock2(&mRock, CVector(-30.0f, 0.0f, -70.0f), CVector(), CVector(1.5f, 5.0f, 40.0f));

	new CObj(&mCube, CVector(15.0f, 0.0f, 0.0f), CVector(), CVector(1.0f, 5.0f, 20.0f));
	new CRock2(&mRock, CVector(15.0f, 0.0f, 0.0f), CVector(), CVector(1.5f, 5.0f, 13.0f));
	new CObj(&mCube, CVector(-5.0f, 0.0f, -10.0f), CVector(), CVector(1.0f, 5.0f, 10.0f));
	new CRock2(&mRock, CVector(-5.0f, 0.0f, -10.0f), CVector(), CVector(1.5f, 5.0f, 7.0f));

	new CObj(&mCube, CVector(-10.0f, 0.0f, 20.0f), CVector(), CVector(25.0f, 5.0f, 1.0f));
	new CRock2(&mRock, CVector(-8.0f, 0.0f, 20.0f), CVector(), CVector(18.0f,5.0f, 1.5f));
	new CObj(&mCube, CVector(-65.0f, 0.0f, 3.0f), CVector(0.0f, 3.0f, 0.0f), CVector(60.0f, 5.0f, 1.0f));
	new CRock2(&mRock, CVector(-70.0f, 0.0f, 3.0f), CVector(0.0f, 3.0f, 0.0f), CVector(50.0f, 5.0f, 1.5f));


	new CObj(&mCube, CVector(-120.0f, 0.0f, 50.0f), CVector(0.0f, 3.0f, 0.0f), CVector(1.0f, 5.0f, 45.0f));
	new CRock2(&mRock, CVector(-120.0f, 0.0f, 50.0f), CVector(0.0f, 3.0f, 0.0f), CVector(1.5f, 5.0f, 40.0f));




	new CObj(&mCube, CVector(112.0f, 0.0f, 45.0f), CVector(0.0f, 12.0f, 0.0f), CVector(1.0f, 5.0f, 60.0f));
	new CRock2(&mRock, CVector(112.0f, 0.0f, 45.0f), CVector(0.0f, 12.0f, 0.0f), CVector(1.5f, 5.0f, 45.0f));
	new CObj(&mCube, CVector(70.0f, 0.0f, 110.0f), CVector(0.0f, 15.0f, 0.0f), CVector(60.0f, 5.0f, 1.0f));
	new CRock2(&mRock, CVector(70.0f, 0.0f, 110.0f), CVector(0.0f, 15.0f, 0.0f), CVector(60.0f, 5.0f, 1.5f));
	new CObj(&mCube, CVector(-50.0f, 0.0f, 110.0f), CVector(0.0f, -15.0f, 0.0f), CVector(70.0f, 5.0f, 1.0f));
	new CRock2(&mRock, CVector(-50.0f, 0.0f, 110.0f), CVector(0.0f, -15.0f, 0.0f), CVector(70.0f, 5.0f, 1.5f));



	mPuddlePoint = new CPuddlePoint();
	
	
	//�L�����N�^�[�Ƀ��f����ݒ肷��

	mPlayer.Init(&CRes::sModelX);
	mPlayer.mPosition = CVector(0.0f, 0.0f, 80);
	
	mEye.mPosition.mY = 3.0f;
	//�e�L�X�g�t�H���g�̓ǂݍ��݂Ɛݒ�
	CText::mFont.Load("FontG.tga");
	CText::mFont.SetRowCol(1, 4096 / 64);

	

	Amount = new CAmount();

	mMap = new CMap();

	

}


void CSceneGame::Update() {


	if (Time > 0){
		Time--;
	}
	
	
	if (mEnd == false){
		CTaskManager::Get()->Update();

		//�Փˏ���
	}

	if (mEnd == true){
		if (CKey::Once(VK_RETURN)){
			mScene = ETITLE;
		}
	}
	//�L�����N�^�[�N���X�̍X�V
	

	
	CCollisionManager::Get()->Collision();

	mEye.mPosition.mX = mPlayer.mPosition.mX;
	mEye.mPosition.mZ = mPlayer.mPosition.mZ;
	
	//�J�����̃p�����[�^���쐬����
	CVector e, c, u;//���_�A�����_�A�����
	e =  CVector(0.0f, 5.0f, -10.0f)*mEye.mMatrix;

	c = mEye.mPosition + CVector(0.0f, 2.0f, 0.0f);

	//����������߂�
	u = CVector(0.0f, 1.0f, 0.0f)*mEye.mMatrixRotate;
	
	if (CKey::Push('M')){


		//���_�����߂�
		e = CVector(0.0f, 200.0f, -1.0f);
		//�����_�����߂�
		c = CVector();
		//����������߂�
		u = CVector(0.0f, 1.0f, 0.0f);
		//�J�����̐ݒ�
	}
	
	Camera3D(e.mX, e.mY, e.mZ, c.mX, c.mY, c.mZ, u.mX, u.mY, u.mZ);
	Camera.mEye = e;
	

	CTaskManager::Get()->Delete();
	CTaskManager::Get()->Render();

	//�R���C�_�̕`��
	CCollisionManager::Get()->Render();



	mSky.Render();
	
	//mEye.Render();


	//�e�N�X�`���e�X�g
	//CRes::sModelX.mMaterial[0]->mpTexture->DrawImage(-5, 5, -5,5, 0, 128, 128, 0);


	//2D�`��J�n
	Start2D(-400, 400, -300, 300);
	//CText::DrawString("SCORE", -350 , 250, 16, 16);
	if (mEnd != true){
		sprintf(buf, "%d", score);//�X�R�A
		CText::DrawString(buf, -350, 250, 16, 16);

		sprintf(buf, "%d", Time / 60);
		CText::DrawString(buf, 300, 250, 16, 16);
		CText::DrawString("COMBO", 210, -150, 20, 20);
		sprintf(buf, "%d", Combo);
		CText::DrawString(buf, 295, -200, 20, 20);

	}
	

	if (CPuddle::mclearcount == PUDDLE){

		CText::DrawString("GAME CLEAR", -150, 80, 20, 20);
		mEnd = true;
	}
	
	if (CXPlayer::mpxPlayer->mstate == CXPlayer::mpxPlayer->EDESU){
				CText::DrawString("GAME OVER", -150, 80, 20, 20);
				mEnd = true;
			}
	if (CPuddle::mclearcount == GAMEOVERA){
		CText::DrawString("GAME OVER", -150, 80, 20, 20);
		mEnd = true;
	}
	if (Time ==GAMEOVERA){
	CText::DrawString("GAME OVER", -150, 80, 20, 20);
	mEnd = true;
	}
	//�I������Ƃ��ɕ\���������
	if (mEnd == true){

		CText::DrawString("NUMBER OF DEFEATS", -350, 0, 15, 15);
		sprintf(buf, "%d", Defeats);
		CText::DrawString(buf, 300, 0, 15, 15);
		CText::DrawString("NUMBER OF COMBO", -350, -40, 15, 15);
		sprintf(buf, "%d", ComboMax);
		CText::DrawString(buf, 300, -40, 15, 15);
		CText::DrawString("SCORE", -350, -80, 15, 15);
		sprintf(buf, "%d", score);
		CText::DrawString(buf, 300, -80, 15, 15);

	}
	
	

	Amount->x = -350;
	Amount->y = -260 + Amount->h;
	Amount->h = CXPlayer::mpxPlayer->mWaterCount/ CXPlayer::mpxPlayer->mWaterCountMax * 100;
	Amount->w = 16;
	Amount->mEnabled = true;
	Amount->Render();

	//2D�`��I��
	End2D();

	return;

}

bool CSceneGame2::Countf = false;

int CSceneGame2::score = 0;
int CSceneGame2::Combo = 0;
int CSceneGame2::ComboMax = 0;
int CSceneGame2::Defeats = 0;
CModel CSceneGame2::mGun;
CModel CSceneGame2::mItem;


//�L�����N�^�̃C���X�^���X
//CXCharacter mPlayer;
CSceneGame2::~CSceneGame2() {
	delete[] CXEnemy::mPoint;
}

//���̃V�[���̎擾
CScene::EScene CSceneGame2::GetNextScene() {
	return mScene;
}

void CSceneGame2::Init() {

	mScene = EGAME2;

	frame = 0;
	Time = 360 * 60;

	mEnd = false;

	CXEnemy::mPointSize = 6;//�|�C���g���̐ݒ�
	CXEnemy::mPoint = new CPoint[CXEnemy::mPointSize];

	CXEnemy::mPoint[0].Set(CVector(30.0f, 5.0f, -70.0f), 5.0f);
	CXEnemy::mPoint[1].Set(CVector(95.0f, 5.0f, -110.0f), 5.0f);
	CXEnemy::mPoint[2].Set(CVector(95.0f, 5.0f, -30.0f), 5.0f);
	CXEnemy::mPoint[3].Set(CVector(30.0f, 5.0f, -30.0f), 5.0f);

	CXEnemy::mPoint[4].Set(CVector(-0.5f, 0.0f, -30.0f), 5.0f);
	CXEnemy::mPoint[5].Set(CVector(-0.5f, 0.0f, -90.0f), 5.0f);


	CXEnemy2::mPointSize = 6;//�|�C���g���̐ݒ�
	CXEnemy2::mPoint = new CPoint[CXEnemy2::mPointSize];

	CXEnemy2::mPoint[0].Set(CVector(-30.0f, 5.0f, 90.0f), 5.0f);
	CXEnemy2::mPoint[1].Set(CVector(95.0f, 5.0f, 90.0f), 5.0f);
	CXEnemy2::mPoint[2].Set(CVector(30.0f, 5.0f, 30.0f), 5.0f);
	CXEnemy2::mPoint[3].Set(CVector(95.0f, 5.0f, 30.0f), 5.0f);
	CXEnemy2::mPoint[4].Set(CVector(-60.0f, 0.0f, 30.0f), 5.0f);
	CXEnemy2::mPoint[5].Set(CVector(-80.0f, 0.0f, 90.0f), 5.0f);

	mRock.Load("Rock1.obj", "Rock1.mtl");

	mSky.Load("sky.obj", "sky.mtl");
	mCube.Load("Cube.obj", "Cube.mtl");
	Puddle.Load("sphere.obj", "sphere.mtl");
	MudPuddle.Load("sphere2.obj", "sphere2.mtl");
	mGun.Load("sphere.obj", "sphere.mtl");
	mBomb.Load("sphere.obj", "sphere.mtl");
	mWorkbench.Load("sphere.obj", "sphere.mtl");
	mItem.Load("Rock1.obj", "Rock1.mtl");
	TextureExp1->Load("exp.tga");

	mpPuddle = new CPuddle(&Puddle, &MudPuddle, CVector(-80.0f, 0.0f, 90.0f), CVector(), CVector(0.9f, 0.1f, 0.9f));

	if (mpPuddle->mpModel == &Puddle){

		CPuddle::mclearcount++;
	}

	mpPuddle = new CPuddle(&Puddle, &MudPuddle, CVector(80.0f, 0.0f, 90.0f), CVector(), CVector(0.9f, 0.1f, 0.9f));
	mpPuddle->mpModel = &MudPuddle;
	if (mpPuddle->mpModel == &Puddle){

		CPuddle::mclearcount++;
	}

	mpPuddle = new CPuddle(&Puddle, &MudPuddle, CVector(-60.0f, 0.0f, 30.0f), CVector(), CVector(0.9f, 0.1f, 0.9f));

	if (mpPuddle->mpModel == &Puddle){

		CPuddle::mclearcount++;
	}


	mpPuddle = new CPuddle(&Puddle, &MudPuddle, CVector(30.0f, 0.0f, 10.0f), CVector(), CVector(0.9f, 0.1f, 0.9f));

	if (mpPuddle->mpModel == &Puddle){

		CPuddle::mclearcount++;
	}


	mpPuddle = new CPuddle(&Puddle, &MudPuddle, CVector(-0.5f, 0.0f, -90.0f), CVector(), CVector(0.9f, 0.1f, 0.9f));

	mpPuddle->mpModel = &MudPuddle;
	if (mpPuddle->mpModel == &Puddle){

		CPuddle::mclearcount++;
	}



	mpPuddle = new CPuddle(&Puddle, &MudPuddle, CVector(70.0f, 0.0f, -50.0f), CVector(), CVector(0.9f, 0.1f, 0.9f));

	mpPuddle->mpModel = &MudPuddle;
	if (mpPuddle->mpModel == &Puddle){

		CPuddle::mclearcount++;
	}



	CRes::sModelX.Load(MODEL_FILE);
	CRes::sKnight.Load(MODEL_FILE2);
	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//1:�ړ�
	CRes::sKnight.SeparateAnimationSet(0, 1530, 1830, "idle1");//2:�ҋ@
	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//3:�_�~�[
	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//4:�_�~�[
	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//5:�_�~�[
	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//6�_�~�[
	CRes::sKnight.SeparateAnimationSet(0, 440, 520, "attack1");//7Attack1
	CRes::sKnight.SeparateAnimationSet(0, 520, 615, "attack2");//7Attack2
	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//9�_�~�[
	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//10�_�~�[
	CRes::sKnight.SeparateAnimationSet(0, 1160, 1260, "death1");//11:�_�E��

	//�󂹂��
	new CRock(&mRock, CVector(56.0f, 0.0f, -18.0f), CVector(), CVector(6.0f, 6.0f, 6.0f));

	new CRock(&mRock, CVector(-45.0f, 0.0f, 15.0f), CVector(), CVector(6.0f, 6.0f, 6.0f));

	//��
	new CObj(&mCube, CVector(85.0f, 0.0f, -20.0f), CVector(), CVector(20.0f, 5.0f, 1.0f));

	new CRock2(&mRock, CVector(85.0f, 0.0f, -20.0f), CVector(), CVector(13.0f, 5.0f, 1.5f));
	new CObj(&mCube, CVector(30.0f, 0.0f, -20.0f), CVector(), CVector(15.0f, 5.0f, 1.0f));
	new CRock2(&mRock, CVector(32.0f, 0.0f, -20.0f), CVector(), CVector(11.0f, 5.0f, 1.5f));
	new CObj(&mCube, CVector(65.0f, 0.0f, 5.0f), CVector(), CVector(1.0f, 5.0f, 25.0f));
	new CRock2(&mRock, CVector(65.0f, 0.0f, 5.0f), CVector(), CVector(1.5f, 5.0f, 15.0f));
	new CObj(&mCube, CVector(45.0f, 0.0f, 5.0f), CVector(), CVector(1.0f, 5.0f, 25.0f));
	new CRock2(&mRock, CVector(45.0f, 0.0f, 5.0f), CVector(), CVector(1.5f, 5.0f, 15.0f));
	new CObj(&mCube, CVector(-30.0f, 0.0f, -20.0f), CVector(), CVector(25.0f, 5.0f, 1.0f));
	new CRock2(&mRock, CVector(-14.0f, 0.0f, -20.0f), CVector(), CVector(9.0f, 5.0f, 1.5f));
	new CObj(&mCube, CVector(100.0f, 0.0f, -70.0f), CVector(), CVector(1.0f, 5.0f, 60.0f));
	new CRock2(&mRock, CVector(100.0f, 0.0f, -78.0f), CVector(), CVector(1.5f, 5.0f, 40.0f));
	new CObj(&mCube, CVector(40.0f, 0.0f, -120.0f), CVector(), CVector(80.0f, 5.0f, 1.0f));
	new CRock2(&mRock, CVector(40.0f, 0.0f, -120.0f), CVector(), CVector(80.0f, 5.0f, 1.5f));
	new CObj(&mCube, CVector(-30.0f, 0.0f, -70.0f), CVector(), CVector(1.0f, 5.0f, 60.0f));
	new CRock2(&mRock, CVector(-30.0f, 0.0f, -70.0f), CVector(), CVector(1.5f, 5.0f, 40.0f));

	new CObj(&mCube, CVector(15.0f, 0.0f, 0.0f), CVector(), CVector(1.0f, 5.0f, 20.0f));
	new CRock2(&mRock, CVector(15.0f, 0.0f, 0.0f), CVector(), CVector(1.5f, 5.0f, 13.0f));
	new CObj(&mCube, CVector(-5.0f, 0.0f, -10.0f), CVector(), CVector(1.0f, 5.0f, 10.0f));
	new CRock2(&mRock, CVector(-5.0f, 0.0f, -10.0f), CVector(), CVector(1.5f, 5.0f, 7.0f));

	new CObj(&mCube, CVector(-10.0f, 0.0f, 20.0f), CVector(), CVector(25.0f, 5.0f, 1.0f));
	new CRock2(&mRock, CVector(-8.0f, 0.0f, 20.0f), CVector(), CVector(18.0f, 5.0f, 1.5f));
	new CObj(&mCube, CVector(-65.0f, 0.0f, 3.0f), CVector(0.0f, 3.0f, 0.0f), CVector(60.0f, 5.0f, 1.0f));
	new CRock2(&mRock, CVector(-70.0f, 0.0f, 3.0f), CVector(0.0f, 3.0f, 0.0f), CVector(50.0f, 5.0f, 1.5f));


	new CObj(&mCube, CVector(-120.0f, 0.0f, 50.0f), CVector(0.0f, 3.0f, 0.0f), CVector(1.0f, 5.0f, 45.0f));
	new CRock2(&mRock, CVector(-120.0f, 0.0f, 50.0f), CVector(0.0f, 3.0f, 0.0f), CVector(1.5f, 5.0f, 40.0f));




	new CObj(&mCube, CVector(112.0f, 0.0f, 45.0f), CVector(0.0f, 12.0f, 0.0f), CVector(1.0f, 5.0f, 60.0f));
	new CRock2(&mRock, CVector(112.0f, 0.0f, 45.0f), CVector(0.0f, 12.0f, 0.0f), CVector(1.5f, 5.0f, 45.0f));
	new CObj(&mCube, CVector(70.0f, 0.0f, 110.0f), CVector(0.0f, 15.0f, 0.0f), CVector(60.0f, 5.0f, 1.0f));
	new CRock2(&mRock, CVector(70.0f, 0.0f, 110.0f), CVector(0.0f, 15.0f, 0.0f), CVector(60.0f, 5.0f, 1.5f));
	new CObj(&mCube, CVector(-50.0f, 0.0f, 110.0f), CVector(0.0f, -15.0f, 0.0f), CVector(70.0f, 5.0f, 1.0f));
	new CRock2(&mRock, CVector(-50.0f, 0.0f, 110.0f), CVector(0.0f, -15.0f, 0.0f), CVector(70.0f, 5.0f, 1.5f));

	


	mPuddlePoint = new CPuddlePoint();


	//�L�����N�^�[�Ƀ��f����ݒ肷��

	mPlayer.Init(&CRes::sModelX);
	mPlayer.mPosition = CVector(0.0f, 0.0f, 80);

	mEye.mPosition.mY = 3.0f;
	//�e�L�X�g�t�H���g�̓ǂݍ��݂Ɛݒ�
	CText::mFont.Load("FontG.tga");
	CText::mFont.SetRowCol(1, 4096 / 64);



	Amount = new CAmount();

	mMap = new CMap();



}


void CSceneGame2::Update() {



	if (Time > 0){
		Time--;
	}


	if (mEnd == false){
		CTaskManager::Get()->Update();

		//�Փˏ���
	}

	if (mEnd == true){
		if (CKey::Once(VK_RETURN)){
			mScene = ETITLE;
		}
	}
	//�L�����N�^�[�N���X�̍X�V



	CCollisionManager::Get()->Collision();

	mEye.mPosition.mX = mPlayer.mPosition.mX;
	mEye.mPosition.mZ = mPlayer.mPosition.mZ;

	//�J�����̃p�����[�^���쐬����
	CVector e, c, u;//���_�A�����_�A�����
	e = CVector(0.0f, 5.0f, -10.0f)*mEye.mMatrix;

	c = mEye.mPosition + CVector(0.0f, 2.0f, 0.0f);

	//����������߂�
	u = CVector(0.0f, 1.0f, 0.0f)*mEye.mMatrixRotate;

	if (CKey::Push('M')){


		//���_�����߂�
		e = CVector(0.0f, 200.0f, -1.0f);
		//�����_�����߂�
		c = CVector();
		//����������߂�
		u = CVector(0.0f, 1.0f, 0.0f);
		//�J�����̐ݒ�
	}

	Camera3D(e.mX, e.mY, e.mZ, c.mX, c.mY, c.mZ, u.mX, u.mY, u.mZ);
	Camera.mEye = e;


	CTaskManager::Get()->Delete();
	CTaskManager::Get()->Render();

	//�R���C�_�̕`��
	CCollisionManager::Get()->Render();



	mSky.Render();

	//mEye.Render();


	//�e�N�X�`���e�X�g
	//CRes::sModelX.mMaterial[0]->mpTexture->DrawImage(-5, 5, -5,5, 0, 128, 128, 0);


	//2D�`��J�n
	Start2D(-400, 400, -300, 300);
	//CText::DrawString("SCORE", -350 , 250, 16, 16);
	if (mEnd != true){
		sprintf(buf, "%d", score);//�X�R�A
		CText::DrawString(buf, -350, 250, 16, 16);

		sprintf(buf, "%d", Time / 60);
		CText::DrawString(buf, 300, 250, 16, 16);
		CText::DrawString("COMBO", 210, -150, 20, 20);
		sprintf(buf, "%d", Combo);
		CText::DrawString(buf, 295, -200, 20, 20);


	}


	if (CPuddle::mclearcount == PUDDLE){

		CText::DrawString("GAME CLEAR", -150, 80, 20, 20);
		mEnd = true;
	}

	if (CXPlayer::mpxPlayer->mstate == CXPlayer::mpxPlayer->EDESU){
		CText::DrawString("GAME OVER", -150, 80, 20, 20);
		mEnd = true;
	}
	if (CPuddle::mclearcount == GAMEOVERA){
		CText::DrawString("GAME OVER", -150, 80, 20, 20);
		mEnd = true;
	}
	if (Time == GAMEOVERA){
		CText::DrawString("GAME OVER", -150, 80, 20, 20);
		mEnd = true;
	}
	//�I������Ƃ��ɕ\���������
	if (mEnd == true){

		CText::DrawString("NUMBER OF DEFEATS", -350, 0, 15, 15);
		sprintf(buf, "%d", Defeats);
		CText::DrawString(buf, 300, 0, 15, 15);
		CText::DrawString("NUMBER OF COMBO", -350, -40, 15, 15);
		sprintf(buf, "%d", ComboMax);
		CText::DrawString(buf, 300, -40, 15, 15);
		CText::DrawString("SCORE", -350, -80, 15, 15);
		sprintf(buf, "%d", score);
		CText::DrawString(buf, 300, -80, 15, 15);

	}



	Amount->x = -350;
	Amount->y = -260 + Amount->h;
	Amount->h = CXPlayer::mpxPlayer->mWaterCount / CXPlayer::mpxPlayer->mWaterCountMax * 100;
	Amount->w = 16;
	Amount->mEnabled = true;
	Amount->Render();

	//2D�`��I��
	End2D();

	return;

}
