#ifndef CXPLAYER_H
#define CXPLAYER_H


#include "CXCharacter.h"
#include "CCollider.h"
#include"CCamera.h"


class CXPlayer :public CXCharacter{
private:

	//�X�V����
	void Update();

	void TaskCollision();


	

	float mWaterCountStop;

	float mVelovcityJump;
	float mSpeed;
	int mBulletCount;
	int mBulletCountMax;

	int mComboCount;//�R���{�̃J�E���g
	int mComboCountMax;//�R���{�̃J�E���g�ő�

	int mComboMemory;//�R���{�L�������Ă���


	int mInvincibleCount;
	int mInvincibleCountMax;
	int mMudCount;
	int mDrawCount;//�`��J�E���g

	bool jflag;//�W�����v�t���O
	bool waterflag;//���łt���O
	
	
	

	CVector mTunRotation; //��
	float mTurn; //��]



	//�f�t�H���g�R���X�g���N�^

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






	void Collision(CCollider*mc, CCollider*yc);
	void Render()override;


public:

	enum Estate
	{
		ENORMAL,//�m�[�}��

		EMUD,  //�D

		EDESU, //����

		EINVINCIBLE, //���G

	};
	Estate mstate;

	static CXPlayer *mpxPlayer;

	static float mWaterCount;
	static float mWaterCountMax;
	

	CXPlayer();

	void Init(CModelX*model);




	int mClean_up;//���򉻃A�C�e��
	int mHPNow;//�v���C���[��HP

	bool touchflag;//�G���
	bool touchflag2;//�G���
	bool Comboflag;//�R���{�̎���
	bool Damege;//�_���[�W

};
#endif