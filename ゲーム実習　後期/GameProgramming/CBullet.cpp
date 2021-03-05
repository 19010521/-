#include"CBullet.h"

CBullet::CBullet()
:mLife(50),mCollider(this, CVector(0.0f, 0.0f, 0.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f, 1.0f, 1.0f), 0.1f)
{
	mCollider.mTag = CCollider::EINPACT;
}

//幅と奥行きの設定
//Set(幅,奥行き)
void CBullet::Set(float w, float d){
	//スケール設定
	mScale = CVector(1.0f, 1.0f, 1.0f);
	//三角形の頂点設定
	mT.SetVertex(CVector(w, 0.0f, 0.0f), CVector(-w, 0.0f, 0.0f), CVector(0.0f, 0.0f,d));
	//三角形の法線設定
	mT.SetNormal(CVector(0.0f, 1.0f, 0.0f));


}
//こうしん
void CBullet::Update(){

	//生存時間の判定
	if (mLife-- > 0){
		CCharacter::Update();
		//位置更新
		mPosition = CVector(0.0f, 0.0f, 1.0f)*mMatrix;
	}
	else{
		//無効にする
		SetEnabled(false);

	}

}
//衝突処理
//Ccllision(コライダ1,コライダ2)
void CBullet::Collision(CCollider*m, CCollider*y){
	//共に球コライダの時
	if (m->mType == CCollider::ESPHERE && y->mType == CCollider::ESPHERE){
		//コライダのｍとｙが衝突しているか判定
			if (y->mTag == CCollider::EPLAYEREBODY){
				if (CCollider::Collision(m, y)){
				//衝突しているときは無効にする
					SetEnabled(false);
			}
		}
	}
}
void CBullet::Render(){


	CCharacter::Render();
	//DIFFUSE黄色設定
	float c[] = { 1.0f, 1.0f, 0.0f, 1.0f };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, c);
	

	//三角形描画
	mT.Render(mMatrix);
	
	//mCollider.Render();
	
}