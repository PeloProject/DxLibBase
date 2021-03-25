#pragma once
#include "Scene/SceneManager.h"

// ゲーム共有クラス
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
