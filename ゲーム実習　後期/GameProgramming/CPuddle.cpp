#include"CPuddle.h"
#include"CXPlayer.h"
#include"CKey.h"
#include"CRes.h"

#define WATERUSE (0.001f) //…‚ÌˆÙ“®—Ê

int CPuddle::mclearcount = 0;
bool CPuddle::mClean_upCountflag;
bool CPuddle::Enemy;
bool CPuddle::Enemy2;
CPuddle::CPuddle(CModel*model, CModel*model2, CVector position, CVector rotation, CVector scale)
:mPuddle(this, CVector(0.0f, 1.0f, 0.0f), CVector(), CVector(5.0f, 3.0f, 5.0f), 2.0f)
, EnemyCount(0), EnemyCount1(0), mClean_upCount(300), mClean_upCountMax(600)
, x(6.0f), y(0.5f), z(6.0f), mx(0.0f), mz(0.0f), mxMax(6.0f), mzMax(6.0f), frame(0), frame1(0), mCount(120), mCountMax(120)

{

	
	mTag = ENORMALPUDDLE;
	mPuddle.mTag = CCollider::EPUDDLE;
	mpModel = model;  //ƒ‚ƒfƒ‹‚ÌÝ’è
	mPosition = position;//ˆÊ’u‚ÌÝ’è
	mRotation = rotation;//‰ñ“]‚ÌÝ’è
	mScale = scale;   //Šgk‚ÌÝ’è
	
	Puddle = model;
	MudPuddle = model2;
	usefrag = false;
	mClean_upCountflag = false;
	rock = true;
	Enemy = false;
	Enemy2 = false;
	mScale = CVector(x, y, z);
	
	
}

void CPuddle::Set(const CVector &pos, float r){

	mPosition = pos;
	mPuddle.mRadius = r;

}
 
void CPuddle::Update(){

	

	if (rock == false){
		
			mclearcount++;
			
			rock = true;

	}
	if (mpModel == Puddle){

		mTag = ENORMALPUDDLE;
		mPuddle.mTag = CCollider::EPUDDLE;

		
	}



	if (mpModel == MudPuddle){
		mTag = EMUDPUDDLE;
		mPuddle.mTag = CCollider::EMUDPUDDLE;
	
	}
	
	if (x > 0 && z > 0){
		if (usefrag == true){
			mScale = CVector(x -= mx, y, z -= mz);
		}
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


	if (Enemy == true){
		if (mPosition.mZ < 0){
			if (mTag == EMUDPUDDLE){
				if (EnemyCount < 5){
					frame++;//ƒtƒŒ[ƒ€”‚É1‰ÁŽZ
					if (frame < 1000 && frame % 150 == 0){
						//“G‹@‚Ì¶¬
						mEnemy = new CXEnemy();
						//“G‚Ì‰ŠúÝ’è
						mEnemy->Init(&CRes::sKnight);
						EnemyCount++;
						//“G‚Ì”z’u
						mEnemy->mAnimationFrameSize = 1024;
						mEnemy->mPosition = mPosition;
						mEnemy->ChangeAnimation(2, true, 200);
						if (Enemy == true){
							Enemy = false;
						}
					}
					else if (frame > 1000)
					{
						frame = 0;
					}
				}
			}
		}
	}
	if (Enemy2 == true){
		if (mPosition.mZ > 0){
			if (mTag == EMUDPUDDLE){
				if (EnemyCount1 < 5){
					frame1++;//ƒtƒŒ[ƒ€”‚É1‰ÁŽZ
					if (frame1 < 1000 && frame1 % 150 == 0){
						//“G‹@‚Ì¶¬
						mEnemy2 = new CXEnemy2();
						//“G‚Ì‰ŠúÝ’è
						mEnemy2->Init(&CRes::sKnight);
						EnemyCount1++;
						//“G‚Ì”z’u
						mEnemy2->mAnimationFrameSize = 1024;
						mEnemy2->mPosition = mPosition;
						mEnemy2->ChangeAnimation(2, true, 200);
						if (Enemy2 == true){
							Enemy2 = false;
						}
					}
					else if (frame1 > 1000)
					{
						frame1 = 0;
					}
				}
			}
		}
	}
	
	
	
		

	CCharacter::Update();
	
}

void CPuddle::Collision(CCollider*m, CCollider*y){

	//‹¤‚É‹…ƒRƒ‰ƒCƒ_‚ÌŽž
	if (m->mType == CCollider::ESPHERE && y->mType == CCollider::ESPHERE){
		//ƒRƒ‰ƒCƒ_‚Ì‚‚Æ‚™‚ªÕ“Ë‚µ‚Ä‚¢‚é‚©”»’è
		if (CCollider::Collision(m, y)){
			//“D‚Ì…‚½‚Ü‚è
			if (m->mTag == CCollider::EMUDPUDDLE){
				if (y->mTag == CCollider::EPLAYEREBODY){
					//ƒAƒCƒeƒ€
					if (CXPlayer::mpxPlayer->mClean_up > 0){
						if (CKey::Push('Q')){
							if (mpModel == MudPuddle){
								CXPlayer::mpxPlayer->mClean_up--;
								CClean*mClean = new CClean();
								mClean->mPosition = mPosition;
								mClean_upCountflag = true;
							
								rock = false;
							}
						}

					}
					if (mClean_upCountflag == true){
						if (mClean_upCount > 0){
							mClean_upCount--;
						}
						else
						{
							mpModel = Puddle;
							mClean_upCount = mClean_upCountMax;

							mClean_upCountflag = false;
						}

					}
				}
			}
			//•’Ê‚Ì…‚½‚Ü‚è
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
						mclearcount--;
						mpModel = MudPuddle;

					}
				}
			}
		}
	}



