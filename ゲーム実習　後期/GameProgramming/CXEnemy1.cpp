#include"CXEnemy1.h"
#include"CRes.h"
#include"CXPlayer.h"
#include"CBullet.h"
#include<stdio.h>
#include<time.h>
//�U���|�C���g
CPoint *CXEnemy1::mPoint = 0;
int CXEnemy1::mPointSize = 0;
bool CXEnemy1::Attackflag = true;

float CXEnemy1::mHPMax = 50;
float CXEnemy1::mHPNow = mHPMax;

#define G (9.8f/60.0f)//�d�͉����x
#define JUMPV0 (2.0f)//�W�����v����


CXEnemy1::CXEnemy1(CModel*model, CVector position, CVector rotation, CVector scale)
: mSearch2(this, CVector(0.0f, 0.0f, -5.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f, 1.0f, 1.0f), 4.0f)
, mColSphereBody(this, CVector(0.0f, 1.0f, 0.0f), CVector(), CVector(1.0f, 1.0f, 1.0f), 1.5f)
, mVelovcityJump(0), mnearCount(360), mnearCountMax(360), Randam(0), mCount(0), mCountMax(60 * 5), fCount(fCountMax), fCountMax(1000)
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
	mpPoint = &mPoint[mPointCnt];//�ڎw���|�C���g�̃|�C���^��ݒ�


}

void CXEnemy1::Update(){

	//mVelovcityJump -= G;

	//srand((unsigned int)time(NULL));  //�悭�킩���


	//�ʒu���ړ�
	CVector dir = CXPlayer::mpxPlayer->mPosition - mPosition;

	CVector left = CVector(1.0f, 0.0f, 0.0f)  * CMatrix().RotateY(mRotation.mY);
	if (left.Dot(dir) > 0.0f){
		mRotation.mY -= 1.0f;
	}
	else if (left.Dot(dir) < 0.0f){
		mRotation.mY += 1.0f;
	}

	//�~�܂�
	if (wflag == true){
		if (mnearCount > 0){
			mnearCount--;
		}
		else
		{
			wflag = false;
			mnearCount = mnearCountMax;
		}
	}
	
	//�s����X�V
	CCharacter::Update();
	if (wflag == true){
		mPosition = CVector(0.0f, 0.0f, 0.0f)*mMatrix;
	}
	else
	{
		mPosition = CVector(0.0f, 0.0f, -0.4f)*mMatrix;
	}
}

void CXEnemy1::Init(CModelX*model){
	
}

void CXEnemy1::Collision(CCollider*m, CCollider*y){


	//���ɋ��R���C�_�̎�
	if (m->mType == CCollider::ESPHERE && y->mType == CCollider::ESPHERE){
		if (CCollider::Collision(m, y)){

			//�R���C�_���T�[�`������
			if (m->mTag == CCollider::ESEARCH2){
				//�Փ˂����R���C�_�̐e�̎�ނ𔻒�
				switch (y->mpParent->mTag){
				case EPLAYER:
					wflag = true;

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

