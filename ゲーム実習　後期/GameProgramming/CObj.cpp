#include "CObj.h"
//�R���X�g���N�^
//model:���f���|�C���^ posision:�ʒu rotation:��] scale:�g�k
CObj::CObj(CModel*model, const CVector &position, const CVector &rotation, const CVector &scale)
:mpCollider(0), mPuddle(this, CVector(0.0f, 1.0f, 0.0f), CVector(), CVector(1.0f, 1.0f, 1.0f), 9.0f)
{
	mpModel = model;
	mPosition = position;
	mRotation = rotation;
	mScale = scale;
	mPuddle.mTag = CCollider::EPUDDLE0;

	//���f���̎O�p�`�̐���,�R���C�_�̔z����쐬���܂�
	mpCollider = new CCollider[model->mTriangles.size()];
	for (int i = 0; i < model->mTriangles.size(); i++){
		//�R���C�_���O�p�`�R���C�_�Őݒ肵�Ă��܂�
		mpCollider[i].SetTriangle(this,
			model->mTriangles[i].mV[0],
			model->mTriangles[i].mV[1],
			model->mTriangles[i].mV[2]);
		

	}

}

//�f�X�g���N�^
CObj::~CObj(){
	//�R���C�_������΍폜
	if (mpCollider){
		//delete[]�@�z����폜
		delete[] mpCollider;
	}
}
void CObj::Collision(CCollider*m, CCollider*y){
	//�G��Cube�ɏՓ˂����Ƃ��폜
	/*if (y->mTag == CCollider::EENEMY2){
		if (m->mType == CCollider::ETRIANGLE){
			CVector adjust;
			if (CCollider::CollisionTriangleSphere(m, y, &adjust)){
				mEnabled = false;
			}
		}
	}*/
}