#ifndef CSCENETITLE_H
#define CSCENETITLE_H

#include "CScene.h"

#include "CText.h"


class CSceneTitle : public CScene {
public:
	//�����������̃I�[�o�[���C�h
	void Init();
	//�X�V�����̃I�[�o�[���C�h
	void Update();

	void Render();

	
	~CSceneTitle();
	//���̃V�[���̎擾
	EScene GetNextScene();
};

#endif