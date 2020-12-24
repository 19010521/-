
#include"CRock.h"
CRock *CRock::mpRock = 0;
CRock::CRock(CModel*model, CVector position, CVector rotation, CVector scale)
:mColBody(this, CVector(0.0f, 1.0f, 0.0f), CVector(), CVector(1.0f, 0.7f, 1.0f), 9.0f)
{
	mColBody.mTag = CCollider::EROCK;
	//���f��,�ʒu,�g�k��ݒ肷��
	mpModel = model;  //���f���̐ݒ�
	mPosition = position;//�ʒu�̐ݒ�
	mRotation = rotation;//��]�̐ݒ�
	mScale = scale;   //�g�k�̐ݒ�

}

void CRock::Collision(CCollider *m, CCollider *y){
	//���ɋ��R���C�_�̎�
	if (m->mType == CCollider::ESPHERE && y->mType == CCollider::ESPHERE){
		//�R���C�_�̂��Ƃ����Փ˂��Ă��邩����
		if (CCollider::Collision(m, y)){
			
		
		}
	}
}