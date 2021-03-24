#include "SceneGame.h"
#include "DxLib.h"

//
void SceneGame::Initialize()
{
}

//
void SceneGame::Update()
{
}

//
void SceneGame::Render()
{
	static int test = 320;
	test--;
	DrawPixel(test, 240, GetColor(255, 255, 255));	// “_‚ð‘Å‚Â

}