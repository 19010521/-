#include"CPuddle1.h"
#include"CXPlayer.h"
#include"CKey.h"
CPuddle1 *CPuddle1::mPuddle01 = 0;
CPuddle1::CPuddle1(CModel*model, CVector position, CVector rotation, CVector scale)
:mPuddle1(this, CVector(0.0f, 1.0f, 0.0f), CVector(), CVector(5.0f, 3.0f, 5.0f), 2.0f)
, UseCount(3), CountRetention(0), x(6.0f), y(0.5f), z(6.0f)

{
	CountRetention = UseCount;
	mPuddle01 = this;
	mPuddle1.mTag = CCollider::EPUDDLE1;

	mpModel = model;  //モデルの設定
	mPosition = position;//位置の設定
	mRotation = rotation;//回転の設定
	mScale = scale;   //拡縮の設定

	mScale = CVector(5.0f, 0.5f, 5.0f);
}

void CPuddle1::Set(const CVector &pos, float r){
	mPosition = pos;

	mPuddle1.mRadius = r;


	
}

void CPuddle1::Update(){

	CCharacter::Update();

	if (CountRetention > UseCount){
		mScale = CVector(x -= 2.0f, y, z -= 2.0f);
		CountRetention = UseCount;
	}

}

void CPuddle1::Collision(CCollider*m, CCollider*y){

	//共に球コライダの時
	if (m->mType == CCollider::ESPHERE && y->mType == CCollider::ESPHERE){
		//コライダのｍとｙが衝突しているか判定
		if (CCollider::Collision(m, y)){
			if (m->mTag == CCollider::EPUDDLE1){
				if (y->mTag == CCollider::EPLAYEREBODY){
					if (CXPlayer::mpxPlayer->mstate == CXPlayer::mpxPlayer->EMUD){
						if (CKey::Once('Q')){
							CXPlayer::mpxPlayer->mstate = CXPlayer::mpxPlayer->ENORMAL;
							mPuddle1.mTag = CCollider::EMUDPUDDLE;
						}

					}
				}
			}
		}
	}
}