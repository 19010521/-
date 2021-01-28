#include"CXEnemy.h"
#include"CRes.h"
#include"CXPlayer.h"
#include"CBullet.h"
#include"CSceneGame.h"
#include<stdio.h>
#include<time.h>
//�U���|�C���g
CPoint *CXEnemy::mPoint = 0;
int CXEnemy::mPointSize = 0;
bool CXEnemy::Attackflag = true;
bool CXEnemy::Call = true;
bool CXEnemy::Desuflag = false;
#define G (9.8f/60.0f)//�d�͉����x
#define JUMPV0 (2.0f)//�W�����v����

CXEnemy::CXEnemy()
:mColSphereBody(this, CVector(0.5f, -1.0f, 0.0f), CVector(), CVector(1.0f, 2.0f, 1.0f), 1.5f)
, mColSphereHead(this, CVector(0.0f, 1.0f, 0.0f), CVector(), CVector(1.0f, 1.0f, 1.0f), 1.5f)
, mColSphereSword0(this, CVector(0.7f, 3.5f, -0.2f), CVector(), CVector(1.0f, 1.0f, 1.0f), 0.5f)
, mColSphereSword1(this, CVector(0.5f, 2.5f, -0.2f), CVector(), CVector(1.0f, 1.0f, 1.0f), 0.5f)
, mColSphereSword2(this, CVector(0.3f, 1.5f, -0.2f), CVector(), CVector(1.0f, 1.0f, 1.0f), 0.5f)
, mSearch(this, CVector(0.0f, 0.0f, -10.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f, 1.0f, 1.0f), 20.0f)
, mVelovcityJump(0), mnearCount(120), mnearCountMax(120), Randam(0), mCount(0), mCountMax(60 * 5), fCount(fCountMax), fCountMax(1000)
, mSpeed(0), mAttaccount(180), mAttaccountMax(180)
, mHPNow(0),mHPMax(1)
{
	jflag = false;
	Attackflag = false;
	
	mflag = false;

	nflag = false;
	
	aflag = false;
	
	//mScale = CVector(1.0f, 1.0f, 1.0f);
	mHPNow = mHPMax;
	mTag = EENEMY;
	mSearch.mTag = CCollider::ESEARCH;
	//mSearch2.mTag = CCollider::ESEARCH2;
	//mSearch3.mTag = CCollider::ESEARCH3;

	mColSphereBody.mTag = CCollider::EENEMYBODY;
	mColSphereSword0.mTag = CCollider::ESWORD;
	mstate = ENORMAL;

	mPointCnt = 0;//�ŏ��̃|�C���g��ݒ�
	mpPoint = &mPoint[mPointCnt];//�ڎw���|�C���g�̃|�C���^��ݒ�


}

void CXEnemy::Init(CModelX*model){
	CXCharacter::Init(model);
	//�����s��
	//M
	mColSphereBody.mpCombinedMatrix =
		&mpCombinedMatrix[1];
	//�����s��
	mColSphereHead.mpCombinedMatrix =
		&mpCombinedMatrix[1];
	//�����s��
	mColSphereSword0.mpCombinedMatrix =
		&mpCombinedMatrix[26];
	//�����s��
	mColSphereSword1.mpCombinedMatrix =
		&mpCombinedMatrix[26];
	//�����s��
	mColSphereSword2.mpCombinedMatrix =
		&mpCombinedMatrix[26];

}

void CXEnemy::Update(){

	mVelovcityJump -= G;

	srand((unsigned int)time(NULL));  //�悭�킩���

	if (mpPoint == 0){
		return;
	}


	
	
	if (mHPNow <= 0){
		ChangeAnimation(11, false, 30);
	}

	//����
	if (mAnimationIndex != 11 && mAnimationIndex != 7 && mAnimationFrame != 2){
		if (mstate == ENORMAL){
			if (nflag == false){
				ChangeAnimation(1, true, 60);

				//�|�C���g�ւ̃x�N�g�������߂�
				CVector dir = mpPoint->mPosition - mPosition;
				//�������̃x�N�g�������߂�
				CVector left = CVector(1.0f, 0.0f, 0.0f)*CMatrix().RotateY(mRotation.mY);
				mPosition = CVector(0.0f, 0.0f, -0.05f)*mMatrix;
				//CVector right = CVector(-1.0f, 0.0f, 0.0f) * CMatrix().RotateY(mRotation.mY);
				//������̃x�N�g�������߂�
				//CVector up = CVector(0.0f, 1.0f, 0.0f)*CMatrix().RotateX(mRotation.mX);
				//���E�̉�]����(Y��)

				if (left.Dot(dir) > 0.0f){
					mRotation.mY -= 1.0f;
				}
				else if (left.Dot(dir) < 0.0f){
					mRotation.mY += 1.0f;
				}
			}
		}
	}

	
	if (nflag == false){
		if (fCount>0){
			fCount--;

		}
		//�ҋ@
		else {
			mstate = EWAIT;
		}
		if (mstate == EWAIT){
			ChangeAnimation(2, false, 300);
			if (mAnimationFrame >= mAnimationFrameSize){
				fCount = fCountMax;
				mstate = ENORMAL;
			}
		}
	}
	//�W�����v
	if (jflag == false){
		mPosition.mY += mVelovcityJump;
		mVelovcityJump -= G;
	}


	if (jflag == true){
		mPosition.mY += mVelovcityJump;
		//mstate = ENORMAL;
	}

	else if (mstate == EJUNP){

		if (jflag == false){
			mVelovcityJump = JUMPV0;
			mPosition.mY += mVelovcityJump;
			jflag = true;
		}
	}
	
		
	//����--
	if (mAnimationIndex == 11){
		if (mAnimationFrame >= mAnimationFrameSize){
			CSceneGame::score += 50;
			mEnabled = false;
			
		}
	}

	if (mHPNow < 0){

		mHPNow = 0;
		ChangeAnimation(11, false, 30);

	}
	
	//�U��
	if (aflag == true){
		ChangeAnimation(7, false, 60);
		if (mAttaccount > 0){
			mAttaccount--;
		}
		else if (mAnimationIndex == 7){
				if (mAnimationFrame >= mAnimationFrameSize){
					aflag = false;
					Attackflag = true;
					ChangeAnimation(1, true, 60);
					mAttaccount = mAttaccountMax;
				}
				else
				{
					Attackflag = false;

				}
			}
		}
	
	if (mstate == ELANDING){
		for (int s = 0; s < 359; s++){
			CBullet*bullet = new CBullet();
			bullet->Set(0.1f, 1.5f);
			bullet->mPosition = CVector(0.0f, 0.0f, 10.0f)*CMatrix().RotateY(s)*mMatrix;
			bullet->mRotation = CVector(0.0f, s, 0.0f);
			mstate = ENORMAL;

		}
	}
	//�s����X�V
	CXCharacter::Update();
	if (mAnimationIndex != 11){
		if (mstate != ENEAR){
			if (mAnimationIndex == 2 || mAnimationIndex == 11){

				mPosition = CVector(0.0f, 0.0f, 0.0f)*mMatrix;
			}

		}
	}
}

