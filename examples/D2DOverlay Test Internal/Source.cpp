#include "DirectOverlay.h"

void drawLoop(int width, int height) {
	DrawLine(0, 0, 100, 100, 5, 1, 1, 0, .8);
	DrawString("The quick brown fox jumped over the lazy dog", 48, 100, 20, 0, 1, 1);
	DrawBox(100, 100, 100, 100, 5, 0, 1, 0, 1, 0);
	DrawCircle(50, 50, 20, 1, 1, 0, 0, .25, 1);
	DrawEllipse(500, 100, 50, 20, 5, 1, 0, 0, 1, 0);
}

DWORD WINAPI MainThread(LPVOID lpParam)
{
	DirectOverlaySetOption(D2DOV_DRAW_FPS | D2DOV_FONT_IMPACT);
	DirectOverlaySetup(drawLoop);
	for (;;) { Sleep(100); }
}

BOOL WINAPI DllMain(HINSTANCE hModule, DWORD dwAttached, LPVOID lpvReserved)
{
	if (dwAttached == DLL_PROCESS_ATTACH) {
		CreateThread(0, 0, MainThread, hModule, 0, NULL);
	}
	return 1;
}