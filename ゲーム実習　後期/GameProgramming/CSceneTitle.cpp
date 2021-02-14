#include "CSceneTitle.h"
#include"CRectangle.h"
#include "CKey.h"
#include"CTaskManager.h"

void CSceneTitle::Init() {
	//テクスチャファイルを読み込む
	//フォントの設定
	CText::mFont.Load("FontG.tga");
	CText::mFont.SetRowCol(1, 4096 / 64);
	//シーンの設定
	mScene = ETITLE;
}

//更新処理のオーバーライド
void CSceneTitle::Update() {
	CTaskManager::Get()->Update();
	CTaskManager::Get()->Render();
	//2D描画開始
	Start2D(0, 800, 0, 600);
	
	CText::DrawString("FIGHT WATER",200,400,15,18);
	CText::DrawString("PUSH ENTER KEY", 280, 300, 15, 18);
	for (int i = 0; i < VectorRect.size(); i++){
		//描画処理
		VectorRect[i]->Render();
	}

	if (CKey::Once(VK_RETURN)) {
		//次のシーンはゲーム
		mScene = EGAME;
	}
	
	//2D描画終了
	End2D();
	CTaskManager::Get()->Delete();
	return;
}
//次のシーンの取得
CScene::EScene CSceneTitle::GetNextScene() {
	return mScene;
}
void CSceneTitle::Render(){

}
CSceneTitle::~CSceneTitle(){

//全てのインスタンスを削除します
	for (int i = 0; i < VectorRect.size(); i++){

		//インスタンスの削除
		delete VectorRect[i];

	}
	//可変長配列
	VectorRect.clear();
}
