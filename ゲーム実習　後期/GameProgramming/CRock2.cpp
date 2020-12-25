#include"CRock2.h"
#include "CXPlayer.h"
CRock2 *CRock2::mpRock = 0;

//コンストラクタ
CRock2::CRock2(CModel *model, CVector position, CVector rotation, CVector scale)
{
	mCollider.mTag = CCollider::EROCK;
	mpModel = model;
	mPosition = position;
	mRotation = rotation;
	mScale = scale;
}