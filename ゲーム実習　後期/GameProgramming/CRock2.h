#ifndef CROCK2_H
#define CROCK2_H

#include "CCharacter.h"
#include "CCollider.h"
#include "CCollisionManager.h"
#include "CEffect.h"
#include "CTexture.h"

class  CRock2 :public CCharacter{
private:

	CCollider mCollider;

public:

	//コンストラクタ
	CRock2(CModel *model, CVector position, CVector rotation, CVector scale);
};
#endif