#include "CItem.h"

CItem::CItem(CModel*model, CVector position, CVector rotation, CVector scale)
:mColBody(this, CVector(0.0f, 1.0f, 0.0f), CVector(), CVector(1.0f, 1.0f, 1.0f), 9.0f)
{
	//モデル,位置,拡縮を設定する
	mpModel = model;  //モデルの設定
	mPosition = position;//位置の設定
	mRotation = rotation;//回転の設定
	mScale = scale;   //拡縮の設定


}
//void CItem::Update(){
//
//}