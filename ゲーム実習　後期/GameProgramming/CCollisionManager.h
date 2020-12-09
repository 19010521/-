#ifndef CCOLLISIONMANAGER_H
#define CCOLLISIONMANAGER_H
//タスクマネージャのインクルード
#include "CTaskManager.h"
#include"CCollider.h"
/*
コリジョンマネージャ
コライダのリスト管理
*/
class CCollisionManager : public CTaskManager {
public:
	//衝突処理
	void Collision();
	//Collision(コライダ）
	//コライダとの衝突処理を実行する

	void Collision(CCollider *collider);


};
//他で使えるように外部参照
extern CCollisionManager CollisionManager;

#endif
