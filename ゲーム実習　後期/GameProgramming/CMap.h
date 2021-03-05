#ifndef CMAP_H
#define CMAP_H

#include"CCharacter.h"
#include"CCollider.h"

class CMap : public CCharacter{
private:
	//確認用
	CCollider mCollider[14];
	

public:
	//デフォルトコンストラクタ
	CMap();
};

#endif