#include"CPuddle2.h"
#include"CXPlayer.h"
#include"CKey.h"
CPuddle2 *CPuddle2::mPuddle02 = 0;
CPuddle2::CPuddle2(CModel*model, CVector position, CVector rotation, CVector scale)
:mPuddle2(this, CVector(0.0f, 1.0f, 0.0f), CVector(), CVector(5.0f, 3.0f, 5.0f), 2.0f)


{
	mPuddle02 = this;
	mPuddle2.mTag = CCollider::EPUDDLE2;

	mpModel = model;  //モデルの設定
	mPosition = position;//位置の設定
	mRotation = rotation;//回転の設定
	mScale = scale;   //拡縮の設定

	mScale = CVector(5.0f, 0.5f, 5.0f);
}

void CPuddle2::Set(const CVector &pos, float r){
	mPosition = pos;

	mPuddle2.mRadius = r;


	CCharacter::Update();
}

void CPuddle2::Collision(CCollider*m, CCollider*y){

	//共に球コライダの時
	if (m->mType == CCollider::ESPHERE && y->mType == CCollider::ESPHERE){
		//コライダのｍとｙが衝突しているか判定
		if (CCollider::Collision(m, y)){
			if (m->mTag == CCollider::EPUDDLE2){

				if (y->mTag == CCollider::EPLAYEREBODY){
					if (CXPlayer::mpxPlayer->mstate == CXPlayer::mpxPlayer->EMUD){

						if (CKey::Once('Q')){
							CXPlayer::mpxPlayer->mstate = CXPlayer::mpxPlayer->ENORMAL;
							mPuddle2.mTag = CCollider::EMUDPUDDLE;
						}

					}
				}
			}
		}
	}
}