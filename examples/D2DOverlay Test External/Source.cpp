#include "..\..\DirectOverlay.h"

void drawLoop(int width, int height) {
	DrawLine(0, 0, 100, 100, 5, 1, 1, 0, .8);
	DrawString("The quick brown fox jumped over the lazy dog", 48, 100, 20, 0, 1, 1);
	DrawBox(100, 100, 100, 100, 5, 0, 1, 0, 1, 0);
	DrawCircle(50, 50, 20, 1, 1, 0, 0, .25, 1);
	DrawEllipse(500, 100, 50, 20, 5, 1, 0, 0, 1, 0);
}

//HWND g_hwnd = NULL;
HWND getHwndCallback()
{
	return GetForegroundWindow();
	//return g_hwnd;
}

void main()
{
	//g_hwnd = FindWindow(NULL, "无标题 - 记事本");
	DirectOverlaySetOption(D2DOV_DRAW_FPS | D2DOV_FONT_IMPACT);
	DirectOverlaySetup(drawLoop, getHwndCallback);
	while (IsDirectOverlayRunning())
		Sleep(1000);
}
