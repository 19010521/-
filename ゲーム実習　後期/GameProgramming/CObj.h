#ifndef COBJ_H
#define COBJ_H
#include "CCharacter.h"
#include "CCollider.h"

class CObj :public CCharacter{
private:


public:
	//コライダの追加
	CCollider*mpCollider;
	
	//コンストラクタで初期せってい
	CObj(CModel*model, const CVector &position,
		const CVector &rotation, const CVector &scale);

	~CObj();
};
#endif