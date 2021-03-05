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
�Q�[���̃V�[��
*/
class CStage2 : public CSceneGame{
private:

	char buf[10];
	CXPlayer mPlayer;
	//�G�̃C���X�^���X
	CXEnemy *mEnemy;

	CAmount *Amount;

	CPuddlePoint *mPuddlePoint;

	int mMouseX;
	int mMouseY;
	int mExplosinCount = 30;
	//��
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


	int frame;//�t���[�����̃J�E���g

	int Time;

	bool mEnd;



	//�����������̃I�[�o�[���C�h
	void Init();
	//�X�V�����̃I�[�o�[���C�h
	void Update();

public:

	CStage2(){};
	~CStage2();

	//static CModel mGun;


	//static CModel mItem;

	static int score;//�X�R�A


	static bool Countf;


};
#endif