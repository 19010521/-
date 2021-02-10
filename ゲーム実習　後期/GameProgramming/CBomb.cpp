#include"CBomb.h"
#include"CKey.h"
#include"CXPlayer.h"
CBomb::CBomb(CModel*model, CVector position, CVector rotation, CVector scale)
:mBomb(this, CVector(0.0f, 1.0f, 0.0f), CVector(), CVector(1.0f, 1.0f, 1.0f), 9.0f)
{
	//���f��,�ʒu,�g�k��ݒ肷��
	mpModel = model;  //���f���̐ݒ�
	mPosition = position;//�ʒu�̐ݒ�
	mRotation = rotation;//��]�̐ݒ�
	mScale = scale;   //�g�k�̐ݒ�
	mBomb.mTag = CCollider::EBOMB;

}

void CBomb::Update(){

	if (CXPlayer::mpxPlayer->BombCarry == true){
		mEnabled = false;
	}
	CCharacter::Update();
}


