#ifndef CAMOUNT_H
#define CAMOUNT_H


#include "CRectangle.h"
#include "glut.h"

class CAmount : public CRectangle{
public:
	//更新処理
	void Update();
	//描画処理
	void Render();
};
#endif