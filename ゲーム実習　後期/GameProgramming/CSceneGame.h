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
�Q�[���̃V�[��
*/
class CSceneGame : public CScene {
public:

	char buf[10];

	CXPlayer mPlayer;
	//�G�̃C���X�^���X
	CXEnemy *mEnemy;
	CXEnemy1*mEnemy1;

	int mMouseX;
	int mMouseY;

	//��
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
	static int frame;//�t���[�����̃J�E���g
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
