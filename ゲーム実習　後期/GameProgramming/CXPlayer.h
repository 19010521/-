#ifndef CXPLAYER_H
#define CXPLAYER_H


#include "CXCharacter.h"
#include "CCollider.h"
#include"CCamera.h"
#include"CEye.h"

class CXPlayer :public CXCharacter{
public:


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
	CEye mEye;

	static CXPlayer *mpxPlayer;

	void Init(CModelX*model);

	//�X�V����
	void Update();

	void TaskCollision();

	static float mHPMax;//�v���C���[��HP
	static float mHPNow;

	float mVelovcityJump;
	float mSpeed;
	int BulletCount;
	int BulletCountMax;
	int WaterCount;
	int WaterCountMax;
	int InvincibleCount;

	bool jflag;//�W�����v�t���O
	bool waterflag;//�����݃t���O
	bool Damege;//�_���[�W
	bool Damege2;//�_���[�W2

	

	void Collision(CCollider*mc, CCollider*yc);

};
#endif