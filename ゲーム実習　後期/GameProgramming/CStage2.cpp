#include"CStage2.h"

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
#define  PUDDLE (4)
#define  CREATE (10)


//bool CStage2::Countf = false;
//int CStage2::score = 0;
//
////CModel CStage2::mGun;
////CModel CStage2::mItem;
//
////std::shared_ptr<CTexture>TextureExp1(new CTexture());
//
////�L�����N�^�̃C���X�^���X
////CXCharacter mPlayer;
//CStage2::~CStage2() {
//	delete[] CXEnemy::mPoint;
//}
//
////���̃V�[���̎擾
//CScene::EScene CStage2::GetNextScene() {
//	return mScene;
//}
//
//void CStage2::Init() {
//
//	mScene = EGAME2;
//
//	frame = 0;
//	Time = 60 * 60;
//
//	mEnd = false;
//
//	mRock.Load("Rock1.obj", "Rock1.mtl");
//
//	mSky.Load("sky.obj", "sky.mtl");
//	mCube.Load("Cube.obj", "Cube.mtl");
//	Puddle.Load("sphere.obj", "sphere.mtl");
//	MudPuddle.Load("sphere2.obj", "sphere2.mtl");
//	//mGun.Load("sphere.obj", "sphere.mtl");
//	mBomb.Load("sphere.obj", "sphere.mtl");
//	mWorkbench.Load("sphere.obj", "sphere.mtl");
//	//mItem.Load("Rock1.obj", "Rock1.mtl");
//
//	CRes::sModelX.Load(MODEL_FILE);
//	CRes::sKnight.Load(MODEL_FILE2);
//	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//1:�ړ�
//	CRes::sKnight.SeparateAnimationSet(0, 1530, 1830, "idle1");//2:�ҋ@
//	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//3:�_�~�[
//	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//4:�_�~�[
//	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//5:�_�~�[
//	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//6�_�~�[
//	CRes::sKnight.SeparateAnimationSet(0, 440, 520, "attack1");//7Attack1
//	CRes::sKnight.SeparateAnimationSet(0, 520, 615, "attack2");//7Attack2
//	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//9�_�~�[
//	CRes::sKnight.SeparateAnimationSet(0, 10, 80, "walk");//10�_�~�[
//	CRes::sKnight.SeparateAnimationSet(0, 1160, 1260, "death1");//11:�_�E��
//
//	mPlayer.Init(&CRes::sModelX);
//	mPlayer.mPosition = CVector(0.0f, 0.0f, -80);
//
//	mEye.mPosition.mY = 3.0f;
//
//	//�e�L�X�g�t�H���g�̓ǂݍ��݂Ɛݒ�
//	CText::mFont.Load("FontG.tga");
//	CText::mFont.SetRowCol(1, 4096 / 64);
//
//
//	mMap = new CMap();
//}
//
//void CStage2::Update() {
//
//
//	if (Time > 0){
//		Time--;
//	}
//
//
//	if (mEnd == false){
//		CTaskManager::Get()->Update();
//
//		//�Փˏ���
//	}
//
//	if (mEnd == true){
//		if (CKey::Once(VK_RETURN)){
//			mScene = ETITLE;
//		}
//	}
//	//�L�����N�^�[�N���X�̍X�V
//
//
//
//	CCollisionManager::Get()->Collision();
//
//	mEye.mPosition.mX = mPlayer.mPosition.mX;
//	mEye.mPosition.mZ = mPlayer.mPosition.mZ;
//
//	//�J�����̃p�����[�^���쐬����
//	CVector e, c, u;//���_�A�����_�A�����
//	e = CVector(0.0f, 5.0f, -10.0f)*mEye.mMatrix;
//
//	c = mEye.mPosition + CVector(0.0f, 2.0f, 0.0f);
//
//	//����������߂�
//	u = CVector(0.0f, 1.0f, 0.0f)*mEye.mMatrixRotate;
//
//	if (CKey::Push('M')){
//
//
//		//���_�����߂�
//		e = CVector(0.0f, 200.0f, -1.0f);
//		//�����_�����߂�
//		c = CVector();
//		//����������߂�
//		u = CVector(0.0f, 1.0f, 0.0f);
//		//�J�����̐ݒ�
//	}
//
//	Camera3D(e.mX, e.mY, e.mZ, c.mX, c.mY, c.mZ, u.mX, u.mY, u.mZ);
//	Camera.mEye = e;
//
//
//	CTaskManager::Get()->Delete();
//	CTaskManager::Get()->Render();
//
//	//�R���C�_�̕`��
//	CCollisionManager::Get()->Render();
//
//
//
//	mSky.Render();
//
//	//mEye.Render();
//
//
//	//�e�N�X�`���e�X�g
//	//CRes::sModelX.mMaterial[0]->mpTexture->DrawImage(-5, 5, -5,5, 0, 128, 128, 0);
//
//
//	//2D�`��J�n
//	Start2D(-400, 400, -300, 300);
//	//CText::DrawString("SCORE", -350 , 250, 16, 16);
//	sprintf(buf, "%d", score);//�X�R�A
//	CText::DrawString(buf, -350, 250, 16, 16);
//
//	sprintf(buf, "%d", Time / 60);
//	CText::DrawString(buf, 300, 250, 16, 16);
//
//
//	if (CXPlayer::mpxPlayer->touchflag == true){
//		//����ɕK�v�Ȑ���
//		CText::DrawString("THE NUMBER REQUIRED", -350, 0, 15, 15);
//		CText::DrawString("FOR PRODUCTION", -300, -40, 15, 15);
//		sprintf(buf, "%d", CXPlayer::mpxPlayer->mItem);
//		CText::DrawString(buf, 150, -40, 15, 15);
//		CText::DrawString("I", 190, -40, 15, 15);
//		sprintf(buf, "%d", CREATE);
//		CText::DrawString(buf, 230, -40, 15, 15);
//		CXPlayer::mpxPlayer->touchflag = false;
//	}
//
//	if (CPuddle::mclearcount == PUDDLE){
//
//		CText::DrawString("GAME CLEAR", -100, 0, 20, 20);
//		mEnd = true;
//	}
//
//	if (CXPlayer::mpxPlayer->mstate == CXPlayer::mpxPlayer->EDESU){
//		CText::DrawString("GAME OVER", -100, 0, 20, 20);
//		mEnd = true;
//	}
//	if (CPuddle::mclearcount == GAMEOVERA){
//		CText::DrawString("GAME OVER", -100, 0, 20, 20);
//		mEnd = true;
//	}
//	if (Time == GAMEOVERA){
//		CText::DrawString("GAME OVER", -100, 0, 20, 20);
//		mEnd = true;
//	}
//
//	/*sprintf(buf, "%d", CXPlayer::mpxPlayer->mBomb);
//	CText::DrawString(buf, -280, -180, 20, 20);*/
//
//	Amount->x = -350;
//	Amount->y = -260 + Amount->h;
//	Amount->h = CXPlayer::mpxPlayer->mWaterCount / CXPlayer::mpxPlayer->mWaterCountMax * 100;
//	Amount->w = 16;
//	Amount->mEnabled = true;
//	Amount->Render();
//
//	//2D�`��I��
//	End2D();
//
//	return;
//}