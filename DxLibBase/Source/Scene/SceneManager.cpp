#include "SceneManager.h"
#include "SceneTitle.h"
#include "SceneGame.h"
#include "DxLib.h"

//
SceneManager::SceneManager()
{
	m_pScene = nullptr;
	m_CurrentSceneType = m_NextSceneType = eSCENE_TYPE_NONE;
}

//
SceneManager::~SceneManager()
{
	if (m_pScene)
	{
		delete m_pScene;
		m_pScene = nullptr;
	}
}

//
void SceneManager::Update()
{
	// シーン変更
	ChangeNextScene();

	// 更新
	if (m_pScene)
	{
		m_pScene->Update();
	}
}

//
void SceneManager::Render()
{
	if (m_pScene)
	{
		m_pScene->Render();
	}
}

// シーンの変更
void SceneManager::RequestNextScene(eSCENE_TYPE sceneType)
{
	m_NextSceneType = sceneType;
}

// 次のシーンへ変更
void SceneManager::ChangeNextScene()
{
	if (m_CurrentSceneType == m_NextSceneType)
	{
		return;
	}

	if (m_pScene)
	{
		delete m_pScene;
		m_pScene = nullptr;
	}

	switch (m_NextSceneType)
	{
		case eSCENE_TYPE_TITLE: m_pScene = new SceneTitle();	break;
		case eSCENE_TYPE_GAME:	m_pScene = new SceneGame();		break;
		default: break;
	}

	if (m_pScene)
	{
		m_pScene->Initialize();
		m_CurrentSceneType = m_NextSceneType;
	}
}