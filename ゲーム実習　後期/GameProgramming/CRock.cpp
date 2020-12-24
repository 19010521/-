
#include"CRock.h"
CRock *CRock::mpRock = 0;
CRock::CRock(CModel*model, CVector position, CVector rotation, CVector scale)
:mColBody(this, CVector(0.0f, 1.0f, 0.0f), CVector(), CVector(1.0f, 0.7f, 1.0f), 9.0f)
{
	mColBody.mTag = CCollider::EROCK;
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
			
		
		}
	}
}