#ifndef CAMOUNT_H
#define CAMOUNT_H


#include "CRectangle.h"
#include "glut.h"

class CAmount : public CRectangle{
public:
	//�X�V����
	void Update();
	//�`�揈��
	void Render();
};
#endif