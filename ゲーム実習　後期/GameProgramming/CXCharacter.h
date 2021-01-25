#ifndef CXCHARACTER_H
#define CXCHARACTER_H

#include"CModelX.h"
#include"CMatrix.h"
#include"CCharacter.h"

class CXCharacter:public CCharacter{
public:
	CModelX *mpModel;  //モデルデータ

	CMatrix *mpCombinedMatrix;//合成行列退避

	int mAnimationIndex;  //アニメーション
	bool mAnimationLoopFlg;//true:アニメーション
	float mAnimationFrame;//アニメーションの再生フレーム
	float mAnimationFrameSize;//アニメーションの再生フレーム数
	CXCharacter()
		:mpCombinedMatrix(0)
	{

	}
	virtual~CXCharacter(){
		SAFE_DELETE_ARRAY(mpCombinedMatrix);
	}
	//初期化処理
	void Init(CModelX *model);
	//アニメーションの変更
	void ChangeAnimation(int index, bool ioop, float framesize);
	//更新処理
	void Update(CMatrix &m);
	void Update();
	//描画処理
    virtual void Render();

};
#endif