#include"CXPlayer.h"
#include"CKey.h"
#include"CInput.h"
#include"CWaterGun.h"
#include"CXEnemy.h"
#include"CSceneGame.h"
#include"CBullet.h"

#include"CCollisionManager.h"

CXPlayer *CXPlayer::mpxPlayer = nullptr;



float CXPlayer::mWaterCountMax = 60;
float CXPlayer::mWaterCount = 0;



#define G (9.8f/60.0f)//�d�͉����x
#define JUMPV0 (2.0f)//�W�����v����
#define SPEED_DOWN (0.03f)
#define MOUSE_SENSE 4
#define TURN (-360.0f/60*3)//��]
#define WATERUSE (20.0f) //���̏����
#define CREATE (2)//����
#define CREATE2 (1)//�{��
CXPlayer::CXPlayer()
:mColSphereBody(this, CVector(0.0f, 3.0f, 0.0f), CVector(), CVector(1.0f, 1.0f, 1.0f), 1.8f)
, mColSphereHead(this, CVector(0.0f, 0.5f, -3.0f), CVector(), CVector(1.0f, 1.0f, 1.0f), 0.5f)
, mColSphereSword(this, CVector(-10.0f, 10.0f, 50.0f), CVector(), CVector(1.0f, 1.0f, 1.0f), 0.3f)
, mVelovcityJump(0), mBulletCount(0), mBulletCountMax(60), mWaterCountStop(0)
, mInvincibleCountMax(150), mInvincibleCount(150), mTunRotation(0.0f,2.5f,0.0f)
, mMudCount(0), mDrawCount(0), mHPNow(100)
, mSpeed(0), mClean_up(1), mComboCount(120), mComboMemory(0), mComboCountMax(120)
{
	Damege = false;

	jflag = false;

	waterflag = false;

	mpxPlayer = this;

	

	touchflag = false;

	mScale = CVector(1.0f, 1.0f, 1.0f);
	//�^�O�Ƀv���C���[��ݒ肵�܂�
	mTag = EPLAYER;

	mstate = ENORMAL;
	//mColSphereSword.mTag = CCollider::ESWORD;
	mColSphereBody.mTag = CCollider::EPLAYEREBODY;


}
void CXPlayer::Init(CModelX*model){


	CXCharacter::Init(model);
	//�����s��
	mColSphereBody.mpCombinedMatrix =
		&mpCombinedMatrix[8];
	//�����s��
	mColSphereHead.mpCombinedMatrix =
		&mpCombinedMatrix[11];
	//�����s��
	mColSphereSword.mpCombinedMatrix =
		&mpCombinedMatrix[21];

	

}

void CXPlayer::TaskCollision()
{
	mColSphereBody.ChangePriority();
	mColSphereHead.ChangePriority();

	CCollisionManager::Get()->Collision(&mColSphereBody);
	CCollisionManager::Get()->Collision(&mColSphereHead);
	

}


