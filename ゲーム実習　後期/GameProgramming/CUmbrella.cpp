#include "CUmbrella.h"
#include"CSceneGame.h"
CUmbrella::CUmbrella()
:mUmbrella(this, CVector(0.0f, 1.0f, 0.0f), CVector(), CVector(1.0f, 1.0f, 1.0f), 9.0f)
{
	mpModel = &CSceneGame::mGun;
	mUmbrella.mTag = CCollider::EUMBRELLA;

}




