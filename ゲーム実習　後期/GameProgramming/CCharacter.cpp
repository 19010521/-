//キャラクタクラスインクルード
#include "CCharacter.h"
//
#include "CTaskManager.h"

//更新処理
void CCharacter::Update() {
	//拡大縮小行列の設定
	mMatrixScale.Scale(mScale.mX, mScale.mY, mScale.mZ);
	//回転行列の設定
	mMatrixRotate =
		CMatrix().RotateZ(mRotation.mZ) *
		CMatrix().RotateX(mRotation.mX) *
		CMatrix().RotateY(mRotation.mY);
	//平行移動行列の設定
	mMatrixTranslate.Translate(mPosition.mX, mPosition.mY, mPosition.mZ);
	//合成行列の設定
	mMatrix = mMatrixScale * mMatrixRotate * mMatrixTranslate;
	////親がいれば、親の行列と合成
	//if (mpParent) {
	//	mMatrix = mMatrix * mpParent->mMatrix;
	//}
}
//描画処理
void CCharacter::Render() {
	//?
	if (mpModel) {
		//モデルの描画
		mpModel->Render(mMatrix);
	}
}

//22
CCharacter::CCharacter()
//: mpParent(0)
//?
: mpModel(0)
, mTag(ENONE)
, mScale(1.0f, 1.0f, 1.0f)
{
	//タスクリストに追加
	CTaskManager::Get()->Add(this);
}
//22
CCharacter::~CCharacter() {
	//タスクリストから削除
	CTaskManager::Get()->Remove(this);
}
//
//void CCharacter::ChangePriority(int priority) {
//	TaskManager.Remove(this);
//	mPriority = priority;
//	TaskManager.Add(this);
//}
