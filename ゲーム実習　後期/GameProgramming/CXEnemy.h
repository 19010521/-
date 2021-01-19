#ifndef CXENEMY_H
#define CXENEMY_H

#include "CXCharacter.h"
#include"CCollider.h"
#include"CPoint.h"


class CXEnemy :public CXCharacter{
public:
	enum Estate
	{
		ENORMAL,//�ʏ�

		EWALK,//����

		ENEAR,//�߂���

		EATTACK1,//�ːi

		EJUNP,//�W�����v

		ELANDING,//���n

		EBACKFLIP,//��]

		EWAIT,//�ҋ@

		EDESU,//��
	};
	Estate mstate;


	static int mPointSize;//�|�C���g�̐�
	CPoint*mpPoint;//�ڎw���|�C���g
	int mPointCnt;//�|�C���g�̃J�E���^

	//�U���|�C���g
	static CPoint *mPoint;
	int Randam;
	//CEnemy(���f��,�ʒu,��],�g�k)

	CXEnemy();
	void Update();
	CCollider mColSphereBody;//��

	CCollider mColSphereHead;   //��
	CCollider mColSphereSword0;  //��
	CCollider mColSphereSword1;  //��1
	CCollider mColSphereSword2;  //��2
	CCollider mSearch;
	CCollider mSearch2;
	CCollider mSearch3;

	//CCollider mSearch2;
	float mVelovcityJump;
	int mnearCount;
	int mnearCountMax;
	int mCount;
	int mCountMax;
	int fCount;
	int fCountMax;
	bool nflag;//�C�Â����t���O
	bool jflag;//�W�����v�t���O
	bool lflag;//��]�t���O
	
	bool mflag;//�����t���O
	static float mHPMax;//�G��HP
	static float mHPNow;

	static bool Attackflag;
	static bool Call;//���Ԃ��Ă�
	static bool Desuflag;//���񂾃t���O
	void Init(CModelX*model);
	//�Փˏ���
	void Collision(CCollider*m, CCollider*y);
};
#endif
