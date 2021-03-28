#include "CEye.h"
#include"CKey.h"
#include"CSceneGame.h"

#define MOUSE_SENSE 2
#define MOUSE_X 40
CEye *CEye::mpthis = nullptr;

CEye::CEye(CModel*model, CVector position, CVector rotation, CVector scale)
{
	//モデル,位置,回転,拡縮を設定する
	mpModel = model;     //モデルの設定
	mPosition = position;//位置の設定
	mRotation = rotation;//回転の位置
	mScale = scale;      //拡縮の設定
	
	
}

void CEye::Update(){

	static int mMouseCount = 0;
	++mMouseCount %= MOUSE_SENSE;
	if (mMouseCount == 0){

		//マウスカーソルを起動時の座標に移動
		CInput::SetMousePos(mMouseX, mMouseY);
	}


	//マウスカーソルの座標を取得oo
	int mx, my;
	//マウスの移動値
	float m(3.0);
	CInput::GetMousePos(&mx, &my);
	

		if (mx < mMouseX) {
			//マウスの移動量の分だけ回転
			mRotation.mY += (mMouseX - mx) / m;
		}
		if (mMouseX < mx) {
			//マウスの移動量の分だけ回転
			mRotation.mY += (mMouseX - mx) / m;
		}
		
		if (my < mMouseY) {
			if (mRotation.mX > -MOUSE_X){
				//マウスの移動量の分だけ回転
				mRotation.mX -= (mMouseY - my) / m;
			}
		}
	    //マウス下
		if (mMouseY < my) {
			//マウスの移動量の分だけ回転
			if (mRotation.mX < MOUSE_X){
				mRotation.mX -= (mMouseY - my) / m;
			}
		}
	CCharacter::Update();

}