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

#define G (9.8f/60.0f)//�d�͉����x
#define JUMPV0 (2.0f)//�W�����v����


CXEnemy1::CXEnemy1(CModel*model, CVector position, CVector rotation, CVector scale)
: mSearch2(this, CVector(0.0f, 0.0f, -5.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f, 1.0f, 1.0f), 10.0f)
, mVelovcityJump(0), mnearCount(120), mnearCountMax(120), Randam(0), mCount(0), mCountMax(60 * 5), fCount(fCountMax), fCountMax(1000)
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
	mstate = ENORMAL;

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
	
	
	//�s����X�V
	CCharacter::Update();
	
	mPosition = CVector(0.0f, 0.0f, -0.5f)*mMatrix;
}

void CXEnemy1::Init(CModelX*model){
	
}

void CXEnemy1::Collision(CCollider*m, CCollider*y){


	////���ɋ��R���C�_�̎�
	//if (m->mType == CCollider::ESPHERE && y->mType == CCollider::ESPHERE){
	//	if (CCollider::Collision(m, y)){

	//		//�R���C�_���T�[�`������
	//		if (m->mTag == CCollider::ESEARCH){

	//			//�Փ˂����R���C�_�̐e�̎�ނ𔻒�
	//			switch (y->mpParent->mTag){
	//			case EPLAYER:

	//				//�ʒu���ړ�
	//				CVector dir = CXPlayer::mpxPlayer->mPosition - mPosition;

	//				CVector left = CVector(1.0f, 0.0f, 0.0f)  * CMatrix().RotateY(mRotation.mY);
	//				if (left.Dot(dir) > 0.0f){
	//					mRotation.mY -= 1.0f;
	//				}
	//				else if (left.Dot(dir) < 0.0f){
	//					mRotation.mY += 1.0f;
	//				}
	//				break;

	//			}
	//			//�v���C���[�̎�
	//			if (y->mTag == CCollider::EPLAYEREBODY){
	//				//�Փ˂��Ă��鎞�͖����ɂ���
	//				nflag = true;
	//			}

	//			else

	//			{
	//				nflag = false;
	//			}


	//		}
	//		//�R���C�_���T�[�`������
	//		else	if (m->mTag == CCollider::ESEARCH2){
	//			//�Փ˂����R���C�_�̐e�̎�ނ𔻒�

	//			switch (y->mpParent->mTag){
	//			case EPLAYER://�v���C���[�̎�

	//				if (mCount > 0){
	//					mCount--;
	//				}
	//				else if (mAnimationIndex != 11){

	//					if (mstate != ENORMAL){
	//						mstate = ENORMAL;
	//					}


	//					Randam = rand() % 3 + 1;
	//					switch (Randam)
	//					{
	//					case 1:
	//						mstate = EJUNP;
	//						mCount = mCountMax;
	//						break;
	//					case 2:
	//						//mstate = ENEAR;
	//						mCount = mCountMax;
	//						break;
	//					case 3:
	//						//mstate = EBACKFLIP;
	//						mCount = mCountMax;
	//						break;

	//					default:

	//						break;

	//					}
	//				}
	//			}

	//		}

	//		else{

	//			//�Փ˂����R���C�_�̐e�̎�ނ𔻒�
	//			switch (y->mpParent->mTag){
	//			case EPOINT://�|�C���g�̎�
	//				//�Փ˂����|�C���^�Ɩڎw���Ă���|�C���^�������Ƃ�
	//				if (y->mpParent == mpPoint){

	//					mPointCnt++;//���̃|�C���g�ɂ���
	//					//�Ōゾ������ŏ��ɂ���
	//					mPointCnt %= mPointSize;
	//					//���̂ۂ���Ƃ̃|�C���^��ݒ�
	//					mpPoint = &mPoint[mPointCnt];
	//				}

	//				break;

	//			}

	//		}
	//	}
	//	if (CCollider::Collision(m, y)){
	//		//����
	//		if (m->mTag == CCollider::EENEMYBODY){
	//			switch (y->mpParent->mTag){

	//			case EWATERGUN:

	//				if (y->mTag == CCollider::EWATER){
	//					ChangeAnimation(11, false, 30);

	//				}
	//				break;

	//			case EPLAYER:


	//				ChangeAnimation(7, false, 60);


	//			}
	//		}
	//	}
	//}
	////���g�R���C�_�̔���^�C�v
	//switch (m->mType){
	//case CCollider::ESPHERE://���R���C�_
	//	//����̃R���C�_���O�p�R���C�_�̎�
	//	if (m->mTag != CCollider::ESEARCH&&m->mTag != CCollider::ESEARCH2){
	//		if (y->mType == CCollider::ETRIANGLE){
	//			CVector adjust;//�����p�x�N�g��		

	//			if (CCollider::CollisionTriangleSphere(y, m, &adjust)){
	//				if (mstate == EJUNP){
	//					mstate = ELANDING;
	//					//mstate = ENORMAL;
	//				}
	//				jflag = false;
	//				lflag = false;


	//				mVelovcityJump = 0;
	//				//�ʒu�̍X�V
	//				mPosition = mPosition - adjust*-1;
	//				//�s��̍X�V
	//				CXCharacter::Update();
	//			}

	//		}
	//		break;
	//	}
	//}
}

