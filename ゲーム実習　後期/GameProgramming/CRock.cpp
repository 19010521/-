
#include"CRock.h"
#include"CXPlayer.h"
#include"CEffect.h"
#include"CKey.h"
CRock *CRock::mpRock = 0;
extern std::shared_ptr<CTexture>TextureExp1;
CRock::CRock(CModel*model, CVector position, CVector rotation, CVector scale)
:mColBody(this, CVector(0.0f, 1.0f, 0.0f), CVector(), CVector(1.0f, 0.7f, 1.5f), 12.0f)
{
	mColBody.mTag = CCollider::EROCK;
	//ƒ‚ƒfƒ‹,ˆÊ’u,Šgk‚ðÝ’è‚·‚é
	mpModel = model;  //ƒ‚ƒfƒ‹‚ÌÝ’è
	mPosition = position;//ˆÊ’u‚ÌÝ’è
	mRotation = rotation;//‰ñ“]‚ÌÝ’è
	mScale = scale;   //Šgk‚ÌÝ’è

}

void CRock::Collision(CCollider *m, CCollider *y){
	//‹¤‚É‹…ƒRƒ‰ƒCƒ_‚ÌŽž
	if (m->mType == CCollider::ESPHERE && y->mType == CCollider::ESPHERE){
		//ƒRƒ‰ƒCƒ_‚Ì‚‚Æ‚™‚ªÕ“Ë‚µ‚Ä‚¢‚é‚©”»’è
		if (CCollider::Collision(m, y)){
			if (CXPlayer::mpxPlayer->BombCarry == true){
				if (CKey::Once('Q')){
					new CEffect(y->mPosition*y->mMatrix*y->mpParent->mMatrix, 1.0f, 1.0f, TextureExp1, 4, 4, 1);
					//mEnabled = false;
				}
			}
		
		}
	}
}