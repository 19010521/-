
#include"CRock.h"
#include"CXPlayer.h"
#include"CEffect.h"
#include"CKey.h"


extern std::shared_ptr<CTexture>TextureExp1;
CRock::CRock(CModel*model, CVector position, CVector rotation, CVector scale)
:mColBody(this, CVector(0.0f, 1.0f, 0.0f), CVector(), CVector(1.0f, 0.7f, 1.0f), 10.0f)
,mColBody2(this, CVector(0.0f, 1.0f, 0.0f), CVector(), CVector(1.0f, 0.7f, 1.0f), 12.0f)
{
	mColBody.mTag = CCollider::EROCK;
	mColBody2.mTag = CCollider::EROCK2;
	
	//モデル,位置,拡縮を設定する
	mpModel = model;  //モデルの設定
	mPosition = position;//位置の設定
	mRotation = rotation;//回転の設定
	mScale = scale;   //拡縮の設定
	

}

void CRock::Collision(CCollider *m, CCollider *y){
	//共に球コライダの時
	if (m->mType == CCollider::ESPHERE && y->mType == CCollider::ESPHERE){
		//コライダのｍとｙが衝突しているか判定
		if (CCollider::Collision(m, y)){
			if (y->mTag == CCollider::EPLAYEREBODY){
				if (m->mTag == CCollider::EROCK2){
					if (CKey::Once('Q')){
					
					}
				}
			}
		}
	}
}
