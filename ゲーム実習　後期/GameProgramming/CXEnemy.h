#ifndef CXENEMY_H
#define CXENEMY_H

#include "CXCharacter.h"
#include"CCollider.h"
#include"CPoint.h"
#include"CItem.h"


class CXEnemy :public CXCharacter{
private:

	int Randam;
	
	void Update();
	CCollider mColSphereBody;//��

	CCollider mColSphereHead;   //��
	CCollider mColSphereSword0;  //��
	CCollider mColSphereSword1;  //��1
	CCollider mColSphereSword2;  //��2
	CCollider mColSphereLeg0;   //��
	CCollider mColSphereLeg1;   //��
	CCollider mSearch;

	float mVelovcityJump;
	float mSpeed;
	int mnearCount;
	int mnearCountMax;
	int mCount;
	int mCountMax;
	int fCount;
	int fCountMax;
	int mAttaccount;
	int mAttaccountMax;
	
	bool nflag;//�C�Â����t���O
	bool jflag;//�W�����v�t���O
	bool lflag;//��]�t���O
	bool aflag;//�U���t���O
	bool mflag;//�����t���O

	float mHPMax;//�G��HP
	float mHPNow;

	

	//�Փˏ���
	void Collision(CCollider*m, CCollider*y);

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

	CXEnemy();
	void Init(CModelX*model);

	static int mPointSize;//�|�C���g�̐�
	CPoint*mpPoint;//�ڎw���|�C���g
	int mPointCnt;//�|�C���g�̃J�E���^

	//�U���|�C���g
	static CPoint *mPoint;


	CItem *mItem;
	//CEnemy(���f��,�ʒu,��],�g�k)

	
	

	static bool Attackflag;
	static bool Call;//���Ԃ��Ă�
	static bool Desuflag;//���񂾃t���O
};

class CXEnemy2 :public CXCharacter{
private:

	int Randam;

	void Update();
	CCollider mColSphereBody;//��

	CCollider mColSphereHead;   //��
	CCollider mColSphereSword0;  //��
	CCollider mColSphereSword1;  //��1
	CCollider mColSphereSword2;  //��2
	CCollider mColSphereLeg0;   //��
	CCollider mColSphereLeg1;   //��
	CCollider mSearch;

	float mVelovcityJump;
	float mSpeed;
	int mnearCount;
	int mnearCountMax;
	int mCount;
	int mCountMax;
	int fCount;
	int fCountMax;
	int mAttaccount;
	int mAttaccountMax;
	
	bool nflag;//�C�Â����t���O
	bool jflag;//�W�����v�t���O
	bool lflag;//��]�t���O
	bool aflag;//�U���t���O
	bool mflag;//�����t���O

	float mHPMax;//�G��HP
	float mHPNow;



	//�Փˏ���
	void Collision(CCollider*m, CCollider*y);

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

	CXEnemy2();
	void Init(CModelX*model);

	static int mPointSize;//�|�C���g�̐�
	CPoint*mpPoint;//�ڎw���|�C���g
	int mPointCnt;//�|�C���g�̃J�E���^

	//�U���|�C���g
	static CPoint *mPoint;


	CItem *mItem;
	//CEnemy(���f��,�ʒu,��],�g�k)

	

	static bool Attackflag;
	static bool Call;//���Ԃ��Ă�
	static bool Desuflag;//���񂾃t���O
};
#endif
