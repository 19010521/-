#include "CObj.h"
//コンストラクタ
//model:モデルポインタ posision:位置 rotation:回転 scale:拡縮
CObj::CObj(CModel*model, const CVector &position, const CVector &rotation, const CVector &scale)
:mpCollider(0), mPuddle(this, CVector(0.0f, 1.0f, 0.0f), CVector(), CVector(1.0f, 1.0f, 1.0f), 9.0f)
{
	mpModel = model;
	mPosition = position;
	mRotation = rotation;
	mScale = scale;
	mPuddle.mTag = CCollider::EPUDDLE0;

	//モデルの三角形の数分,コライダの配列を作成します
	mpCollider = new CCollider[model->mTriangles.size()];
	for (int i = 0; i < model->mTriangles.size(); i++){
		//コライダを三角形コライダで設定しています
		mpCollider[i].SetTriangle(this,
			model->mTriangles[i].mV[0],
			model->mTriangles[i].mV[1],
			model->mTriangles[i].mV[2]);
		

	}

}

//デストラクタ
CObj::~CObj(){
	//コライダがあれば削除
	if (mpCollider){
		//delete[]　配列を削除
		delete[] mpCollider;
	}
}
void CObj::Collision(CCollider*m, CCollider*y){
	//敵がCubeに衝突したとき削除
	/*if (y->mTag == CCollider::EENEMY2){
		if (m->mType == CCollider::ETRIANGLE){
			CVector adjust;
			if (CCollider::CollisionTriangleSphere(m, y, &adjust)){
				mEnabled = false;
			}
		}
	}*/
}