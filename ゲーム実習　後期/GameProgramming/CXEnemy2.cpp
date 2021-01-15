#include"CXEnemy2.h"
#include"CRes.h"
#include"CXPlayer.h"
#include"CBullet.h"
#include<stdio.h>
#include<time.h>
//�U���|�C���g
bool CXEnemy2::Attackflag = true;
float CXEnemy2::mHPMax = 50;
float CXEnemy2::mHPNow = mHPMax;
#define G (9.8f/60.0f)//�d�͉����x
#define JUMPV0 (2.0f)//�W�����v����


CXEnemy2::CXEnemy2(CModel*model, CVector position, CVector rotation, CVector scale)
: mSearch2(this, CVector(0.0f, 0.0f, -5.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f, 1.0f, 1.0f), 4.0f)
, mColSphereBody(this, CVector(0.0f, 1.0f, 0.0f), CVector(), CVector(1.0f, 1.0f, 1.0f), 1.5f)
, mVelovcityJump(0), mnearCount(120), mnearCountMax(120), Randam(0), mCount(0), mCountMax(180), fCount(fCountMax), fCountMax(1000)
{

	mpModel = model;  //���f���̐ݒ�
	mPosition = position;//�ʒu�̐ݒ�
	mRotation = rotation;//��]�̐ݒ�
	mScale = scale;   //�g�k�̐ݒ�

	jflag = false;
	Attackflag = false;

	mflag = false;

	nflag = false;
	mScale = CVector(1.0f, 1.0f, 1.0f);

	mTag = EENEMY;
	mSearch.mTag = CCollider::ESEARCH;
	mSearch2.mTag = CCollider::ESEARCH2;

	mColSphereBody.mTag = CCollider::EENEMYBODY;
	mColSphereSword0.mTag = CCollider::ESWORD;
	//mstate = ENORMAL;

	mPointCnt = 0;//�ŏ��̃|�C���g��ݒ�
	//mpPoint = &mPoint[mPointCnt];//�ڎw���|�C���g�̃|�C���^��ݒ�


}

void CXEnemy2::Update(){

	//mVelovcityJump -= G;

	//srand((unsigned int)time(NULL));  //�悭�킩���

	if (mCount > 0){

		Attackflag = false;

	}

	//�ʒu���ړ�
	CVector dir = CXPlayer::mpxPlayer->mPosition - mPosition;

	CVector left = CVector(1.0f, 0.0f, 0.0f)  * CMatrix().RotateY(mRotation.mY);
	if (left.Dot(dir) > 0.0f){
		mRotation.mY -= 1.0f;
	}
	else if (left.Dot(dir) < 0.0f){
		mRotation.mY += 1.0f;
	}


	//�s����X�V
	CCharacter::Update();


	

}

void CXEnemy2::Init(CModelX*model){

}

void CXEnemy2::Collision(CCollider*m, CCollider*y){

	//���ɋ��R���C�_�̎�
	if (m->mType == CCollider::ESPHERE && y->mType == CCollider::ESPHERE){
		if (CCollider::Collision(m, y)){

			//�R���C�_���T�[�`������
			if (m->mTag == CCollider::ESEARCH2){
				//�Փ˂����R���C�_�̐e�̎�ނ𔻒�
				switch (y->mpParent->mTag){
				case EPLAYER:
					if (mCount > 0){
						mCount--;
					}
					else if (mHPNow > 0)
					{
						Attackflag = true;
						mCount = mCountMax;
					}

				}
			}
		}
		if (CCollider::Collision(m, y)){
			//����
			if (m->mTag == CCollider::EENEMYBODY){
				switch (y->mpParent->mTag){

				case EWATERGUN:

					if (y->mTag == CCollider::EWATER){
						mHPNow -= 20;


					}
					break;

				}
			}
		}
	}
	
}


