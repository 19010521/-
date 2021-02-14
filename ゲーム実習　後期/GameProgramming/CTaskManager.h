#ifndef CTASKMANAGER_H
#define CTASKMANAGER_H
//�^�X�N�N���X�̃C���N���[�h
#include "CTask.h"

/*
�^�X�N�}�l�[�W��
�^�X�N���X�g�̊Ǘ�
*/
class CTaskManager {
public:
	CTask *mpHead;	//�擪�|�C���^
//	CTask *mpTail;	//�Ō�|�C���^
	//static
	static CTaskManager*instance;
	static CTaskManager*Get();
	//�f�t�H���g�R���X�g���N�^
	CTaskManager();
	//�f�X�g���N�^
	virtual ~CTaskManager();
	//���X�g�ɒǉ�
	//Add(�^�X�N�̃|�C���^)
	void Add(CTask *task);
	//�X�V
	void Update();

	void Destory();

	void TaskCollision();
	//�`��
	void Render();
	//22
	//���X�g����폜
	//Remove(�^�X�N�̃|�C���^)
	void Remove(CTask *task);
	//22
	//�^�X�N�̍폜
	void Delete();
};

//�^�X�N�}�l�[�W��y�̊O���Q��
// CTaskManager TaskManager;

#endif
