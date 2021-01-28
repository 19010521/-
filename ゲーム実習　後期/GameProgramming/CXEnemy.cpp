#include"CXEnemy.h"
#include"CRes.h"
#include"CXPlayer.h"
#include"CBullet.h"
#include"CSceneGame.h"
#include<stdio.h>
#include<time.h>
//誘導ポイント
CPoint *CXEnemy::mPoint = 0;
int CXEnemy::mPointSize = 0;
bool CXEnemy::Attackflag = true;
bool CXEnemy::Call = true;
bool CXEnemy::Desuflag = false;
#define G (9.8f/60.0f)//重力加速度
#define JUMPV0 (2.0f)//ジャンプ初速

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

	mPointCnt = 0;//最初のポイントを設定
	mpPoint = &mPoint[mPointCnt];//目指すポイントのポインタを設定


}

void CXEnemy::Init(CModelX*model){
	CXCharacter::Init(model);
	//合成行列
	//M
	mColSphereBody.mpCombinedMatrix =
		&mpCombinedMatrix[1];
	//合成行列
	mColSphereHead.mpCombinedMatrix =
		&mpCombinedMatrix[1];
	//合成行列
	mColSphereSword0.mpCombinedMatrix =
		&mpCombinedMatrix[26];
	//合成行列
	mColSphereSword1.mpCombinedMatrix =
		&mpCombinedMatrix[26];
	//合成行列
	mColSphereSword2.mpCombinedMatrix =
		&mpCombinedMatrix[26];

}

void CXEnemy::Update(){

	mVelovcityJump -= G;

	srand((unsigned int)time(NULL));  //よくわからん

	if (mpPoint == 0){
		return;
	}


	
	
	if (mHPNow <= 0){
		ChangeAnimation(11, false, 30);
	}

	//歩く
	if (mAnimationIndex != 11 && mAnimationIndex != 7 && mAnimationFrame != 2){
		if (mstate == ENORMAL){
			if (nflag == false){
				ChangeAnimation(1, true, 60);

				//ポイントへのベクトルを求める
				CVector dir = mpPoint->mPosition - mPosition;
				//左方向のベクトルを求める
				CVector left = CVector(1.0f, 0.0f, 0.0f)*CMatrix().RotateY(mRotation.mY);
				mPosition = CVector(0.0f, 0.0f, -0.05f)*mMatrix;
				//CVector right = CVector(-1.0f, 0.0f, 0.0f) * CMatrix().RotateY(mRotation.mY);
				//上方向のベクトルを求める
				//CVector up = CVector(0.0f, 1.0f, 0.0f)*CMatrix().RotateX(mRotation.mX);
				//左右の回転処理(Y軸)

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
		//待機
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
	//ジャンプ
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
	
		
	//死んだ--
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
	
	//攻撃
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
	//行列を更新
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


	//共に球コライダの時
	if (m->mType == CCollider::ESPHERE && y->mType == CCollider::ESPHERE){
		if (CCollider::Collision(m, y)){

			//コライダがサーチか判定
			if (m->mTag == CCollider::ESEARCH){
				//衝突したコライダの親の種類を判定
				switch (y->mpParent->mTag){
				case EPLAYER:
					
					//位置を移動
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
				//プレイヤーの時
				if (y->mTag == CCollider::EPLAYEREBODY){
					//衝突している時は無効にする
					//nflag = true;
				}

		

			}
			//コライダがサーチか判定
			else	if (m->mTag == CCollider::ESEARCH2){
				//衝突したコライダの親の種類を判定

				switch (y->mpParent->mTag){
				case EPLAYER://プレイヤーの時

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
				case EPLAYER://プレイヤーの時
					if (y->mTag == CCollider::EPLAYEREBODY){
					
					}
					break;
				}
			}
			else{
			
				//衝突したコライダの親の種類を判定
				switch (y->mpParent->mTag){
				case EPOINT://ポイントの時
					//衝突したポインタと目指しているポインタが同じとき
					if (y->mpParent == mpPoint){

						mPointCnt++;//次のポイントにする
						//最後だったら最初にする
						mPointCnt %= mPointSize;
						//次のぽいんとのポインタを設定
						mpPoint = &mPoint[mPointCnt];
					}

					break;

				}

			}
		}
		if (CCollider::Collision(m, y)){

			//判定
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
	//自身コライダの判定タイプ
	switch (m->mType){
	case CCollider::ESPHERE://球コライダ
		//相手のコライダが三角コライダの時
		if (m->mTag != CCollider::ESEARCH&&m->mTag != CCollider::ESEARCH2&&m->mTag!=CCollider::ESEARCH3){
			if (y->mType == CCollider::ETRIANGLE){
				CVector adjust;//調整用ベクトル		

				if (CCollider::CollisionTriangleSphere(y, m, &adjust)){
					if (mstate == EJUNP&&jflag == true){
						mstate = ELANDING;
						
					}

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
	}
}

