#include"CPuddle.h"
#include"CXPlayer.h"
#include"CKey.h"
#include"CRes.h"

CPuddle *CPuddle::mpPuddle = 0;
CPuddle::CPuddle(CModel*model,CModel*model2, CVector position, CVector rotation, CVector scale)
:mPuddle(this, CVector(0.0f, 1.0f, 0.0f), CVector(), CVector(5.0f, 3.0f, 5.0f), 2.0f)
, UseCount(3), CountRetention(0), x(6.0f), y(0.5f), z(6.0f), mx(0.0f), mz(0.0f), frame(0)
{

	CountRetention = UseCount;
	mTag = ENORMAL;
	mPuddle.mTag = CCollider::EPUDDLE0;
	mpModel = model;  //���f���̐ݒ�
	mPosition = position;//�ʒu�̐ݒ�
	mRotation = rotation;//��]�̐ݒ�
	mScale = scale;   //�g�k�̐ݒ�

	Puddle = model;
	MudPuddle = model2;

	mScale = CVector(x, y, z);
	mpPuddle = this;


}


void CPuddle::Set(const CVector &pos, float r){

	mPosition = pos;
	mPuddle.mRadius = r;

	
}
 
void CPuddle::Update(){


	CCharacter::Update();
	if (CountRetention > UseCount){

		if (mx <= 1.0f && mz <= 1.0f){
			mx += 0.5f;
			mz += 0.5f;
			mScale = CVector(x -= mx, y, z -= mz);

		}
		else{
			CountRetention = UseCount;
			mx = 0;
			mz = 0;

		}
	}

	if (x <= 0 || z <= 0){
		mEnabled = false;
	}

	if (mTag==EMUD){

		mpModel = MudPuddle;

		frame++;//�t���[������1���Z
		if (frame < 1000 && frame % 150 == 0){
			//�G�@�̐���
			mEnemy = new CXEnemy();
			//�G�̏����ݒ�
			mEnemy->Init(&CRes::sKnight);

			//�G�̔z�u
			mEnemy->mAnimationFrameSize = 1024;
			mEnemy->mPosition = mPosition;
			mEnemy->ChangeAnimation(2, true, 200);
		}
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
								mPuddle.mTag = CCollider::EMUDPUDDLE;
								
							}
						}
					}
				}
			}
		}
	}

