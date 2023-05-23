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
	//遇到记事本则退出
	g_exitHwnd = FindWindow(NULL, "无标题 - 记事本");

	DirectOverlaySetOption(D2DOV_DRAW_FPS);
	DirectOverlaySetFontName(L"华文琥珀");
	DirectOverlaySetup(drawLoop, getHwndCallback);
	while (IsDirectOverlayRunning())
		Sleep(1000);
}
