#pragma once

#include "SceneBase.h"

class SceneManager
{
public:

	enum eSCENE_TYPE
	{
		eSCENE_TYPE_NONE,
		eSCENE_TYPE_TITLE,
		eSCENE_TYPE_GAME
	};

	SceneManager();
	virtual ~SceneManager();

	void Update();
	void Render();
	void RequestNextScene(eSCENE_TYPE sceneType);

private:

	void ChangeNextScene();

	//	�V�[��
	SceneBase*	m_pScene;

	//	�V�[���̃^�C�v
	eSCENE_TYPE	m_CurrentSceneType;
	eSCENE_TYPE	m_NextSceneType;
};

