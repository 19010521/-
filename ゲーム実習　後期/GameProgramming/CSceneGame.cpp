
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
bool CSceneGame::mEnd = false;
CModel CSceneGame::mGun;
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

	mEnd = false;

	CXEnemy::mPointSize = 14;//�|�C���g���̐ݒ�
	CXEnemy::mPoint = new CPoint[CXEnemy::mPointSize];
	CXEnemy::mPoint[0].Set(CVector(55.0f, 5.0f, 45.0f), 5.0f);
	CXEnemy::mPoint[1].Set(CVector(55.0f, 5.0f, 75.0f), 5.0f);
	CXEnemy::mPoint[2].Set(CVector(10.0f, 5.0f, 85.0f), 5.0f);
	CXEnemy::mPoint[3].Set(CVector(-30.0f, 5.0f, 90.0f), 5.0f);
	CXEnemy::mPoint[4].Set(CVector(-115.0f, 5.0f, 75.0f), 5.0f);
	CXEnemy::mPoint[5].Set(CVector(-115.0f, 5.0f, 15.0f), 5.0f);
	CXEnemy::mPoint[6].Set(CVector(5.0f, 5.0f, 10.0f), 5.0f);
	CXEnemy::mPoint[7].Set(CVector(5.0f, 5.0f, -30.0f), 5.0f);
	CXEnemy::mPoint[8].Set(CVector(-20.0f, 5.0f, -30.0f), 5.0f);
	CXEnemy::mPoint[9].Set(CVector(-20.0f, 5.0f, -110.0f), 5.0f);
	CXEnemy::mPoint[10].Set(CVector(30.0f, 5.0f, -70.0f), 5.0f);
	CXEnemy::mPoint[11].Set(CVector(95.0f, 5.0f, -110.0f), 5.0f);
	CXEnemy::mPoint[12].Set(CVector(95.0f, 5.0f, -30.0f), 5.0f);
	CXEnemy::mPoint[13].Set(CVector(55.0f, 5.0f, -30.0f), 5.0f);
	
	//CXEnemy::mPoint[1].Set(CVector(30.0f, 5.0f, -3.0f), 10.0f);//�ד�
	//CXEnemy::mPoint[2].Set(CVector(-35.0f, 5.0f, 50.0f), 10.0f);
	//CXEnemy::mPoint[3].Set(CVector(3.0f, 5.0f, 6.0f), 10.0f);
	//mPlane.Load("plane.obj", "plane.mtl");

	mRock.Load("Rock1.obj", "Rock1.mtl");
	mPlane.Load("plane.obj", "plane.mtl");
	mSky.Load("sky.obj", "sky.mtl");
	mCube.Load("Cube.obj", "Cube.mtl");
	Puddle.Load("sphere.obj", "sphere.mtl");
	MudPuddle.Load("sphere2.obj", "sphere2.mtl");
	mGun.Load("sphere.obj", "sphere.mtl");

	mpPuddle = new CPuddle(&MudPuddle, CVector(30.0f, 0.0f, -5.0f), CVector(), CVector(0.9f, 0.1f, 0.9f));
	mpPuddle->mpModel = &Puddle;

	mpPuddle1 = new CPuddle1(&MudPuddle, CVector(-80.0f, 0.0f, 90.0f), CVector(), CVector(0.9f, 0.1f, 0.9f));
	mpPuddle1->mpModel = &Puddle;

	mpPuddle2 = new CPuddle2(&MudPuddle, CVector(-0.5f, 0.0f, -90.0f), CVector(), CVector(0.9f, 0.1f, 0.9f));
	mpPuddle2->mpModel = &Puddle;


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

	
	new CRock(&mRock, CVector(60.0f, 0.0f, -60.0f), CVector(), CVector(7.0f, 7.0f, 7.0f));
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

	//new CRock2(&mRock, CVector(-140.0f, 1.0f, 140.0f), CVector(), CVector(10.0f, 38.0f, 10.0f));
	//new CRock2(&mRock, CVector(-140.0f, 1.0f, -140.0f), CVector(), CVector(10.0f, 28.0f, 10.0f));
	//new CRock2(&mRock, CVector(140.0f, 1.0f, 140.0f), CVector(), CVector(10.0f, 38.0f, 10.0f));
	//new CRock2(&mRock, CVector(140.0f, 1.0f, -140.0f), CVector(), CVector(10.0f, 28.0f, 10.0f));

	//new CPuddle(&Puddle, CVector(-0.5f, 0.0f, -20.0f), CVector(), CVector(0.9f, 0.1f, 0.9f));
	//new CPuddle1(&Puddle, CVector(0.0f,0.0f,20.0f), CVector(), CVector(0.1f, 0.1f, 0.1f));
	//new CPuddle2(&Puddle, CVector(-0.5f,0.0f,50.0f), CVector(), CVector(0.1f, 0.1f, 0.1f));

	//�L�����N�^�[�Ƀ��f����ݒ肷��
	mPlayer.Init(&CRes::sModelX);
	mPlayer.mPosition = CVector(0.0f, 0.0f, -80);
	mEnemy = new CXEnemy();
	//�G�̏����ݒ�
	mEnemy->Init(&CRes::sKnight);

	//�G�̔z�u
	mEnemy->mAnimationFrameSize = 1024;
	mEnemy->mPosition = CVector(-10.0f, 0.0f, 55.0f);
	mEnemy->ChangeAnimation(2, true, 200);
	
	//�e�L�X�g�t�H���g�̓ǂݍ��݂Ɛݒ�
	CText::mFont.Load("FontG.tga");
	CText::mFont.SetRowCol(1, 4096 / 64);

	//new CEye(&mCube, CVector(0.0f, 0.0f, 0.0f), CVector(), CVector(0.0f, 0.0f, 0.0f));

	Amount = new CAmount();

	mMap = new CMap();

}


