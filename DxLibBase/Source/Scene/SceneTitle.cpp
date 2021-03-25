#include "SceneTitle.h"
#include "DxLib.h"
#include "../GameApp.h"

//
SceneTitle::SceneTitle()
{
}

//
SceneTitle::~SceneTitle()
{
}

//
void SceneTitle::Initialize()
{
}

//
void SceneTitle::Update()
{
	char buf[256];
	GetHitKeyStateAll(buf);
	if (buf[KEY_INPUT_A] == 1)
	{
		g_GameApp.GetSceneManager().RequestNextScene(SceneManager::eSCENE_TYPE_GAME);
	}
}

//
void SceneTitle::Render()
{
	DrawString(100, 240, "タイトルシーン", GetColor(255, 255, 255));
}