void CXPlayer::Update(){




	mVelovcityJump -= G;

	
		

		if (mAnimationIndex != 11){
		
			if (CKey::Push('W') || CKey::Push('A') || CKey::Push('D') || CKey::Push('S')){


				mRotation.mY = CEye::mpthis->mRotation.mY;

				ChangeAnimation(1, true, 60);

				mPosition = CVector(0.0f, 0.0f, 0.3f - mSpeed)*mMatrix;

				if (CKey::Push('S')){
					mRotation.mY += 180;

					mPosition = CVector(0.0f, 0.0f, 0.3f - mSpeed)*mMatrix;
				}

				if (CKey::Push('A')){
					mRotation.mY += 90;
					mPosition = CVector(0.0f, 0.0f, 0.3f - mSpeed)*mMatrix;
					if (CKey::Push('S')){
						mRotation.mY += 225;
						mPosition = CVector(0.0f, 0.0f, 0.3f - mSpeed)*mMatrix;
					}
					if (CKey::Push('W')){
						mRotation.mY += 315;
						mPosition = CVector(0.0f, 0.0f, 0.3f - mSpeed)*mMatrix;
					}
				}

				if (CKey::Push('D')){
					mRotation.mY += 270;
					mPosition = CVector(0.0f, 0.0f, 0.3f - mSpeed)*mMatrix;
					if (CKey::Push('S')){
						mRotation.mY += 135;
						mPosition = CVector(0.0f, 0.0f, 0.3f - mSpeed)*mMatrix;
					}
					if (CKey::Push('W')){
						mRotation.mY += 45;
						mPosition = CVector(0.0f, 0.0f, 0.3f - mSpeed)*mMatrix;
					}
				}

			}
			else if (mAnimationIndex == 1){
				ChangeAnimation(0, true, 60);
			}

			if (mAnimationIndex == 3){
				if (mAnimationFrame >= mAnimationFrameSize){
					ChangeAnimation(4, false, 30);
				}
			}
			if (mAnimationIndex == 4){
				if (mAnimationFrame >= mAnimationFrameSize){
					ChangeAnimation(0, true, 60);
				}
			}

			



			if (mWaterCount > WATERUSE){

				if (mBulletCount > 0 && jflag == false){

					mBulletCount--;
				}

				//�}�E�X�̉E���͂Œe����
				else if (CInput::GetMouseButton(GLFW_MOUSE_BUTTON_RIGHT)){
					mWaterCountStop = mWaterCount;
					waterflag = true;
					CWaterGun*bullet = new CWaterGun();
					bullet->Set(0.1f, 1.5f);
					bullet->mPosition = CVector(0.0f, 5.0f, 1.0f)*mMatrix;
					
					bullet->mForward = bullet->mForward*mMatrixRotate;
					mBulletCount = mBulletCountMax;

					mSpeed -= SPEED_DOWN;

				}
			
			}
			
		}

		if (waterflag == true){
			if (mWaterCount > mWaterCountStop - WATERUSE){
				mWaterCount--;
			}
			else
			{
				waterflag = false;
			}
		}


		//�W�����v
		if (jflag == false){
			mPosition.mY += mVelovcityJump;
			mVelovcityJump -= G;
		}
		if (jflag == true){

			mPosition.mY += mVelovcityJump;
			mTurn -= TURN;
			mVelovcityJump -= G;

		}
		else if (CKey::Once(VK_SPACE)){
			if (jflag == false && mstate == ENORMAL){
				mVelovcityJump = JUMPV0;
				mPosition.mY += mVelovcityJump;
				//mPosition = CVector(0.0f, 0.0f, 0.5f)*mMatrix;
				jflag = true;
				mTurn = TURN;
			}
		}
	

		//���G���
		if (mstate == EINVINCIBLE){
			if (mInvincibleCount>0){
				mInvincibleCount--;

			}
			/*else if (mMudCount < 3)
			{
				mstate = ENORMAL;
				mInvincibleCount = mInvincibleCountMax;
				
			}*/
			else
			{
				mstate = ENORMAL;
				mInvincibleCount = mInvincibleCountMax;
				
			}

		}

		//�R���{
		if (Comboflag == true){
			if (mComboCount > 0){
				mComboCount--;
			}

			else{
				mComboMemory = CSceneGame::Combo;
				if (mComboMemory > CSceneGame::ComboMax){
					CSceneGame::ComboMax = mComboMemory;
				}
				CSceneGame::Combo = 0;
				mComboCount =  mComboCountMax;
				Comboflag = false;
			}

		}
		
		////�D��ԂɂȂ�
		//if (mMudCount > 3){
		//	mstate = EMUD;
		//}


		//�_���[�W1
		if (Damege == true){
			Damege = false;
			mHPNow -= 20;
			mMudCount += 1;
			mstate = EINVINCIBLE;
			
		}
	
		//����--
	
		if (mHPNow < 0){
			mstate = EDESU;
			ChangeAnimation(11, false, 30);
			mHPNow = 0;
		
		}
		CCharacter::Update();
		CMatrix turnMatrix;
		if (jflag == true){
			CMatrix a, b, c;
			a.Translate(-mTunRotation.mX, -mTunRotation.mY, -mTunRotation.mZ);
			b.RotateX(mTurn);
			c.Translate(mTunRotation.mX, mTunRotation.mY, mTunRotation.mZ);
			turnMatrix = a*b*c;
		}

		CXCharacter::Update(turnMatrix*mMatrix);

}

void CXPlayer::Collision(CCollider*mc, CCollider*yc){

	//���g�R���C�_�̔���^�C�v
	switch (mc->mType){
	case CCollider::ESPHERE://���R���C�_
		//����̃R���C�_���O�p�R���C�_�̎�
		if (yc->mType == CCollider::ETRIANGLE){
			CVector adjust;//�����p�x�N�g��		
			if (CCollider::CollisionTriangleSphere(yc, mc, &adjust)){
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


	if (mc->mType == CCollider::ESPHERE && yc->mType == CCollider::ESPHERE){
		//�R���C�_�̂��Ƃ����Փ˂��Ă��邩����
		if (CCollider::Collision(mc, yc)){
			//�G�̏o������
			if (yc->mTag == CCollider::ESEARCHENEMY ){
				if (mc->mTag == CCollider::EPLAYEREBODY){
					CPuddle::Enemy = true;
				}
			}
			if ( yc->mTag == CCollider::ESEARCHENEMY2){
				if (mc->mTag == CCollider::EPLAYEREBODY){
					CPuddle::Enemy2 = true;
				}

			}
			if (Damege == false){
				if (mstate != EINVINCIBLE){
					if (yc->mTag == CCollider::EMUDPUDDLE){
						CXPlayer::mpxPlayer->Damege = true;
					}
				}
			}
		}
	}
	//���ɋ��R���C�_�̎�
	if (mc->mType == CCollider::ESPHERE && yc->mType == CCollider::ESPHERE){
		//�R���C�_�̂��Ƃ����Փ˂��Ă��邩����
		if (CCollider::Collision(mc, yc)){


			//�Փ˂����R���C�_�̐e�̎�ނ𔻒�
			switch (yc->mpParent->mTag){
				//�G
			case EENEMY:
				if (Damege == false){
					if (mstate != EINVINCIBLE){
						if (yc->mTag == CCollider::EENEMYBODY){
							if (mAnimationIndex != 11){
								if (CXEnemy::Attackflag == true || CXEnemy2::Attackflag == true){
									Damege = true;

								}
							}
						}

					}
				}
				break;
			
			}
		}
	}
}
void CXPlayer::Render(){
	//���_���A�j���[�V������K������
	//mpModel->AnimateVertex(mpCombinedMatrix);
	//mpModel->Render();

	if (mstate == EINVINCIBLE){
		if (mDrawCount % 8 == 0){
			mpModel->RenderShader(mpCombinedMatrix);
		}
		++mDrawCount;
	}
	else
	{
		mpModel->RenderShader(mpCombinedMatrix);
	}
}
