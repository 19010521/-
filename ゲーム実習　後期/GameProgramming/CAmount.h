#ifndef CAMOUNT_H
#define CAMOUNT_H


#include "CRectangle.h"
#include "glut.h"

class CAmount : public CRectangle{
private:
	//�X�V����
	void Update();

public:
	//�`�揈��
	void Render();
};
#endif