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
�Q�[���̃V�[��
*/
class CSceneGame : public CScene {
public:

	char buf[10];

	CXPlayer mPlayer;
	//�G�̃C���X�^���X
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
