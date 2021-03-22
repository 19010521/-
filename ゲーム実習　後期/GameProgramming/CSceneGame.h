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
�Q�[���̃V�[��
*/
class CSceneGame : public CScene {
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

	CSceneGame(){};
	~CSceneGame();

	static CModel mGun;
	
	static CModel mItem;

	static int Combo;//�R���{

	static int ComboMax;//�R���{�ő�

	static int score;//�X�R�A

	static int Defeats;//���j��
    

	static bool Countf;
	
	
	
};
/*
�Q�[���̃V�[��
*/
class CSceneGame2 : public CScene {
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

	CSceneGame2(){};
	~CSceneGame2();

	static CModel mGun;

	static CModel mItem;

	static int Combo;//�R���{

	static int ComboMax;//�R���{�ő�

	static int score;//�X�R�A

	static int Defeats;//���j��


	static bool Countf;



};


#endif
