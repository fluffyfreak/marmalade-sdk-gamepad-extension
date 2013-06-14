/*
 * This file is part of the Marmalade SDK Code Samples.
 *
 * (C) 2001-2012 Marmalade. All Rights Reserved.
 *
 * This source code is intended only as a supplement to the Marmalade SDK.
 *
 * THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
 * KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
 * PARTICULAR PURPOSE.
 */

#include "IwGx.h"
#include "gamepad.h"

// Standard C-style entry point. This can take args if required.
int main()
{
	char buf [4096];
	uint32 i,j;
	uint32 num = gamepadGetNumDevices();

	// Initialise the IwGx drawing module
    IwGxInit();
	if (gamepadAvailable())
	{
		//gamepadInit();
	}

    // Set the background colour to (opaque) blue
    IwGxSetColClear(0, 0, 0xff, 0xff);
    // Loop forever, until the user or the OS performs some action to quit the app
    while (!s3eDeviceCheckQuitRequest())
    {
        // Clear the surface
        IwGxClear();

		if (!gamepadAvailable())
		{
	        IwGxPrintString(10, 10, "GamePad API is not available!");
		}
		else
		{
			gamepadUpdate();
			buf[0] = 0;
			for (i=0; i<num; ++i)
			{
				sprintf(buf+strlen(buf), "%d: id=0x%08X\n", i, gamepadGetDeviceId(i));
				uint32 numAxes  = gamepadGetNumAxes(i);
				sprintf(buf+strlen(buf), "%d axes\n", numAxes);
				for (j=0; j<numAxes && j<6; ++j)
				{
					sprintf(buf+strlen(buf), "axis %d: %f\n", j, gamepadGetAxis(i,j));
				}
				uint32 numButtons = gamepadGetNumButtons(i);
				uint32 b = gamepadGetButtons(i);
				sprintf(buf+strlen(buf), "%d buttons\n", numButtons);
				for (j=0; j<numButtons && j<32; ++j)
				{
					sprintf(buf+strlen(buf), (b&1)?"X":"-");
					b = b >> 1;
				}
				sprintf(buf+strlen(buf), "\n");
			}
			
			IwGxPrintString(10, 10, buf);
		}

        // Standard EGL-style flush of drawing to the surface
        IwGxFlush();

        // Standard EGL-style flipping of double-buffers
        IwGxSwapBuffers();

        // Sleep for 0ms to allow the OS to process events etc.
        s3eDeviceYield(0);
    }
	if (gamepadAvailable())
	{
		//gamepadTerminate();
	}
    // Shut down the IwGx drawing module
    IwGxTerminate();

    // Return
    return 0;
}