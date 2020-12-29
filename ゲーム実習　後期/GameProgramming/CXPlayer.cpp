
#include"CXPlayer.h"
#include"CKey.h"
#include"CInput.h"
#include"CWaterGun.h"
#include"CXEnemy.h"
#include"CSceneGame.h"
#include"CBullet.h"
#include"CCollisionManager.h"
#include"CEye.h"
CXPlayer *CXPlayer::mpxPlayer = 0;
float CXPlayer::mHPMax = 100;
float CXPlayer::mHPNow = mHPMax;

#define G (9.8f/60.0f)//重力加速度
#define JUMPV0 (3.0f)//ジャンプ初速
#define MOUSE_SENSE 4

CXPlayer::CXPlayer()
:mColSphereBody(this, CVector(0.0f, 5.0f, 0.0f), CVector(), CVector(1.0f, 1.0f, 1.0f), 1.5f)
, mColSphereHead(this, CVector(0.0f, 0.5f, -3.0f), CVector(), CVector(1.0f, 1.0f, 1.0f), 0.5f)
, mColSphereSword(this, CVector(-10.0f, 10.0f, 50.0f), CVector(), CVector(1.0f, 1.0f, 1.0f), 0.3f)
, mColSphereLeg0(this, CVector(0.0f, 1.5f, 0.0f), CVector(), CVector(5.0f, 5.0f, 5.0f), 0.5f)
, mColSphereLeg1(this, CVector(0.0f, 1.5f, 0.0f), CVector(), CVector(5.0f, 5.0f, 5.0f), 0.5f)
, mVelovcityJump(0), BulletCount(0), BulletCountMax(60), WaterCount(0), WaterCountMax(3), InvincibleCount(150)
{
	Damege = false;

	jflag = false;

	waterflag = false;

	mpxPlayer = this;

	mScale = CVector(1.0f, 1.0f, 1.0f);
	//タグにプレイヤーを設定します
	mTag = EPLAYER;

	mstate = ENORMAL;
	//mColSphereSword.mTag = CCollider::ESWORD;
	mColSphereBody.mTag = CCollider::EPLAYEREBODY;


}
void CXPlayer::Init(CModelX*model){


	CXCharacter::Init(model);
	//合成行列
	mColSphereBody.mpCombinedMatrix =
		&mpCombinedMatrix[8];
	//合成行列
	mColSphereHead.mpCombinedMatrix =
		&mpCombinedMatrix[11];
	//合成行列
	mColSphereSword.mpCombinedMatrix =
		&mpCombinedMatrix[21];

	mColSphereLeg0.mpCombinedMatrix =
		&mpCombinedMatrix[25];

	mColSphereLeg1.mpCombinedMatrix =
		&mpCombinedMatrix[30];

}

void CXPlayer::TaskCollision()
{
	mColSphereBody.ChangePriority();
	mColSphereHead.ChangePriority();
	mColSphereLeg0.ChangePriority();
	CollisionManager.Collision(&mColSphereBody);
	CollisionManager.Collision(&mColSphereHead);
	CollisionManager.Collision(&mColSphereLeg0);
}

