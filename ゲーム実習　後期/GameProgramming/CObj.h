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
	
};
#endif