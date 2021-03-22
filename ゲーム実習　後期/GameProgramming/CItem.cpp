#include"CItem.h"
#include"CXPlayer.h"
#include"CSceneGame.h"



//コンストラクタ
CItem::CItem()
:mCollider(this, CVector(0.0f, 1.0f, 0.0f), CVector(), CVector(1.0f, 0.7f, 1.0f), 10.0f)
, mCollider2(this, CVector(0.0f, 1.0f, 0.0f), CVector(), CVector(1.0f, 0.7f, 1.0f), 1.0f)

{
	mpModel = &CSceneGame::mItem;
	mCollider.mTag = CCollider::ESEARCH;
	mCollider2.mTag = CCollider::EITEM;
	Recoveryflag = false;
}


void CItem::Update(){




	if (Recoveryflag == true){
		//位置を移動
		CVector dir = CXPlayer::mpxPlayer->mPosition - mPosition;

		CVector left = CVector(1.0f, 0.0f, 0.0f)  * CMatrix().RotateY(mRotation.mY);
		if (left.Dot(dir) > 0.0f){
			mRotation.mY += 1.0f;
		}
		else if (left.Dot(dir) < 0.0f){
			mRotation.mY -= 1.0f;
		}
	}


	//行列を更新
	CCharacter::Update();
	if (Recoveryflag == false){

		mPosition = CVector(0.0f, 0.0f, 0.0f)*mMatrix;
	}
	else
	{
		mPosition = CVector(0.0f, 0.0f, 0.1f)*mMatrix;
	
	}

}
void CItem::Collision(CCollider*m, CCollider*y){

	//共に球コライダの時
	if (m->mType == CCollider::ESPHERE && y->mType == CCollider::ESPHERE){
		if (CCollider::Collision(m, y)){

			
			if (m->mTag == CCollider::ESEARCH){
				if (y->mTag == CCollider::EPLAYEREBODY){

					Recoveryflag = true;

				}
			}
			if (m->mTag == CCollider::EITEM){
				if (y->mTag == CCollider::EPLAYEREBODY){
					if (GetEnabled() != false){
						CXPlayer::mpxPlayer->mClean_up++;
					}
					SetEnabled(false); 

				}
				if (y->mTag == CCollider::EENEMYBODY){
					SetEnabled(false);
				}

			}
		}
	}
}



