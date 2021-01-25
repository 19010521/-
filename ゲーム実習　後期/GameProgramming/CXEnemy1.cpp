#include"CXEnemy1.h"
#include"CRes.h"
#include"CXPlayer.h"
#include"CBullet.h"
#include<stdio.h>
#include<time.h>
//誘導ポイント
CPoint *CXEnemy1::mPoint = 0;
int CXEnemy1::mPointSize = 0;
bool CXEnemy1::Attackflag = true;

float CXEnemy1::mHPMax = 50;
float CXEnemy1::mHPNow = mHPMax;

#define G (9.8f/60.0f)//重力加速度
#define JUMPV0 (2.0f)//ジャンプ初速


CXEnemy1::CXEnemy1(CModel*model, CVector position, CVector rotation, CVector scale)
: mSearch2(this, CVector(0.0f, 0.0f, -5.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f, 1.0f, 1.0f), 4.0f)
, mColSphereBody(this, CVector(0.0f, 1.0f, 0.0f), CVector(), CVector(1.0f, 1.0f, 1.0f), 1.5f)
, mVelovcityJump(0), mnearCount(360), mnearCountMax(360), Randam(0), mCount(0), mCountMax(60 * 5), fCount(fCountMax), fCountMax(1000)
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
	mpPoint = &mPoint[mPointCnt];//目指すポイントのポインタを設定


}

void CXEnemy1::Update(){

	//mVelovcityJump -= G;

	//srand((unsigned int)time(NULL));  //よくわからん


	//位置を移動
	CVector dir = CXPlayer::mpxPlayer->mPosition - mPosition;

	CVector left = CVector(1.0f, 0.0f, 0.0f)  * CMatrix().RotateY(mRotation.mY);
	if (left.Dot(dir) > 0.0f){
		mRotation.mY -= 1.0f;
	}
	else if (left.Dot(dir) < 0.0f){
		mRotation.mY += 1.0f;
	}

	//止まる
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
	
	//行列を更新
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


	//共に球コライダの時
	if (m->mType == CCollider::ESPHERE && y->mType == CCollider::ESPHERE){
		if (CCollider::Collision(m, y)){

			//コライダがサーチか判定
			if (m->mTag == CCollider::ESEARCH2){
				//衝突したコライダの親の種類を判定
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

