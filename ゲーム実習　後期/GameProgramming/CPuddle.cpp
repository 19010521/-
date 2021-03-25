#include"CPuddle.h"
#include"CXPlayer.h"
#include"CKey.h"
#include"CRes.h"

#define WATERUSE (0.001f) //水の異動量
#define RECOVERYWATERUSE (0.001f)//水の回復量
#define MUDWATERUSE (0.01f) //泥水の異動量


int CPuddle::mclearcount = 0;
bool CPuddle::mClean_upCountflag;
bool CPuddle::Enemy;
bool CPuddle::Enemy2;
CPuddle::CPuddle(CModel*model, CModel*model2, CVector position, CVector rotation, CVector scale)
:mPuddle(this, CVector(0.0f, 1.0f, 0.0f), CVector(), CVector(4.0f, 2.0f, 4.0f), 1.0f)
, EnemyCount(0), EnemyCount1(0), mClean_upCount(300), mClean_upCountMax(600)
, x(6.0f), y(0.5f), z(6.0f), mx(0.0f), mz(0.0f), mxMax(6.0f), mzMax(6.0f), frame(0), frame1(0), mCount(120), mCountMax(120)
{
	
	mTag = ENORMALPUDDLE;
	mPuddle.mTag = CCollider::EPUDDLE;
	mpModel = model;  //モデルの設定
	mPosition = position;//位置の設定
	mRotation = rotation;//回転の設定
	mScale = scale;   //拡縮の設定
	
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
	
	if (x > 1 && z > 1){
		if (usefrag == true){
			mScale = CVector(x -= mx, y, z -= mz);
			CXPlayer::mpxPlayer->mWaterCount++;
		}
	}
	//泥水が徐々に増える
	if (mPuddle.mTag == CCollider::EMUDPUDDLE){
		mScale = CVector(x += MUDWATERUSE, y, z += MUDWATERUSE);
		
		mPuddle.mRadius += MUDWATERUSE;
		}

	//泥水が治ったとき
	if (x > mxMax&&z > mzMax){
		if (mPuddle.mTag == CCollider::EPUDDLE){
			mScale = CVector(x -= MUDWATERUSE, y, z -= MUDWATERUSE);

			mPuddle.mRadius = MUDWATERUSE;
		}
	}
	//水が少しずつ回復する
	if (mPuddle.mTag == CCollider::EPUDDLE){
		if (x < mxMax&&z < mzMax){
			if (usefrag == false){

				
					mScale = CVector(x += RECOVERYWATERUSE, y, z += RECOVERYWATERUSE);
					
			}
		}
	}


	if (Enemy == true){
		if (mPosition.mZ < 0){
			if (mTag == EMUDPUDDLE){
				if (EnemyCount < 5){
					frame++;//フレーム数に1加算
					if (frame < 1000 && frame % 150 == 0){
						//敵機の生成
						mEnemy = new CXEnemy();
						//敵の初期設定
						mEnemy->Init(&CRes::sKnight);
						EnemyCount++;
						//敵の配置
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
					frame1++;//フレーム数に1加算
					if (frame1 < 1000 && frame1 % 150 == 0){
						//敵機の生成
						mEnemy2 = new CXEnemy2();
						//敵の初期設定
						mEnemy2->Init(&CRes::sKnight);
						EnemyCount1++;
						//敵の配置
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

	//共に球コライダの時
	if (m->mType == CCollider::ESPHERE && y->mType == CCollider::ESPHERE){
		//コライダのｍとｙが衝突しているか判定
		if (CCollider::Collision(m, y)){
			//泥の水たまり
			if (m->mTag == CCollider::EMUDPUDDLE){
				if (y->mTag == CCollider::EPLAYEREBODY){
					//アイテム
					if (CXPlayer::mpxPlayer->mClean_up > 0){
						if (CKey::Push('Q')){
							if (mpModel == MudPuddle){
								CXPlayer::mpxPlayer->mClean_up--;
								CXPlayer::mpxPlayer->mHPNow++;
								CClean*mClean = new CClean();
								mClean->mPosition = mPosition;
								mClean_upCountflag = true;

								rock = false;
							}
						}

					}
					//時間差で治る
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
			//普通の水たまり
				if (m->mTag == CCollider::EPUDDLE){
					if (y->mTag == CCollider::EMUDPUDDLE){
						mclearcount--;
 						mpModel = MudPuddle;

					}
					if (y->mTag == CCollider::EPLAYEREBODY){
						
						if (CKey::Push('Q') && CXPlayer::mpxPlayer->mWaterCount < CXPlayer::mpxPlayer->mWaterCountMax){

							if (mx <= 0.1f && mz <= 0.1f){
								mx += WATERUSE;
								mz += WATERUSE;

							}
							else{
								mx = 0;
								mz = 0;

							}
							
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



