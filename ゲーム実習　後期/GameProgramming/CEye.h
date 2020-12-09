#ifndef CEYE_H
#define CEYE_H
#include "CCharacter.h"
#include"CInput.h"
class CEye :public CCharacter{
public:
	
	static CEye *mpthis;
	int mMouseX;
	int mMouseY;
	CEye(CModel*model, CVector position, CVector rotation, CVector scale);
	void Update();
	CEye(){
		mMouseX = 1920 / 2;
		mMouseY = 1080 / 2;
		mpthis = this;
		CInput::SetMousePos(mMouseX, mMouseY);
		CInput::GetMousePos(&mMouseX, &mMouseY);
	};

};
#endif