#include "CMaterial.h"
//memsetのインクルード
#include <string.h>

#include "glut.h"

//デフォルトコンストラクタ
CMaterial::CMaterial()
: mpTexture(0), mVertexNum(0)
{
	//名前を0で埋め
	memset(mName, 0, sizeof(mName));
	//0で埋める
	memset(mDiffuse, 0, sizeof(mDiffuse));
}

CMaterial::CMaterial(CModelX*model)
:mpTextureFilename(0)
{
	//CModelXにマテリアルを追加する
	model->mMaterial.push_back(this);
	model->GetToken();//{?Name
	if (strcmp(model->mToken, "{") != 0){
		//{でないときマテリアル名
		strcpy(mName, model->mToken);
		model->GetToken();//{

	}
	mDiffuse[0] = model->GetFloatToken();
	mDiffuse[1] = model->GetFloatToken();
	mDiffuse[2] = model->GetFloatToken();
	mDiffuse[3] = model->GetFloatToken();

	mPower = model->GetFloatToken();

	mSpeclar[0] = model->GetFloatToken();
	mSpeclar[1] = model->GetFloatToken();
	mSpeclar[2] = model->GetFloatToken();

	mEmissive[0] = model->GetFloatToken();
	mEmissive[1] = model->GetFloatToken();
	mEmissive[2] = model->GetFloatToken();

	model->GetToken();// TextureFilename or}

	if (strcmp(model->mToken, "TextureFilename") == 0){
		//テクスチャありの場合,テクスチャファイル名取得
		model->GetToken();//{
		model->GetToken();//filename
//		mpTextureFilename = new char[strlen(model->mToken) + 1];
//		strcpy(mpTextureFilename, model->mToken);
		//スマートポインタの生成
		std::shared_ptr<CTexture>t(new CTexture());
		//スマートポインタの代入
		mpTexture = t;
		//テクスチャファイルの読み込み
		t->Load(model->mToken);
		model->GetToken();//}
		model->GetToken();//}

	}

#ifdef _DEBUG

	printf("Material  \n");
	printf("Diffuse %f %f %f %f \n", mDiffuse[0], mDiffuse[1], mDiffuse[2], mDiffuse[3]);
	printf("Power %f \n", mPower);
	printf("Specular %f %f %f \n", mSpeclar[0], mSpeclar[1], mSpeclar[2]);
	printf("Emissive %f %f %f \n", mEmissive[0], mEmissive[1], mEmissive[2]);


#endif
}

//マテリアルを有効にする
void CMaterial::Enabled() {
	//アルファブレンドを有効にする
	glEnable(GL_BLEND);
	//ブレンド方法を指定
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//拡散光の設定
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mDiffuse);
	//テクスチャが無い時、戻る
	if (mpTexture == 0)
		return;
	//テクスチャ有り
	if (mpTexture->mId) {
		//テクスチャを使用可能にする
		glEnable(GL_TEXTURE_2D);
		//テクスチャをバインドする
		glBindTexture(GL_TEXTURE_2D, mpTexture->mId);
	}
}
//マテリアルを無効にする
void CMaterial::Disabled() {
	//アルファブレンドを無効
	glDisable(GL_BLEND);
	//テクスチャが無い時、戻る
	if (mpTexture == 0)
		return;
	//テクスチャ有り
	if (mpTexture->mId) {
		//テクスチャのバインドを解く
		glBindTexture(GL_TEXTURE_2D, 0);
		//テクスチャを無効にする
		glDisable(GL_TEXTURE_2D);
	}
}