void CXPlayer::Update(){


	mVelovcityJump -= G;

	if (CKey::Once('Z')){
		for (int s = 0; s < 359; s++){
			CBullet*bullet = new CBullet();
			bullet->Set(0.1f, 1.5f);
			bullet->mPosition = CVector(0.0f, 0.0f, 10.0f)*CMatrix().RotateY(s)*mMatrix;
			bullet->mRotation = CVector(0.0f, s, 0.0f);
			//mFireCount = 60;
		}
	}

	if (mAnimationIndex != 11 && mstate == EMUD || mstate == EINVINCIBLE){
		if (CKey::Push('W') || CKey::Push('A') || CKey::Push('D') || CKey::Push('S')){

			mRotation.mY = CEye::mpthis->mRotation.mY;

			ChangeAnimation(1, true, 60);

			mPosition = CVector(0.0f, 0.0f, 0.07f)*mMatrix;

			if (CKey::Push('S')){

				mRotation.mY += 180;

				mPosition = CVector(0.0f, 0.0f, 0.07f)*mMatrix;
			}

			if (CKey::Push('A')){
				mRotation.mY += 90;
				mPosition = CVector(0.0f, 0.0f, 0.07f)*mMatrix;

				if (CKey::Push('S')){
					mRotation.mY += 225;
					mPosition = CVector(0.0f, 0.0f, 0.07f)*mMatrix;
				}

				if (CKey::Push('W')){
					mRotation.mY += 315;
					mPosition = CVector(0.0f, 0.0f, 0.07f)*mMatrix;
				}
			}

			if (CKey::Push('D')){
				mRotation.mY += 270;
				mPosition = CVector(0.0f, 0.0f, 0.07f)*mMatrix;
				if (CKey::Push('S')){
					mRotation.mY += 135;
					mPosition = CVector(0.0f, 0.0f, 0.07f)*mMatrix;
				}

				if (CKey::Push('W')){
					mRotation.mY += 45;
					mPosition = CVector(0.0f, 0.0f, 0.07f)*mMatrix;
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
	}

	if (mAnimationIndex != 11 && mstate == ENORMAL){
		if (CKey::Push('W') || CKey::Push('A') || CKey::Push('D') || CKey::Push('S')){

			mRotation.mY = CEye::mpthis->mRotation.mY;

			ChangeAnimation(1, true, 60);

			mPosition = CVector(0.0f, 0.0f, 0.1f)*mMatrix;

			if (CKey::Push('S')){
				mRotation.mY += 180;

				mPosition = CVector(0.0f, 0.0f, 0.1f)*mMatrix;
			}

			if (CKey::Push('A')){
				mRotation.mY += 90;
				mPosition = CVector(0.0f, 0.0f, 0.1f)*mMatrix;
				if (CKey::Push('S')){
					mRotation.mY += 225;
					mPosition = CVector(0.0f, 0.0f, 0.1f)*mMatrix;
				}
				if (CKey::Push('W')){
					mRotation.mY += 315;
					mPosition = CVector(0.0f, 0.0f, 0.1f)*mMatrix;
				}
			}

			if (CKey::Push('D')){
				mRotation.mY += 270;
				mPosition = CVector(0.0f, 0.0f, 0.1f)*mMatrix;
				if (CKey::Push('S')){
					mRotation.mY += 135;
					mPosition = CVector(0.0f, 0.0f, 0.1f)*mMatrix;
				}
				if (CKey::Push('W')){
					mRotation.mY += 45;
					mPosition = CVector(0.0f, 0.0f, 0.1f)*mMatrix;
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

		/*if (CInput::GetMouseButton(GLFW_MOUSE_BUTTON_LEFT)){

		if (mAnimationIndex == 0 || mAnimationIndex == 1){
		ChangeAnimation(3, false, 30);
		}
		}*/



		if (waterflag == true && WaterCount > 0){

			if (BulletCount > 0 && jflag == false){

				BulletCount--;
			}

			//マウスの右入力で弾発射
			else if (CInput::GetMouseButton(GLFW_MOUSE_BUTTON_RIGHT)){

				CWaterGun*bullet = new CWaterGun();
				bullet->Set(0.1f, 1.5f);
				bullet->mPosition = CVector(0.0f, 1.0f, 1.0f)*mMatrix;
				//bullet->mRotation = mRotation;
				bullet->mForward = bullet->mForward*mMatrixRotate;
				BulletCount = BulletCountMax;
				WaterCount -= 1;
				if (WaterCount <= 0){
					waterflag = false;
				}

			}
			//マウスの左入力で全弾発射
			else if (CInput::GetMouseButton(GLFW_MOUSE_BUTTON_LEFT)){


				CWaterGun*bullet = new CWaterGun();
				bullet->Set(0.1f, 1.5f);
				bullet->mPosition = CVector(0.0f, 1.0f, 1.0f)*mMatrix;
				//bullet->mRotation = mRotation;
				bullet->mForward = bullet->mForward*mMatrixRotate;
				BulletCount = BulletCountMax;


				waterflag = false;

				//bullet->mTag = CCharacter::;


				/*if (mAIM == true){
				mRotation.mX -= 20;
				mRotation.mY -= 20;
				}*/

			}
		}


	}
	////ジャンプ
	//if (jflag == false){
	//	mPosition.mY += mVelovcityJump;
	//	mVelovcityJump -= G;
	//}
	//if (jflag == true){
	//	mPosition.mY += mVelovcityJump;

	//}
	//else if (CKey::Once(VK_SPACE)){
	//	if (jflag == false && mstate == ENORMAL){
	//		mVelovcityJump = JUMPV0;
	//		mPosition.mY += mVelovcityJump;
	//		jflag = true;
	//	}
	//}

	if (mAnimationIndex == 11){
		mstate = EDESU;
	}

	if (mHPNow < 0){

		mHPNow = 0;
		ChangeAnimation(11, false, 30);

	}
	if (mstate == EINVINCIBLE){
		if (InvincibleCount>0){
			InvincibleCount--;

		}
		else
		{
			mstate = EMUD;
		}

	}


	if (Damege == true){

		mHPNow -= 20;
		
		Damege = false;
		
		mstate = EINVINCIBLE;
	}

	CXCharacter::Update();

}


void CXPlayer::Collision(CCollider*mc, CCollider*yc){

	//自身コライダの判定タイプ
	switch (mc->mType){
	case CCollider::ESPHERE://球コライダ
		//相手のコライダが三角コライダの時
		if (yc->mType == CCollider::ETRIANGLE){
			CVector adjust;//調整用ベクトル		
			if (CCollider::CollisionTriangleSphere(yc, mc, &adjust)){
				jflag = false;
				mVelovcityJump = 0;
				//位置の更新
				mPosition = mPosition - adjust*-1;
				//行列の更新
				CXCharacter::Update();
			}
		}
		break;
	}
	//共に球コライダの時
	if (mc->mType == CCollider::ESPHERE && yc->mType == CCollider::ESPHERE){
		//コライダのｍとｙが衝突しているか判定
		if (CCollider::Collision(mc, yc)){


			
				if (mstate != EMUD){
					if (waterflag == false){
						if (yc->mTag == CCollider::EPUDDLE0){
								//水をくむ
							if (CKey::Once('Q')){
								if (CPuddle::mPuddle->UseCount > 0){
									
									waterflag = true;
									WaterCount = WaterCountMax;
									CPuddle::mPuddle->UseCount--;
									
								}
							}
						}
							else if (yc->mTag == CCollider::EPUDDLE1){
							
									//水をくむ
									if (CKey::Once('Q')){
										if (CPuddle1::mPuddle01->UseCount > 0){
										waterflag = true;
										WaterCount = WaterCountMax;
										CPuddle1::mPuddle01->UseCount--;
									}
								}
							}
							else if (yc->mTag == CCollider::EPUDDLE2){
								
									//水をくむ
									if (CKey::Once('Q')){
										if (CPuddle2::mPuddle02->UseCount > 0){
										waterflag = true;
										WaterCount = WaterCountMax;
										CPuddle2::mPuddle02->UseCount--;
									}
								}
							}
				}
			}

			//衝突したコライダの親の種類を判定
			switch (yc->mpParent->mTag){
			case EENEMY:
				if (yc->mTag == CCollider::EENEMYBODY){
					if (mstate != EINVINCIBLE){
						if (CXEnemy::Attackflag == false){
							Damege = true;

							mstate = EMUD;

						}
					}
					break;
				}
			}
		}
	}
}