#include"CPuddle1.h"
#include"CXPlayer.h"
#include"CKey.h"
CPuddle1::CPuddle1(CModel*model, CVector position, CVector rotation, CVector scale)
:mPuddle1(this, CVector(0.0f, 0.0f, 0.0f), CVector(), CVector(5.0f, 3.0f, 5.0f), 1.0f)


{
	mPuddle1.mTag = CCollider::EPUDDLE1;

	mpModel = model;  //���f���̐ݒ�
	mPosition = position;//�ʒu�̐ݒ�
	mRotation = rotation;//��]�̐ݒ�
	mScale = scale;   //�g�k�̐ݒ�

	mScale = CVector(1.0f, 1.0f, 1.0f);
}

void CPuddle1::Set(const CVector &pos, float r){
	mPosition = pos;
	
	mPuddle1.mRadius = r;


	CCharacter::Update();
}

void CPuddle1::Collision(CCollider*m, CCollider*y){

	//���ɋ��R���C�_�̎�
	if (m->mType == CCollider::ESPHERE && y->mType == CCollider::ESPHERE){
		//�R���C�_�̂��Ƃ����Փ˂��Ă��邩����
		if (CCollider::Collision(m, y)){
			if (m->mTag == CCollider::EPUDDLE1){
					if (y->mTag == CCollider::EPLAYEREBODY){
						if (CXPlayer::mpxPlayer->mstate==CXPlayer::mpxPlayer->EMUD){
						if (CKey::Once('Q')){
							CXPlayer::mpxPlayer->mstate = CXPlayer::mpxPlayer->ENORMAL;
							mPuddle1.mTag = CCollider::EMUDPUDDLE;
						}

					}
				}
			}
		}
	}
}