void CXEnemy::Collision(CCollider*m, CCollider*y){


	//���ɋ��R���C�_�̎�
	if (m->mType == CCollider::ESPHERE && y->mType == CCollider::ESPHERE){
		if (CCollider::Collision(m, y)){

			//�R���C�_���T�[�`������
			if (m->mTag == CCollider::ESEARCH){
				//�Փ˂����R���C�_�̐e�̎�ނ𔻒�
				switch (y->mpParent->mTag){
				case EPLAYER:
					
					//�ʒu���ړ�
					CVector dir = CXPlayer::mpxPlayer->mPosition - mPosition;

					CVector left = CVector(1.0f, 0.0f, 0.0f)  * CMatrix().RotateY(mRotation.mY);
					if (left.Dot(dir) > 0.0f){
						mRotation.mY -= 1.0f;
					}
					else if (left.Dot(dir) < 0.0f){
						mRotation.mY += 1.0f;
					}
				
					break;
					
				}
				//�v���C���[�̎�
				if (y->mTag == CCollider::EPLAYEREBODY){
					//�Փ˂��Ă��鎞�͖����ɂ���
					//nflag = true;
				}

		

			}
			//�R���C�_���T�[�`������
			else	if (m->mTag == CCollider::ESEARCH2){
				//�Փ˂����R���C�_�̐e�̎�ނ𔻒�

				switch (y->mpParent->mTag){
				case EPLAYER://�v���C���[�̎�

					if (mCount > 0){
						mCount--;
					}
					else if (mAnimationIndex != 11){

						if (mstate != ENORMAL){
							mstate = ENORMAL;
						}


						Randam = rand() % 3 + 1;
						switch (Randam)
						{
						case 1:
						/*	mstate = EJUNP;
							mCount = mCountMax;
							break;*/
						case 2:
						/*	mstate = ENEAR;
							mCount = mCountMax;
							break;*/
						/*case 3:
							mstate = EBACKFLIP;
							mCount = mCountMax;
							break;*/

						default:

							break;

						}
					}
				}

			}
			else	if (m->mTag == CCollider::ESEARCH3){
				switch (y->mpParent->mTag){
				case EPLAYER://�v���C���[�̎�
					if (y->mTag == CCollider::EPLAYEREBODY){
					
					}
					break;
				}
			}
			else{
			
				//�Փ˂����R���C�_�̐e�̎�ނ𔻒�
				switch (y->mpParent->mTag){
				case EPOINT://�|�C���g�̎�
					//�Փ˂����|�C���^�Ɩڎw���Ă���|�C���^�������Ƃ�
					if (y->mpParent == mpPoint){

						mPointCnt++;//���̃|�C���g�ɂ���
						//�Ōゾ������ŏ��ɂ���
						mPointCnt %= mPointSize;
						//���̂ۂ���Ƃ̃|�C���^��ݒ�
						mpPoint = &mPoint[mPointCnt];
					}

					break;

				}

			}
		}
		if (CCollider::Collision(m, y)){

			//����
			if (m->mTag == CCollider::EENEMYBODY){
				
			
				
				switch (y->mpParent->mTag){

				case EWATERGUN:

					if (y->mTag == CCollider::EWATER){
						mHPNow -= 10;
					}
					break;

				case EPLAYER:

					if (aflag == false){
						aflag = true;
				}
					


				}
			}
			
		}
	}
	//���g�R���C�_�̔���^�C�v
	switch (m->mType){
	case CCollider::ESPHERE://���R���C�_
		//����̃R���C�_���O�p�R���C�_�̎�
		if (m->mTag != CCollider::ESEARCH&&m->mTag != CCollider::ESEARCH2&&m->mTag!=CCollider::ESEARCH3){
			if (y->mType == CCollider::ETRIANGLE){
				CVector adjust;//�����p�x�N�g��		

				if (CCollider::CollisionTriangleSphere(y, m, &adjust)){
					if (mstate == EJUNP&&jflag == true){
						mstate = ELANDING;
						
					}

					jflag = false;
					
					mVelovcityJump = 0;
					//�ʒu�̍X�V
					mPosition = mPosition - adjust*-1;
					//�s��̍X�V
					CXCharacter::Update();
				}

			}
			break;
		}
	}
}

