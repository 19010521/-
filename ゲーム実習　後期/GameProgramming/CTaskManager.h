#ifndef CTASKMANAGER_H
#define CTASKMANAGER_H
//タスククラスのインクルード
#include "CTask.h"

/*
タスクマネージャ
タスクリストの管理
*/
class CTaskManager {
public:
	CTask *mpHead;	//先頭ポインタ
//	CTask *mpTail;	//最後ポインタ
	//static
	static CTaskManager*instance;
	static CTaskManager*Get();
	//デフォルトコンストラクタ
	CTaskManager();
	//デストラクタ
	virtual ~CTaskManager();
	//リストに追加
	//Add(タスクのポインタ)
	void Add(CTask *task);
	//更新
	void Update();

	void Destory();

	void TaskCollision();
	//描画
	void Render();
	//22
	//リストから削除
	//Remove(タスクのポインタ)
	void Remove(CTask *task);
	//22
	//タスクの削除
	void Delete();
};

//タスクマネージャyの外部参照
// CTaskManager TaskManager;

#endif
