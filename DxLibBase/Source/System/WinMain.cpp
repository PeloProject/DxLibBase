#include "WinMain.h"
#include "DxLib.h"


// ウィンドウの設定
static const int WINDOW_WIDTH			= 400;
static const int WINDOW_HEIGHT			= 600;
static const int WINDOW_COLOR_BIT_DEPTH = 32;

SceneManager g_SceneManager;


//
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// ウィンドウの設定
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
	AppSceneManager.RequestNextScene(SceneManager::eSCENE_TYPE_TITLE);

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
			AppSceneManager.Update();
			AppSceneManager.Render();

			// 裏画面の内容を表画面に反映
			ScreenFlip();
		}
	}

	// DxLib終了
	DxLib_End();

	return 0;
}