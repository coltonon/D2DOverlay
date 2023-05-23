#include "..\..\DirectOverlay.h"

void drawLoop(int width, int height) {
	DrawLine(0, 0, 100, 100, 5, 1, 1, 0, .8);
	DrawString("The quick brown fox jumped over the lazy dog", 48, 100, 20, 0, 1, 1);
	DrawBox(100, 100, 100, 100, 5, 0, 1, 0, 1, 0);
	DrawCircle(50, 50, 20, 1, 1, 0, 0, .25, 1);
	DrawEllipse(500, 100, 50, 20, 5, 1, 0, 0, 1, 0);
}

HWND g_exitHwnd = NULL;
HWND getHwndCallback()
{
	HWND foreWin = GetForegroundWindow();
	if (g_exitHwnd && foreWin == g_exitHwnd)
	{
		DirectOverlayStop();
		return NULL;
	}
	return foreWin;
}

void main()
{
	//�������±����˳�
	g_exitHwnd = FindWindow(NULL, "�ޱ��� - ���±�");

	DirectOverlaySetOption(D2DOV_DRAW_FPS);
	DirectOverlaySetFontName(L"��������");
	DirectOverlaySetup(drawLoop, getHwndCallback);
	while (IsDirectOverlayRunning())
		Sleep(1000);
}
