#ifndef CCOLLISIONMANAGER_H
#define CCOLLISIONMANAGER_H
//�^�X�N�}�l�[�W���̃C���N���[�h
#include "CTaskManager.h"
#include"CCollider.h"
/*
�R���W�����}�l�[�W��
�R���C�_�̃��X�g�Ǘ�
*/
class CCollisionManager : public CTaskManager {
public:
	static CCollisionManager*instance;
	static CCollisionManager*Get();
	//�Փˏ���
	void Collision();
	void Destory();
	//Collision(�R���C�_�j
	//�R���C�_�Ƃ̏Փˏ��������s����

	void Collision(CCollider *collider);


};
//���Ŏg����悤�ɊO���Q��
//extern CCollisionManager CollisionManager;

#endif
