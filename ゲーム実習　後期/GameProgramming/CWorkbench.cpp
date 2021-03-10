#include"CWorkbench.h"



//コンストラクタ
//水をきれいにするアイテム用
CWorkbench::CWorkbench(CModel *model, CVector position, CVector rotation, CVector scale)
:mCollider(this, CVector(0.0f, 1.0f, 0.0f), CVector(), CVector(1.0f, 0.7f, 1.0f), 5.0f)
{
	mCollider.mTag = CCollider::EWORKBENCH;
	

	mpModel = model;
	mPosition = position;
	mRotation = rotation;
	mScale = scale;
}


//コンストラクタ
//爆弾用
CWorkbench2::CWorkbench2(CModel *model, CVector position, CVector rotation, CVector scale)
:mCollider(this, CVector(0.0f, 1.0f, 0.0f), CVector(), CVector(1.0f, 0.7f, 1.0f), 5.0f)
{
	mCollider.mTag = CCollider::EWORKBENCH2;


	mpModel = model;
	mPosition = position;
	mRotation = rotation;
	mScale = scale;
}