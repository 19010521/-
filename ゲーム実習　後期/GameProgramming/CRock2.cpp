#include"CRock2.h"



//�R���X�g���N�^
CRock2::CRock2(CModel *model, CVector position, CVector rotation, CVector scale)
{
	mCollider.mTag = CCollider::EROCK;
	mpModel = model;
	mPosition = position;
	mRotation = rotation;
	mScale = scale;
}