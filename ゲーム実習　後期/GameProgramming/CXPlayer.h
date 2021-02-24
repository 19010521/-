#ifndef CXPLAYER_H
#define CXPLAYER_H


#include "CXCharacter.h"
#include "CCollider.h"
#include"CCamera.h"


class CXPlayer :public CXCharacter{
public:
	CVector mTunRotation; //��
	float mTurn; //��]


	enum Estate
	{
		ENORMAL,//�m�[�}��

		EMUD,  //�D

		EDESU, //����

		EINVINCIBLE, //���G

	};
	Estate mstate;
	//�f�t�H���g�R���X�g���N�^
	CXPlayer();
	CMatrix Matrix;

	//�R���C�_�̐錾
	CCamera mCamera;
	CCollider mColSphereBody;   //��
	CCollider mColSphereHead;   //��
	CCollider mColSphereSword;  //��
	CCollider mColSphereLeg0;   //��
	CCollider mColSphereLeg1;   //��
	CCollider mSearch;
	CCollider mColBody;
	

	static CXPlayer *mpxPlayer;

	void Init(CModelX*model);

	//�X�V����
	void Update();

	void TaskCollision();
	static int mItem;
	static float mWaterCount;
	static float mWaterCountMax;
	
	int mHPNow;//�v���C���[��HP

	float mWaterCountStop;

	float mVelovcityJump;
	float mSpeed;
	int mBulletCount;
	int mBulletCountMax;
	int mClean_up;//���򉻃A�C�e��
	int mBomb;//���e�A�C�e��
	
	int mInvincibleCount;
	int mInvincibleCountMax;
	int mMudCount;
	int mDrawCount;//�`��J�E���g

	bool jflag;//�W�����v�t���O
	bool waterflag;//���łt���O
	bool Damege;//�_���[�W
	bool Damege2;//�_���[�W2

	bool touchflag;//�G���

	

	void Collision(CCollider*mc, CCollider*yc);
	void Render()override;


};
#endif