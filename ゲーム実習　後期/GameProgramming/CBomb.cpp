#include"CBomb.h"
#include"CKey.h"
#include"CXPlayer.h"
CBomb::CBomb(CModel*model, CVector position, CVector rotation, CVector scale)
:mBomb(this, CVector(0.0f, 1.0f, 0.0f), CVector(), CVector(1.0f, 1.0f, 1.0f), 9.0f)
{
	//ƒ‚ƒfƒ‹,ˆÊ’u,Šgk‚ğİ’è‚·‚é
	mpModel = model;  //ƒ‚ƒfƒ‹‚Ìİ’è
	mPosition = position;//ˆÊ’u‚Ìİ’è
	mRotation = rotation;//‰ñ“]‚Ìİ’è
	mScale = scale;   //Šgk‚Ìİ’è
	mBomb.mTag = CCollider::EBOMB;

}

void CBomb::Update(){

	if (CXPlayer::mpxPlayer->BombCarry == true){
		mEnabled = false;
	}
	CCharacter::Update();
}


