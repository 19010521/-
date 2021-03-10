#include"CPuddlePoint.h"


CPuddlePoint::CPuddlePoint()
:mCollider(this, CVector(25.0f, 0.0f, -70.0f), CVector(), CVector(1.5f, 1.0f, 1.0f), 50.0f)
, mCollider2(this, CVector(0.0f, 0.0f, 50.0f), CVector(), CVector(1.5f, 1.0f, 1.0f), 70.0f)
{
	mCollider.mTag = CCollider::ESEARCHENEMY;
	mCollider2.mTag = CCollider::ESEARCHENEMY2;
	mTag = EPOINT;//タグをポイントにする
	mScale = CVector(1.5f, 1.0f, 1.0f);
}

void CPuddlePoint::Set(const CVector &pos, float r){
	mPosition = pos;
	mCollider.mRadius = r;
	CCharacter::Update();
}