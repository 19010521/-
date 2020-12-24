#include"CPuddle.h"
#include"CXPlayer.h"
#include"CKey.h"

CPuddle *CPuddle::mPuddle = 0;
CPuddle::CPuddle(CModel*model, CVector position, CVector rotation, CVector scale)
:mPuddle0(this, CVector(0.0f, 1.0f, 0.0f), CVector(), CVector(5.0f, 3.0f, 5.0f), 2.0f)
, UseCount(3), CountRetention(0), x(6.0f), y(0.5f), z(6.0f)
{

	CountRetention = UseCount;
	mPuddle0.mTag = CCollider::EPUDDLE0;
	mpModel = model;  //���f���̐ݒ�
	mPosition = position;//�ʒu�̐ݒ�
	mRotation = rotation;//��]�̐ݒ�
	mScale = scale;   //�g�k�̐ݒ�

	mScale = CVector(x, y, z);
	mPuddle = this;
}


void CPuddle::Set(const CVector &pos, float r){

	mPosition = pos;
	mPuddle0.mRadius = r;

	
}
 
void CPuddle::Update(){

	CCharacter::Update();

	if (CountRetention > UseCount){
		mScale = CVector(x-=2.0f, y, z-=2.0f);
		CountRetention = UseCount;
	}

}

void CPuddle::Collision(CCollider*m, CCollider*y){
	
	//���ɋ��R���C�_�̎�
		if (m->mType == CCollider::ESPHERE && y->mType == CCollider::ESPHERE){
			//�R���C�_�̂��Ƃ����Փ˂��Ă��邩����
			if (CCollider::Collision(m, y)){
				if (m->mTag == CCollider::EPUDDLE0){
					if (y->mTag == CCollider::EPLAYEREBODY){
						if (CXPlayer::mpxPlayer->mstate == CXPlayer::mpxPlayer->EMUD){
							if (CKey::Once('Q')){
								CXPlayer::mpxPlayer->mstate = CXPlayer::mpxPlayer->ENORMAL;
								mPuddle0.mTag = CCollider::EMUDPUDDLE;
								//mEnabled = false;
							}
						}
					}
				}
			}
		}
	}

