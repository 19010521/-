#ifndef CMAP_H
#define CMAP_H

#include"CCharacter.h"
#include"CCollider.h"

class CMap : public CCharacter{
private:
	//�m�F�p
	CCollider mCollider[14];
	

public:
	//�f�t�H���g�R���X�g���N�^
	CMap();
};

#endif