#include "WinMain.h"
#include "DxLib.h"


// �E�B���h�E�̐ݒ�
static const int WINDOW_WIDTH			= 400;
static const int WINDOW_HEIGHT			= 600;
static const int WINDOW_COLOR_BIT_DEPTH = 32;

SceneManager g_SceneManager;


//
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// �E�B���h�E�̐ݒ�
	ChangeWindowMode(TRUE);
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);
	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_COLOR_BIT_DEPTH);

	// DxLib������
	if (DxLib_Init() == -1)	
	{
		return -1;
	}

	// �`����ʂ��o�b�N�o�b�t�@�ɐݒ�
	SetDrawScreen(DX_SCREEN_BACK);

	// �^�C�g���\��
	AppSceneManager.RequestNextScene(SceneManager::eSCENE_TYPE_TITLE);

	//	���C�����[�v
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
			// ��ʂ̃N���A
			ClearDrawScreen();

			// �X�V����
			AppSceneManager.Update();
			AppSceneManager.Render();

			// ����ʂ̓��e��\��ʂɔ��f
			ScreenFlip();
		}
	}

	// DxLib�I��
	DxLib_End();

	return 0;
}