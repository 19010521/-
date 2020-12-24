#include"CXEnemy.h"
#include"CRes.h"
#include"CXPlayer.h"
#include"CBullet.h"
#include<stdio.h>
#include<time.h>
//�U���|�C���g
CPoint *CXEnemy::mPoint = 0;
int CXEnemy::mPointSize = 0;
bool CXEnemy::Attackflag = true;

#define G (9.8f/60.0f)//�d�͉����x
#define JUMPV0 (2.0f)//�W�����v����


CXEnemy::CXEnemy()
:mColSphereBody(this, CVector(0.5f, -1.0f, 0.0f), CVector(), CVector(1.0f, 2.0f, 1.0f), 1.5f)
, mColSphereHead(this, CVector(0.0f, 1.0f, 0.0f), CVector(), CVector(1.0f, 1.0f, 1.0f), 1.5f)
, mColSphereSword0(this, CVector(0.7f, 3.5f, -0.2f), CVector(), CVector(1.0f, 1.0f, 1.0f), 0.5f)
, mColSphereSword1(this, CVector(0.5f, 2.5f, -0.2f), CVector(), CVector(1.0f, 1.0f, 1.0f), 0.5f)
, mColSphereSword2(this, CVector(0.3f, 1.5f, -0.2f), CVector(), CVector(1.0f, 1.0f, 1.0f), 0.5f)
, mSearch(this, CVector(0.0f, 0.0f, -15.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f, 1.0f, 1.0f), 20.0f)
, mSearch2(this, CVector(0.0f, 0.0f, -5.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f, 1.0f, 1.0f), 10.0f)
, mVelovcityJump(0), mnearCount(120), mnearCountMax(120), Randam(0), mCount(0), mCountMax(60 * 5), fCount(fCountMax), fCountMax(1000)
{
	jflag = false;
	Attackflag = false;

	mflag = false;

	nflag = false;
	//mScale = CVector(1.0f, 1.0f, 1.0f);

	mTag = EENEMY;
	mSearch.mTag = CCollider::ESEARCH;
	mSearch2.mTag = CCollider::ESEARCH2;

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

	//����
	if (mAnimationIndex != 11 && mAnimationIndex != 7){
		if (mstate == ENORMAL){
			if (nflag == false){
				ChangeAnimation(1, true, 60);
				//�|�C���g�ւ̃x�N�g�������߂�
				CVector dir = mpPoint->mPosition - mPosition;
				//�������̃x�N�g�������߂�
				CVector left = CVector(1.0f, 0.0f, 0.0f)*CMatrix().RotateY(mRotation.mY);
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



	//��]
	if (lflag == false){

		mPosition.mY += mVelovcityJump;
		mVelovcityJump -= G;
	}

	if (lflag == true){
		mPosition.mY += mVelovcityJump;
		mPosition.mZ += 0.6f;
		mRotation.mX += 15.0f;
		if (mRotation.mX > 359){
			mstate = ENORMAL;
		}
		//mstate = ENORMAL;
	}

	else if (mstate == EBACKFLIP){

		ChangeAnimation(2, false, 90);

		if (mAnimationFrame >= mAnimationFrameSize){

			if (lflag == false){

				mVelovcityJump = JUMPV0;
				mPosition.mY += mVelovcityJump;
				lflag = true;
			}
		}
	}

	//�߂�����
	if (mstate == ENEAR){

		CVector dir = CXPlayer::mpxPlayer->mPosition - mPosition;

		CVector left = CVector(1.0f, 0.0f, 0.0f)  * CMatrix().RotateY(mRotation.mY);

		if (left.Dot(dir) > 0.0f){
			mRotation.mY -= 1.0f;
		}
		else if (left.Dot(dir) < 0.0f){
			mRotation.mY += 1.0f;
		}
	}

	if (mstate == ENEAR){

		if (mnearCount>0){
			mnearCount--;
		}
		else
		{
			mstate = ENORMAL;
			mnearCount = mnearCountMax;
		}
	}

	if (mAnimationIndex == 7){
		if (mAnimationFrame >= mAnimationFrameSize){
			Attackflag = false;
			ChangeAnimation(1, true, 60);
		}

		else
		{
			Attackflag = true;

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
		if (mAnimationIndex == 2){
			mPosition = CVector(0.0f, 0.0f, 0.0f)*mMatrix;

		}
		else{
			if (mstate != ENEAR){

				//�ʒu���ړ�
				mPosition = CVector(0.0f, 0.0f, -0.1f)*mMatrix;

			}
			else

			{
				mPosition = CVector(0.0f, 0.0f, -0.5f)*mMatrix;

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
					nflag = true;
				}

				else
				
				{
					nflag = false;
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
							mstate = EJUNP;
							mCount = mCountMax;
							break;
						case 2:
							//mstate = ENEAR;
							mCount = mCountMax;
							break;
						case 3:
							//mstate = EBACKFLIP;
							mCount = mCountMax;
							break;

						default:

							break;

						}
					}
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
						ChangeAnimation(11, false, 30);

					}
					break;

				case EPLAYER:


					ChangeAnimation(7, false, 60);


				}
			}
		}
	}
	//���g�R���C�_�̔���^�C�v
	switch (m->mType){
	case CCollider::ESPHERE://���R���C�_
		//����̃R���C�_���O�p�R���C�_�̎�
		if (m->mTag != CCollider::ESEARCH&&m->mTag != CCollider::ESEARCH2){
			if (y->mType == CCollider::ETRIANGLE){
				CVector adjust;//�����p�x�N�g��		

				if (CCollider::CollisionTriangleSphere(y, m, &adjust)){
					if (mstate == EJUNP){
						mstate = ELANDING;
						//mstate = ENORMAL;
					}
					jflag = false;
					lflag = false;


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

