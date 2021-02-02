#ifndef CITEM_H
#define CITEM_H
#include"CCharacter.h"
#include"CCollider.h"

class CItem :public CCharacter{
public:

	CItem(CModel*model, CVector position, CVector rotation, CVector scale);
	CCollider mColBody;
	//void Update();

};
#endif
