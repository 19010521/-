#ifndef CWATERGUN_H
#define CWATERGUN_H
#include"CCharacter.h"
#include"CCollider.h"
class CWaterGun :public CCharacter{
private:
	//コライダ
	CCollider mCollider;
	//三角形
	CTriangle mT;
	
	//幅と奥行きの設定
	//set(幅,奥行)
	
	//生存時間
	int mLife;

	float mVelovcityGun;
	//更新
	void Update();

	//衝突処理
	//Ccllision(コライダ1,コライダ2)
	void Collision(CCollider*m, CCollider*y);
	//描画
	void Render();
public:
	
	CWaterGun();
	CWaterGun(CModel *model, CVector position, CVector rotation, CVector scale);
	
	CVector mForward; //前方

	void Set(float w, float d);
};
#endif