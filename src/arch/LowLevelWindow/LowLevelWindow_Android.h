/* LowLevelWindow_Android - OpenGL GLES window driver. */

#ifndef LOW_LEVEL_WINDOW_ANDROID_H
#define LOW_LEVEL_WINDOW_ANDROID_H

#include "RageDisplay.h" // VideoModeParams
#include "LowLevelWindow_EGL.h"

#include "archutils/Android/Globals.cpp"

/**
 * \class LowLevelWindow_Android
 * \brief Low-Level window that builds on the EGL LLW core.
 **/
class LowLevelWindow_Android : public LowLevelWindow_EGL
{
public:
	LowLevelWindow_Android();
	~LowLevelWindow_Android();

    // Return NOPE if the video mode doesn't correspond to the current one.
    RString TryVideoMode(const VideoModeParams &p, bool &bNewDeviceOut) {}; // nop

    // Defined as =false upstream
	//bool IsSoftwareRenderer( RString &sError );

	// Return the current Android display resolution. Nothing more, nothing less.
	void GetDisplayResolutions( DisplayResolutions &out ) const;

    // Nope all the way.
    bool SupportsThreadedRendering(){return false;};
    void BeginConcurrentRenderingMainThread(){return false;};
    void EndConcurrentRenderingMainThread(){return false;};
    void BeginConcurrentRendering(){return false;};
    void EndConcurrentRendering(){return false;};

private:
	//bool m_bWasWindowed;

    EGLint GetAttibutesInitConfig();
    void PreContextSetup();

    EGLConfig* GetEGLConfig();
    EGLSurface GetEGLSurface();
    EGLDisplay* GetEGLDisplayContext();
    EGLNativeWindowType* GetEGLWindowContext();

	void InitializeConfig();
	VideoModeParams CurrentParams;
};

#ifdef ARCH_LOW_LEVEL_WINDOW
#error "More than one LowLevelWindow selected!"
#endif
#define ARCH_LOW_LEVEL_WINDOW LowLevelWindow_Android

#endif
/*
 * (c) 2014 Renaud Lepage
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, and/or sell copies of the Software, and to permit persons to
 * whom the Software is furnished to do so, provided that the above
 * copyright notice(s) and this permission notice appear in all copies of
 * the Software and that both the above copyright notice(s) and this
 * permission notice appear in supporting documentation.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT OF
 * THIRD PARTY RIGHTS. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR HOLDERS
 * INCLUDED IN THIS NOTICE BE LIABLE FOR ANY CLAIM, OR ANY SPECIAL INDIRECT
 * OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
 * OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */
