#include"CPuddle.h"
#include"CXPlayer.h"
#include"CKey.h"
#include"CRes.h"

#define WATERUSE (0.001f) //���̈ٓ���
CPuddle *CPuddle::mpPuddle = 0;
int CPuddle::clearcount = 0;
CPuddle::CPuddle(CModel*model,CModel*model2, CVector position, CVector rotation, CVector scale)
:mPuddle(this, CVector(0.0f, 1.0f, 0.0f), CVector(), CVector(5.0f, 3.0f, 5.0f), 2.0f)
, x(6.0f), y(0.5f), z(6.0f), mx(0.0f), mz(0.0f), mxMax(6.0f), mzMax(6.0f), frame(0), mCount(120), mCountMax(120)

{

	
	mTag = ENORMALPUDDLE;
	mPuddle.mTag = CCollider::EPUDDLE;
	mpModel = model;  //���f���̐ݒ�
	mPosition = position;//�ʒu�̐ݒ�
	mRotation = rotation;//��]�̐ݒ�
	mScale = scale;   //�g�k�̐ݒ�

	Puddle = model;
	MudPuddle = model2;
	usefrag = false;
	
	mScale = CVector(x, y, z);
	mpPuddle = this;


}

void CPuddle::Set(const CVector &pos, float r){

	mPosition = pos;
	mPuddle.mRadius = r;

}
 
void CPuddle::Update(){

	
	if (rock == false){
		if (mpModel == Puddle){

			mTag = ENORMALPUDDLE;
			mPuddle.mTag = CCollider::EPUDDLE;
		
			clearcount ++ ;
			rock = true;
		}

	}
	if (mudrock == false){
		if (mpModel == MudPuddle){
			mTag = EMUDPUDDLE;
			mPuddle.mTag = CCollider::EMUDPUDDLE;
			mudrock = true;
		}
	}

	if (usefrag == true){
		mScale = CVector(x -= mx, y, z -= mz);

	}
	if (x < mxMax&&z < mzMax){
	      if (usefrag == false){
			
			if (mCount > 0){
				mCount--;
			}
			else
			{
				mScale = CVector(x += mx, y, z += mz);
				mCount = mCountMax;
			}
			
		}
	}

	



	if (mTag == EMUDPUDDLE){


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
	CCharacter::Update();
	
}

void CPuddle::Collision(CCollider*m, CCollider*y){

	//���ɋ��R���C�_�̎�
	if (m->mType == CCollider::ESPHERE && y->mType == CCollider::ESPHERE){
		//�R���C�_�̂��Ƃ����Փ˂��Ă��邩����
		if (CCollider::Collision(m, y)){
			if (m->mTag == CCollider::EMUDPUDDLE){
				//�A�C�e��
				if (CXPlayer::mpxPlayer->mClean_up > 0){
					if (CKey::Push('Q')){
						rock = false;
						if (mpModel == MudPuddle){
							CXPlayer::mpxPlayer->mClean_up--;
						}
						mpModel = Puddle;
					}
				}

			}
				if (m->mTag == CCollider::EPUDDLE){
					
					if (y->mTag == CCollider::EPLAYEREBODY){
						
						if (CKey::Push('Q') && CXPlayer::mpxPlayer->mWaterCount < CXPlayer::mpxPlayer->mWaterCountMax){

							if (mx <= 1.0f && mz <= 1.0f){
								mx += WATERUSE;
								mz += WATERUSE;

							}
							else{
								mx = 0;
								mz = 0;

							}
							CXPlayer::mpxPlayer->mWaterCount++;
							usefrag = true;

						}
						else if (usefrag == true)
						{
							usefrag = false;
						}


						if (CXPlayer::mpxPlayer->mstate == CXPlayer::mpxPlayer->EMUD ){
							
								CXPlayer::mpxPlayer->mstate = CXPlayer::mpxPlayer->ENORMAL;
								mpModel = MudPuddle;
							
						}
						

						}
					if (y->mTag == CCollider::EENEMYBODY){
						mudrock = false;
						clearcount--;
						mpModel = MudPuddle;

					}
				}
			}
		}
	}



