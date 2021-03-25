#include "../GameApp.h"
#include "../Scene/SceneManager.h"
#include "DxLib.h"

// ウィンドウの設定
static const int WINDOW_WIDTH			= 400;
static const int WINDOW_HEIGHT			= 600;
static const int WINDOW_COLOR_BIT_DEPTH = 32;

//
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// ウィンドウの設定
	SetMainWindowText("SPACE INVADERS");
	ChangeWindowMode(TRUE);
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);
	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_COLOR_BIT_DEPTH);

	// DxLib初期化
	if (DxLib_Init() == -1)	
	{
		return -1;
	}

	// 描画先画面をバックバッファに設定
	SetDrawScreen(DX_SCREEN_BACK);

	// タイトル表示
	SceneManager& sceneManager = g_GameApp.GetSceneManager();
	sceneManager.RequestNextScene(SceneManager::eSCENE_TYPE_GAME);

	//	メインループ
	for (;;)
	{
		MSG	msg;
		if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
		{
			if (!GetMessage(&msg, NULL, 0, 0))
			{
				break;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			// 画面のクリア
			ClearDrawScreen();

			// 更新処理
			sceneManager.Update();
			sceneManager.Render();

#if _DEBUG
			// FPSの描画
			DrawFormatString(0, 0, GetColor(255, 255, 255), "FPS:%f", GetFPS());
#endif
			// 裏画面の内容を表画面に反映
			ScreenFlip();
		}
	}

	// DxLib終了
	DxLib_End();

	return 0;
}