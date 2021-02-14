#include "CSceneTitle.h"
#include"CRectangle.h"
#include "CKey.h"
#include"CTaskManager.h"

void CSceneTitle::Init() {
	//�e�N�X�`���t�@�C����ǂݍ���
	//�t�H���g�̐ݒ�
	CText::mFont.Load("FontG.tga");
	CText::mFont.SetRowCol(1, 4096 / 64);
	//�V�[���̐ݒ�
	mScene = ETITLE;
}

//�X�V�����̃I�[�o�[���C�h
void CSceneTitle::Update() {
	CTaskManager::Get()->Update();
	CTaskManager::Get()->Render();
	//2D�`��J�n
	Start2D(0, 800, 0, 600);
	
	CText::DrawString("FIGHT WATER",200,400,15,18);
	CText::DrawString("PUSH ENTER KEY", 280, 300, 15, 18);
	for (int i = 0; i < VectorRect.size(); i++){
		//�`�揈��
		VectorRect[i]->Render();
	}

	if (CKey::Once(VK_RETURN)) {
		//���̃V�[���̓Q�[��
		mScene = EGAME;
	}
	
	//2D�`��I��
	End2D();
	CTaskManager::Get()->Delete();
	return;
}
//���̃V�[���̎擾
CScene::EScene CSceneTitle::GetNextScene() {
	return mScene;
}
void CSceneTitle::Render(){

}
CSceneTitle::~CSceneTitle(){

//�S�ẴC���X�^���X���폜���܂�
	for (int i = 0; i < VectorRect.size(); i++){

		//�C���X�^���X�̍폜
		delete VectorRect[i];

	}
	//�ϒ��z��
	VectorRect.clear();
}
