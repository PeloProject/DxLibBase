#pragma once
#include "Scene/SceneManager.h"

// �Q�[�����L�N���X
class GameApp final
{
public:
	GameApp();
	~GameApp();

	SceneManager& GetSceneManager() { return m_SceneManager; }

private:

	SceneManager m_SceneManager;

};

extern GameApp g_GameApp;