void CSceneGame::Update() {

	
	if (CPuddle::mPuddle->mPuddle0.mTag == CCollider::EMUDPUDDLE){
		mpPuddle->mpModel = &MudPuddle;
	}

	if (CPuddle1::mPuddle01->mPuddle1.mTag == CCollider::EMUDPUDDLE){
		mpPuddle1->mpModel = &MudPuddle;
	}

	if (CPuddle2::mPuddle02->mPuddle2.mTag == CCollider::EMUDPUDDLE){
		mpPuddle2->mpModel = &MudPuddle;
	}
	
	/*if (CXEnemy::mHPNow <= 50 && CXEnemy::Call == true){
		mEnemy1 = new CXEnemy1(&mCube, CVector(10.0f, 0.0f, 5.0f), CVector(), CVector(0.5f, 0.0f, 0.5f));
		mEnemy2 = new CXEnemy2(&mCube, CVector(CXPlayer::mpxPlayer->mPosition.mX + 10.0f, 0.0f, CXPlayer::mpxPlayer->mPosition.mZ + 5.0f), CVector(), CVector(0.5f, 0.0f, 0.5f));
	CXEnemy::Call = false;

	}*/

	//�����A�j���[�V�����ɐ؂�ւ���
	//mCharacter.ChangeAnimation(1, true, 60);
	//�A�j���[�V������؂�ւ���
	//if (mPlayer.mAnimationFrame >= mPlayer.mAnimationFrameSize){
	//	mPlayer.ChangeAnimation(mPlayer.mAnimationIndex + 1, true, 60);
	//}



	if (mEnd == false){
		TaskManager.Update();
		//�Փˏ���
	}

	if (mEnd == true){
		if (CKey::Once(VK_RETURN)){
			mScene = ETITLE;
		}
	}
	//�L�����N�^�[�N���X�̍X�V

	mEye.Update();
	//TaskManager.TaskCollision();
	CollisionManager.Collision();
	mEye.mPosition = mPlayer.mPosition;
	//�J�����̃p�����[�^���쐬����
	CVector e, c, u;//���_�A�����_�A�����
	e = CVector(0.0f, 5.0f, -10.0f)*mEye.mMatrix;

	c = mEye.mPosition;

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

	//�s��ݒ�
	//glMultMatrixf(Matrix.mF);

	//�ŏ��̃A�j���[�V�����̌��ݎ��Ԃ�45�ɂ���
	//CRes::sModelX.mAnimationSet[0]->mTime = 0;
	/*CRes::sModelX.mAnimationSet[0]->mTime += 1.0f;
	CRes::sModelX.mAnimationSet[0]->mTime =
	(int)CRes::sModelX.mAnimationSet[0]->mTime %
	(int)(CRes::sModelX.mAnimationSet[0]->mMaxTime + 1);*/
	//�ŏ��̃A�j���[�V�����̏d�݂�1.0(100%)�ɂ���
	//CRes::sModelX.mAnimationSet[0]->mWeight = 1.0f;
	//�t���[���̕ϊ��s����A�j���[�V�����ōX�V����
	//CRes::sModelX.AnimateFrame();
	//�t���[���̍����s��
	//CRes::sModelX.mFrame[0]->AnimateCombined(&Matrix);
	/*CRes::sModelX.AnimateVertex();*/
	//���f��
	//CRes::sModelX.Render();

	TaskManager.Delete();
	TaskManager.Render();

	//�R���C�_�̕`��
	CollisionManager.Render();



	mSky.Render();
	//mPlane.Render();
	//mEye.Render();


	//�e�N�X�`���e�X�g
	//CRes::sModelX.mMaterial[0]->mpTexture->DrawImage(-5, 5, -5,5, 0, 128, 128, 0);


	//2D�`��J�n
	Start2D(-400, 400, -300, 300);

	

	if (CXEnemy::Desuflag==true){
		if (mExplosinCount > 0){
			mExplosinCount--;
		}
		else{
			CText::DrawString("GAME CLEAR", -100, 0, 20, 20);
			mEnd = true;
		}
	}
	if (CXPlayer::mpxPlayer->mstate==CXPlayer::mpxPlayer->EDESU){
		if (DesuCount > 0){
			DesuCount--;
		}
		else
		{
			CText::DrawString("GAME OVER", -100, 0, 20, 20);
			mEnd = true;
		}
		

	}

	sprintf(buf, "%d", CXPlayer::mpxPlayer->mWaterCount);
	CText::DrawString(buf, -320, -180, 20, 20);

	Amount->x = -350 + Amount->w;
	Amount->y = -260;
	Amount->w = CXPlayer::mpxPlayer->mHPNow / CXPlayer::mpxPlayer->mHPMax * 100;
	Amount->h = 16;
	Amount->mEnabled = true;
	Amount->Render();



	//2D�`��I��
	End2D();

	return;

}

