#include"CWorkbench.h"



//�R���X�g���N�^
//�������ꂢ�ɂ���A�C�e���p
CWorkbench::CWorkbench(CModel *model, CVector position, CVector rotation, CVector scale)
:mCollider(this, CVector(0.0f, 1.0f, 0.0f), CVector(), CVector(1.0f, 0.7f, 1.0f), 5.0f)
{
	mCollider.mTag = CCollider::EWORKBENCH;
	

	mpModel = model;
	mPosition = position;
	mRotation = rotation;
	mScale = scale;
}


//�R���X�g���N�^
//���e�p
CWorkbench2::CWorkbench2(CModel *model, CVector position, CVector rotation, CVector scale)
:mCollider(this, CVector(0.0f, 1.0f, 0.0f), CVector(), CVector(1.0f, 0.7f, 1.0f), 5.0f)
{
	mCollider.mTag = CCollider::EWORKBENCH2;


	mpModel = model;
	mPosition = position;
	mRotation = rotation;
	mScale = scale;
}