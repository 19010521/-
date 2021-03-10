#include"CClean.h"
#include"CSceneGame.h"
#include"CPuddle.h"
CClean::CClean()
{
	mpModel = &CSceneGame::mGun;
}

void CClean::Update(){

	CCharacter::Update();
	if (CPuddle::mClean_upCountflag == false){
		SetEnabled(false);
	}

}