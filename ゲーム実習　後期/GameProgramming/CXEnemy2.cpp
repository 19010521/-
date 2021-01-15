#include"CXEnemy2.h"
#include"CRes.h"
#include"CXPlayer.h"
#include"CBullet.h"
#include<stdio.h>
#include<time.h>
//誘導ポイント
bool CXEnemy2::Attackflag = true;
float CXEnemy2::mHPMax = 50;
float CXEnemy2::mHPNow = mHPMax;
#define G (9.8f/60.0f)//重力加速度
#define JUMPV0 (2.0f)//ジャンプ初速


CXEnemy2::CXEnemy2(CModel*model, CVector position, CVector rotation, CVector scale)
: mSearch2(this, CVector(0.0f, 0.0f, -5.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f, 1.0f, 1.0f), 4.0f)
, mColSphereBody(this, CVector(0.0f, 1.0f, 0.0f), CVector(), CVector(1.0f, 1.0f, 1.0f), 1.5f)
, mVelovcityJump(0), mnearCount(120), mnearCountMax(120), Randam(0), mCount(0), mCountMax(180), fCount(fCountMax), fCountMax(1000)
{

	mpModel = model;  //モデルの設定
	mPosition = position;//位置の設定
	mRotation = rotation;//回転の設定
	mScale = scale;   //拡縮の設定

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

	mPointCnt = 0;//最初のポイントを設定
	//mpPoint = &mPoint[mPointCnt];//目指すポイントのポインタを設定


}

void CXEnemy2::Update(){

	//mVelovcityJump -= G;

	//srand((unsigned int)time(NULL));  //よくわからん

	if (mCount > 0){

		Attackflag = false;

	}

	//位置を移動
	CVector dir = CXPlayer::mpxPlayer->mPosition - mPosition;

	CVector left = CVector(1.0f, 0.0f, 0.0f)  * CMatrix().RotateY(mRotation.mY);
	if (left.Dot(dir) > 0.0f){
		mRotation.mY -= 1.0f;
	}
	else if (left.Dot(dir) < 0.0f){
		mRotation.mY += 1.0f;
	}


	//行列を更新
	CCharacter::Update();


	

}

void CXEnemy2::Init(CModelX*model){

}

void CXEnemy2::Collision(CCollider*m, CCollider*y){

	//共に球コライダの時
	if (m->mType == CCollider::ESPHERE && y->mType == CCollider::ESPHERE){
		if (CCollider::Collision(m, y)){

			//コライダがサーチか判定
			if (m->mTag == CCollider::ESEARCH2){
				//衝突したコライダの親の種類を判定
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
			//判定
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


