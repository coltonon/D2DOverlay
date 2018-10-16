/*
	Direct2D Overlay by Coltonon
	Simple library used to make a Direct2d overlay over any application quickly.
	Simply set up your drawing loop, and initialize the overlay.

	Sample use:

-----------------------------------------------------------------------------------------
	#include "DirectOverlay.h"

	void drawLoop(int width, int height) {  // our loop to render in
		DrawString("The quick brown fox jumped over the lazy dog", 48, 100, 20, 0, 1, 1);
	}

	int main(){
		DirectOverlaySetOption(D2DOV_DRAW_FPS | D2DOV_FONT_IMPACT);	// set the font, and draw the fps
		DirectOverlaySetup(drawLoop);		// initialize our overlay
		getchar();	// The overlay operates in it's own thread, ours will continue as normal
	}
-----------------------------------------------------------------------------------------

	The #defines are settings for the window, pass them to the DirectOverlaySetOption function.
	You may OR them together '|', you must set them before calling DirectOverlaySetup.

*/

#include <Windows.h>
#include <string>

// Link the static library (make sure that file is in the same directory as this file)
#pragma comment(lib, "D2DOverlay.lib")

// Requires the targetted window to be active and the foreground window to draw.
#define D2DOV_REQUIRE_FOREGROUND	(1 << 0)

// Draws the FPS of the overlay in the top-right corner
#define D2DOV_DRAW_FPS				(1 << 1)

// Attempts to limit the frametimes so you don't render at 500fps
#define D2DOV_VSYNC					(1 << 2)

// Sets the text font to Calibri
#define D2DOV_FONT_CALIBRI			(1 << 3)

// Sets the text font to Arial
#define D2DOV_FONT_ARIAL			(1 << 4)

// Sets the text font to Courier
#define D2DOV_FONT_COURIER			(1 << 5)

// Sets the text font to Gabriola
#define D2DOV_FONT_GABRIOLA			(1 << 6)

// Sets the text font to Impact
#define D2DOV_FONT_IMPACT			(1 << 7)

// The function you call to set up the above options.  Make sure its called before the DirectOverlaySetup function
void DirectOverlaySetOption(DWORD option);

// typedef for the callback function, where you'll do the drawing.
typedef void(*DirectOverlayCallback)(int width, int height);

// Initializes a the overlay window, and the thread to run it.  Input your callback function.
// Uses the first window in the current process to target.  If you're external, use the next function
void DirectOverlaySetup(DirectOverlayCallback callbackFunction);

// Used to specify the window manually, to be used with externals.
void DirectOverlaySetup(DirectOverlayCallback callbackFunction, HWND targetWindow);

// Draws a line from (x1, y1) to (x2, y2), with a specified thickness.
// Specify the color, and optionally an alpha for the line.
void DrawLine(float x1, float y1, float x2, float y2, float thickness, float r, float g, float b, float a = 1);

// Draws a rectangle on the screen.  Width and height are relative to the coordinates of the box.  
// Use the "filled" bool to make it a solid rectangle; ignore the thickness.
// To just draw the border around the rectangle, specify a thickness and pass "filled" as false.
void DrawBox(float x, float y, float width, float height, float thickness, float r, float g, float b, float a, bool filled);

// Draws a circle.  As with the DrawBox, the "filled" bool will make it a solid circle, and thickness is only used when filled=false.
void DrawCircle(float x, float y, float radius, float thickness, float r, float g, float b, float a, bool filled);

// Allows you to draw an elipse.  Same as a circle, except you have two different radii, for width and height.
void DrawEllipse(float x, float y, float width, float height, float thickness, float r, float g, float b, float a, bool filled);

// Draw a string on the screen.  Input is in the form of an std::string.
void DrawString(std::string str, float fontSize, float x, float y, float r, float g, float b, float a = 1);