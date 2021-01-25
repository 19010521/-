#include "CWaterGun.h"
#include"CSceneGame.h"
#define G (9.8f/60.0f)//重力加速度
#define WATERV0 (1.0f)//水初速
CWaterGun::CWaterGun()
:mLife(30), mCollider(this, CVector(0.0f, 0.0f, 0.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f , 1.0f , 1.0f ),1.0f)
, mVelovcityGun(0), mForward(0.0f, 1.0f, 1.0f), x(1.0f)
{
	mpModel = &CSceneGame::mGun;
	mTag = EWATERGUN;
	mVelovcityGun = WATERV0;
	mForward.mY += mVelovcityGun;
	mCollider.mTag = CCollider::EWATER;
	
}
//幅と奥行きの設定
//Set(幅,奥行)
void CWaterGun::Set(float w, float d){

	//スケール設定
	mScale = CVector(1.0f, 1.0f, 1.0f);
	//三角形の頂点設定
	mT.SetVertex(CVector(w, 0.0f, 0.0f), CVector(-w, 0.0f, 0.0f), CVector(0.0f, 0.0f, d));
	//三角形の法線設定
	mT.SetNormal(CVector(0.0f, 1.0f, 0.0f));

}
//更新
void CWaterGun::Update(){

	
		mForward.mY -= G;
		//mVelovcityGun -= G;
		//位置更新
		mPosition +=mForward;
		
	
	////位置更新
	//生存時間の判定
	
		mScale = mScale*1.1f;
		mCollider.mRadius *= 1.1f;
	
		
		//生存時間の判定
		if (mLife-- > 0){
			CCharacter::Update();
		}
		else{
			//無効にする

			mEnabled = false;

		}

}
//衝突処理
//Collision(コライダ1,コライダ2)
void CWaterGun::Collision(CCollider *m, CCollider *y){

	//共に球コライダの時
	if (m->mType == CCollider::ESPHERE && y->mType == CCollider::ESPHERE){
		//コライダのｍとｙが衝突しているか判定
		if (CCollider::Collision(m, y)){
			if (y->mTag == CCollider::EENEMYBODY){
				//衝突しているときは無効にする
				mEnabled = false;
			}
		}
	}
	//自身コライダの判定タイプ
	switch (m->mType){
	case CCollider::ESPHERE://球コライダ
		//相手のコライダが三角コライダの時
		if (y->mType == CCollider::ETRIANGLE){
			CVector adjust;//調整用ベクトル		
			if (CCollider::CollisionTriangleSphere(y, m, &adjust)){
				//mEnabled = false;
				//mVelovcityGun = 0;
				//位置の更新
				//mPosition = mPosition - adjust*-1;
				//行列の更新
				CCharacter::Update();

			}

		}
		break;
	}

}

//描画
void CWaterGun::Render(){

	CCharacter::Render();
	//DIFUSE黄色設定
	float c[] = { 1.0f, 1.0f, 0.0f, 1.0f };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, c);

	//三角形描画
	mT.Render(mMatrix);
	//確認用メソッド
	//mCollider.Render();

}
