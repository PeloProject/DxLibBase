#include "SceneTitle.h"
#include "DxLib.h"
#include "../System/WinMain.h"
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
		AppSceneManager.RequestNextScene(SceneManager::eSCENE_TYPE_GAME);
	}
}

//
void SceneTitle::Render()
{
	// •¶Žš—ñ‚Ì•`‰æ
	DrawString(100, 240, "Hello World! Press A Key", GetColor(255, 255, 255));
}