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

#define G (9.8f/60.0f)//重力加速度
#define JUMPV0 (2.0f)//ジャンプ初速


CXEnemy1::CXEnemy1(CModel*model, CVector position, CVector rotation, CVector scale)
: mSearch2(this, CVector(0.0f, 0.0f, -5.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f, 1.0f, 1.0f), 10.0f)
, mVelovcityJump(0), mnearCount(120), mnearCountMax(120), Randam(0), mCount(0), mCountMax(60 * 5), fCount(fCountMax), fCountMax(1000)
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
	mstate = ENORMAL;

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
	
	
	//行列を更新
	CCharacter::Update();
	
	mPosition = CVector(0.0f, 0.0f, -0.5f)*mMatrix;
}

void CXEnemy1::Init(CModelX*model){
	
}

void CXEnemy1::Collision(CCollider*m, CCollider*y){


	////共に球コライダの時
	//if (m->mType == CCollider::ESPHERE && y->mType == CCollider::ESPHERE){
	//	if (CCollider::Collision(m, y)){

	//		//コライダがサーチか判定
	//		if (m->mTag == CCollider::ESEARCH){

	//			//衝突したコライダの親の種類を判定
	//			switch (y->mpParent->mTag){
	//			case EPLAYER:

	//				//位置を移動
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
	//			//プレイヤーの時
	//			if (y->mTag == CCollider::EPLAYEREBODY){
	//				//衝突している時は無効にする
	//				nflag = true;
	//			}

	//			else

	//			{
	//				nflag = false;
	//			}


	//		}
	//		//コライダがサーチか判定
	//		else	if (m->mTag == CCollider::ESEARCH2){
	//			//衝突したコライダの親の種類を判定

	//			switch (y->mpParent->mTag){
	//			case EPLAYER://プレイヤーの時

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

	//			//衝突したコライダの親の種類を判定
	//			switch (y->mpParent->mTag){
	//			case EPOINT://ポイントの時
	//				//衝突したポインタと目指しているポインタが同じとき
	//				if (y->mpParent == mpPoint){

	//					mPointCnt++;//次のポイントにする
	//					//最後だったら最初にする
	//					mPointCnt %= mPointSize;
	//					//次のぽいんとのポインタを設定
	//					mpPoint = &mPoint[mPointCnt];
	//				}

	//				break;

	//			}

	//		}
	//	}
	//	if (CCollider::Collision(m, y)){
	//		//判定
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
	////自身コライダの判定タイプ
	//switch (m->mType){
	//case CCollider::ESPHERE://球コライダ
	//	//相手のコライダが三角コライダの時
	//	if (m->mTag != CCollider::ESEARCH&&m->mTag != CCollider::ESEARCH2){
	//		if (y->mType == CCollider::ETRIANGLE){
	//			CVector adjust;//調整用ベクトル		

	//			if (CCollider::CollisionTriangleSphere(y, m, &adjust)){
	//				if (mstate == EJUNP){
	//					mstate = ELANDING;
	//					//mstate = ENORMAL;
	//				}
	//				jflag = false;
	//				lflag = false;


	//				mVelovcityJump = 0;
	//				//位置の更新
	//				mPosition = mPosition - adjust*-1;
	//				//行列の更新
	//				CXCharacter::Update();
	//			}

	//		}
	//		break;
	//	}
	//}
}

