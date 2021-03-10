#ifndef COBJ_H
#define COBJ_H
#include "CCharacter.h"
#include "CCollider.h"

class CObj :public CCharacter{
private:


public:
	//�R���C�_�̒ǉ�
	CCollider*mpCollider;
	
	//�R���X�g���N�^�ŏ��������Ă�
	CObj(CModel*model, const CVector &position,
		const CVector &rotation, const CVector &scale);

	~CObj();
};
#endif