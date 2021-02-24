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
#include"CWorkbench.h"


/*
�Q�[���̃V�[��
*/
class CSceneGame : public CScene {
public:

	char buf[10];

	CXPlayer mPlayer;
	//�G�̃C���X�^���X
	CXEnemy *mEnemy;
	
	CAmount *Amount;
	int mMouseX;
	int mMouseY;
	int mExplosinCount = 30;
	//��
	CCollider mCollider[14];


	CEye mEye;
	CMap *mMap;

	CModel mRock;
	CModel mCube;
	CModel mBomb;
	static CModel mGun;
	
	CModel Puddle;
	CModel MudPuddle;
	CModel mWorkbench;
	static CModel mItem;

	CPuddle *mpPuddle;
	
	EScene GetNextScene();

	int DesuCount=30;
	static int frame;//�t���[�����̃J�E���g
	static int score;//�X�R�A
	static int Time;

	static bool Countf;
	CSceneGame(){};
	~CSceneGame();
	static bool mEnd;
	//�����������̃I�[�o�[���C�h
	void Init();
	//�X�V�����̃I�[�o�[���C�h
	void Update();

};

#endif
