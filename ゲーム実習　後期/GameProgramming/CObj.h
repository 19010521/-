#ifndef COBJ_H
#define COBJ_H
#include "CCharacter.h"
#include "CCollider.h"

class CObj :public CCharacter{
public:
	//�R���C�_�̒ǉ�
	CCollider*mpCollider;
	CCollider mPuddle;
	//�R���X�g���N�^�ŏ��������Ă�
	CObj(CModel*model, const CVector &position,
		const CVector &rotation, const CVector &scale);
	~CObj();
	//Collision(�R���C�_1,�R���C�_2)
	void Collision(CCollider *m, CCollider *y);
};
#endif