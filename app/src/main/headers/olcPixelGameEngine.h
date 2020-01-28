/*
 olcPixelGameEngine.h
 
 +-------------------------------------------------------------+
 |           OneLoneCoder Pixel Game Engine v1.17              |
 | "Like the command prompt console one, but not..." - javidx9 |
 +-------------------------------------------------------------+
 
 What is this?
 ~~~~~~~~~~~~~
 The olcConsoleGameEngine has been a surprising and wonderful success for me,
 and I'm delighted how people have reacted so positively towards it, so thanks
 for that.
 
 However, there are limitations that I simply cannot avoid. Firstly, I need to
 maintain several different versions of it to accommodate users on Windows7,
 8, 10, Linux, Mac, Visual Studio & Code::Blocks. Secondly, this year I've been
 pushing the console to the limits of its graphical capabilities	and the effect
 is becoming underwhelming. The engine itself is not slow at all, but the process
 that Windows uses to draw the command prompt to the screen is, and worse still,
 it's dynamic based upon the variation of character colours and glyphs. Sadly
 I have no control over this, and recent videos that are extremely graphical
 (for a command prompt :P ) have been dipping to unacceptable framerates. As
 the channel	has been popular with aspiring game developers, I'm concerned that
 the visual appeal of the command prompt is perhaps limited to us oldies, and I
 dont want to alienate younger learners. Finally, I'd like to demonstrate many
 more algorithms and image processing that exist in the graphical domain, for
 which the console is insufficient.
 
 For this reason, I have created olcPixelGameEngine! The look and feel to the
 programmer is almost identical, so all of my existing code from the videos is
 easily portable, and the programmer uses this file in exactly the same way. But
 I've decided that rather than just build a command prompt emulator,	that I
 would at least harness some modern(ish) portable technologies.
 
 As a result, the olcPixelGameEngine supports 32-bit colour, is written in a
 cross-platform style, uses modern(ish) C++ conventions and most importantly,
 renders much much faster. I	will use this version when my applications are
 predominantly graphics based, but use the console version when they are
 predominantly text based - Don't worry, loads more command prompt silliness to
 come yet, but evolution is important!!
 
 License (OLC-3)
 ~~~~~~~~~~~~~~~
 
 Copyright 2018 - 2019 OneLoneCoder.com
 
 Redistribution and use in source and binary forms, with or without modification,
 are permitted provided that the following conditions are met:
 
 1. Redistributions or derivations of source code must retain the above copyright
 notice, this list of conditions and the following disclaimer.
 
 2. Redistributions or derivative works in binary form must reproduce the above
 copyright notice. This list of conditions and the following	disclaimer must be
 reproduced in the documentation and/or other materials provided with the distribution.
 
 3. Neither the name of the copyright holder nor the names of its contributors may
 be used to endorse or promote products derived from this software without specific
 prior written permission.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS	"AS IS" AND ANY
 EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 SHALL THE COPYRIGHT	HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 INCIDENTAL,	SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 CONTRACT, STRICT LIABILITY, OR TORT	(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 SUCH DAMAGE.
 
 Links
 ~~~~~
 YouTube:	https://www.youtube.com/javidx9
 https://www.youtube.com/javidx9extra
 Discord:	https://discord.gg/WhwHUMV
 Twitter:	https://www.twitter.com/javidx9
 Twitch:		https://www.twitch.tv/javidx9
 GitHub:		https://www.github.com/onelonecoder
 Homepage:	https://www.onelonecoder.com
 Patreon:	https://www.patreon.com/javidx9
 
 Relevant Videos
 ~~~~~~~~~~~~~~~
 https://youtu.be/kRH6oJLFYxY Introducing olcPixelGameEngine
 
 Compiling in Linux
 ~~~~~~~~~~~~~~~~~~
 You will need a modern C++ compiler, so update yours!
 To compile use the command:
 
 g++ -o YourProgName YourSource.cpp -lX11 -lGL -lpthread -lpng
 
 On some Linux configurations, the frame rate is locked to the refresh
 rate of the monitor. This engine tries to unlock it but may not be
 able to, in which case try launching your program like this:
 
 vblank_mode=0 ./YourProgName
 
 
 Compiling in Code::Blocks on Windows
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 Well I wont judge you, but make sure your Code::Blocks installation
 is really up to date - you may even consider updating your C++ toolchain
 to use MinGW32-W64, so google this. You will also need to enable C++14
 in your build options, and add to your linker the following libraries:
 user32 gdi32 opengl32 gdiplus
 
 Ports
 ~~~~~
 olc::PixelGameEngine has been ported and tested with varying degrees of
 success to: WinXP, Win7, Win8, Win10, Various Linux, Rapberry Pi,
 Chromebook, Playstation Portable (PSP) and Nintendo Switch. If you are
 interested in the details of these ports, come and visit the Discord!
 
 Thanks
 ~~~~~~
 I'd like to extend thanks to Eremiell, slavka, gurkanctn, Phantim,
 JackOJC, KrossX, Huhlig, Dragoneye, Appa, JustinRichardsMusic, SliceNDice
 Ralakus, Gorbit99, raoul, joshinils, benedani & MagetzUb for advice, ideas and
 testing, and I'd like to extend my appreciation to the 40K YouTube followers,
 22 Patreons and 2.6K Discord server	members who give me the motivation to keep
 going with all this :D
 
 Special thanks to those who bring gifts!
 GnarGnarHead.......Domina
 Gorbit99...........Bastion, Ori & The Blind Forest
 Marti Morta........Gris
 
 Special thanks to my Patreons too - I wont name you on here, but I've
 certainly enjoyed my tea and flapjacks :D
 
 Author
 ~~~~~~
 David Barr, aka javidx9, �OneLoneCoder 2018, 2019
 */

//////////////////////////////////////////////////////////////////////////////////////////

/* Example Usage (main.cpp)
 #define OLC_PGE_APPLICATION
 #include "olcPixelGameEngine.h"
 // Override base class with your custom functionality
 class Example : public olc::PixelGameEngine
 {
 public:
 Example()
 {
 sAppName = "Example";
 }
 public:
 bool OnUserCreate() override
 {
 // Called once at the start, so create things here
 return true;ƒ
 }
 bool OnUserUpdate(float fElapsedTime) override
 {
 // called once per frame, draws random coloured pixels
 for (int x = 0; x < ScreenWidth(); x++)
 for (int y = 0; y < ScreenHeight(); y++)
 Draw(x, y, olc::Pixel(rand() % 255, rand() % 255, rand()% 255));
 return true;
 }
 };
 int main()
 {
 Example demo;
 if (demo.Construct(256, 240, 4, 4))
 demo.Start();
 return 0;
 }
 */
#ifndef OLC_PGE_DEF

#define OLC_PGE_DEF

// RLP: Moved as much as possible arch-dependent code into sepearate files

#ifdef _WIN32
	#include "arch/win32/windows.h"
#elif __APPLE__
	#include "arch/apple/apple.h"
#elif ANDROID
	#include "arch/android/android.h"
#elif LINUX
	#include "arch/linux/linux.h.h"
#endif


// Standard includes
#include <cmath>
#include <cstdint>
#include <string>
#include <iostream>
#include <streambuf>
#include <chrono>
#include <vector>
#include <list>
#include <thread>
#include <atomic>
#include <condition_variable>
#include <fstream>
#include <map>
#include <functional>
#include <algorithm>

#undef min
#undef max

namespace olc // All OneLoneCoder stuff will now exist in the "olc" namespace
{
	struct Pixel {
		union {
			uint32_t n = 0xFF000000;
			struct {
				uint8_t r;
				uint8_t g;
				uint8_t b;
				uint8_t a;
			};
		};

		Pixel();

		Pixel(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255);

		Pixel(uint32_t p);

		enum Mode {
			NORMAL, MASK, ALPHA, CUSTOM
		};
	};

	// Some constants for symbolic naming of Pixels
	static const Pixel
			WHITE(255, 255, 255),
			GREY(192, 192, 192), DARK_GREY(128, 128, 128), VERY_DARK_GREY(64, 64, 64),
			RED(255, 0, 0), DARK_RED(128, 0, 0), VERY_DARK_RED(64, 0, 0),
			YELLOW(255, 255, 0), DARK_YELLOW(128, 128, 0), VERY_DARK_YELLOW(64, 64, 0),
			GREEN(0, 255, 0), DARK_GREEN(0, 128, 0), VERY_DARK_GREEN(0, 64, 0),
			CYAN(0, 255, 255), DARK_CYAN(0, 128, 128), VERY_DARK_CYAN(0, 64, 64),
			BLUE(0, 0, 255), DARK_BLUE(0, 0, 128), VERY_DARK_BLUE(0, 0, 64),
			MAGENTA(255, 0, 255), DARK_MAGENTA(128, 0, 128), VERY_DARK_MAGENTA(64, 0, 64),
			BLACK(0, 0, 0),
			BLANK(0, 0, 0, 0);

	enum rcode {
		FAIL = 0,
		OK = 1,
		NO_FILE = -1,
	};

	//==================================================================================

	template<class T>
	struct v2d_generic {
		T x = 0;
		T y = 0;

		inline v2d_generic() : x(0), y(0) {}

		inline v2d_generic(T _x, T _y) : x(_x), y(_y) {}

		inline v2d_generic(const v2d_generic &v) : x(v.x), y(v.y) {}

		inline T mag() { return sqrt(x * x + y * y); }

		inline v2d_generic norm() {
			T r = 1 / mag();
			return v2d_generic(x * r, y * r);
		}

		inline v2d_generic perp() { return v2d_generic(-y, x); }

		inline T dot(const v2d_generic &rhs) { return this->x * rhs.x + this->y * rhs.y; }

		inline T cross(const v2d_generic &rhs) { return this->x * rhs.y - this->y * rhs.x; }

		inline v2d_generic operator+(const v2d_generic &rhs) const {
			return v2d_generic(this->x + rhs.x, this->y + rhs.y);
		}

		inline v2d_generic operator-(const v2d_generic &rhs) const {
			return v2d_generic(this->x - rhs.x, this->y - rhs.y);
		}

		inline v2d_generic operator*(const T &rhs) const {
			return v2d_generic(this->x * rhs, this->y * rhs);
		}

		inline v2d_generic operator/(const T &rhs) const {
			return v2d_generic(this->x / rhs, this->y / rhs);
		}

		inline v2d_generic &operator+=(const v2d_generic &rhs) {
			this->x += rhs.x;
			this->y += rhs.y;
			return *this;
		}

		inline v2d_generic &operator-=(const v2d_generic &rhs) {
			this->x -= rhs.x;
			this->y -= rhs.y;
			return *this;
		}

		inline v2d_generic &operator*=(const T &rhs) {
			this->x *= rhs;
			this->y *= rhs;
			return *this;
		}

		inline v2d_generic &operator/=(const T &rhs) {
			this->x /= rhs;
			this->y /= rhs;
			return *this;
		}

		inline T &operator[](std::size_t i) {
			return *((T *) this + i);       /* <-- D'oh :( */        }
	};

	template<class T>
	inline v2d_generic<T> operator*(const float &lhs, const v2d_generic<T> &rhs) {
		return v2d_generic<T>(lhs * rhs.x, lhs * rhs.y);
	}

	template<class T>
	inline v2d_generic<T> operator*(const double &lhs, const v2d_generic<T> &rhs) {
		return v2d_generic<T>(lhs * rhs.x, lhs * rhs.y);
	}

	template<class T>
	inline v2d_generic<T> operator*(const int &lhs, const v2d_generic<T> &rhs) {
		return v2d_generic<T>(lhs * rhs.x, lhs * rhs.y);
	}

	template<class T>
	inline v2d_generic<T> operator/(const float &lhs, const v2d_generic<T> &rhs) {
		return v2d_generic<T>(lhs / rhs.x, lhs / rhs.y);
	}

	template<class T>
	inline v2d_generic<T> operator/(const double &lhs, const v2d_generic<T> &rhs) {
		return v2d_generic<T>(lhs / rhs.x, lhs / rhs.y);
	}

	template<class T>
	inline v2d_generic<T> operator/(const int &lhs, const v2d_generic<T> &rhs) {
		return v2d_generic<T>(lhs / rhs.x, lhs / rhs.y);
	}

	typedef v2d_generic<int> vi2d;
	typedef v2d_generic<float> vf2d;
	typedef v2d_generic<double> vd2d;

	//=============================================================

	struct HWButton {
		bool bPressed = false;    // Set once during the frame the event occurs
		bool bReleased = false;    // Set once during the frame the event occurs
		bool bHeld = false;        // Set true for all frames between pressed and released events
	};

	//=============================================================


	class ResourcePack {
	public:
		ResourcePack();

		~ResourcePack();

		struct sEntry : public std::streambuf {
			uint32_t nID, nFileOffset, nFileSize;
			uint8_t *data;

			void _config() {
				this->setg((char *) data, (char *) data, (char *) (data + nFileSize));
			}
		};

	public:
		olc::rcode AddToPack(std::string sFile);

	public:
		olc::rcode SavePack(std::string sFile);

		olc::rcode LoadPack(std::string sFile);

		olc::rcode ClearPack();

	public:
		olc::ResourcePack::sEntry GetStreamBuffer(std::string sFile);

	private:

		std::map<std::string, sEntry> mapFiles;
	};

	//=============================================================

	// A bitmap-like structure that stores a 2D array of Pixels
	class Sprite {
	public:
		Sprite();

		Sprite(std::string sImageFile);

		Sprite(std::string sImageFile, olc::ResourcePack *pack);

		Sprite(int32_t w, int32_t h);

		~Sprite();

	public:
		olc::rcode LoadFromFile(std::string sImageFile, olc::ResourcePack *pack = nullptr);

		olc::rcode LoadFromPGESprFile(std::string sImageFile, olc::ResourcePack *pack = nullptr);

		olc::rcode SaveToPGESprFile(std::string sImageFile);

		void clear(Pixel color);

		void fade(float perc);

	public:
		int32_t width = 0;
		int32_t height = 0;
		enum Mode {
			NORMAL, PERIODIC
		};

	public:
		void SetSampleMode(olc::Sprite::Mode mode = olc::Sprite::Mode::NORMAL);

		Pixel GetPixel(int32_t x, int32_t y);

		bool SetPixel(int32_t x, int32_t y, Pixel p);

		Pixel Sample(float x, float y);

		Pixel SampleBL(float u, float v);

		Pixel *GetData();

	private:
		Pixel *pColData = nullptr;
		Mode modeSample = Mode::NORMAL;

#ifdef OLC_DBG_OVERDRAW
		public:
		static int nOverdrawCount;
#endif

	};

	//=============================================================

	enum Key {
		NONE,
		A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
		K0, K1, K2, K3, K4, K5, K6, K7, K8, K9,
		F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
		UP, DOWN, LEFT, RIGHT,
		SPACE, TAB, SHIFT, CTRL, INS, DEL, HOME, END, PGUP, PGDN,
		BACK, ESCAPE, RETURN, ENTER, PAUSE, SCROLL,
		NP0, NP1, NP2, NP3, NP4, NP5, NP6, NP7, NP8, NP9,
		NP_MUL, NP_DIV, NP_ADD, NP_SUB, NP_DECIMAL,
	};


	//=============================================================

	class PixelGameEngine {

	public:
		PixelGameEngine();


	public:
		olc::rcode
		Construct(uint32_t screen_w, uint32_t screen_h, uint32_t pixel_w, uint32_t pixel_h,
				  bool full_screen = false);

		olc::rcode Start();

	public: // Override Interfaces
		// Called once on application startup, use to load your resources
		virtual bool OnUserCreate();

		// Called every frame, and provides you with a time per frame value
		virtual bool OnUserUpdate(float fElapsedTime);

		// Called once on application termination, so you can be a clean coder
		virtual bool OnUserDestroy();

	public: // Hardware Interfaces
		// Returns true if window is currently in focus
		bool IsFocused();

		// Get the state of a specific keyboard button
		HWButton GetKey(Key k);

		// Get the state of a specific mouse button
		HWButton GetMouse(uint32_t b);

		// Get Mouse X coordinate in "pixel" space
		int32_t GetMouseX();

		// Get Mouse Y coordinate in "pixel" space
		int32_t GetMouseY();

		// Get Mouse Wheel Delta
		int32_t GetMouseWheel();

	public: // Utility
		// Returns the width of the screen in "pixels"
		int32_t ScreenWidth();

		// Returns the height of the screen in "pixels"
		int32_t ScreenHeight();

		// Returns the width of the currently selected drawing target in "pixels"
		int32_t GetDrawTargetWidth();

		// Returns the height of the currently selected drawing target in "pixels"
		int32_t GetDrawTargetHeight();

		// Returns the currently active draw target
		Sprite *GetDrawTarget();

	public: // Draw Routines
		// Specify which Sprite should be the target of drawing functions, use nullptr
		// to specify the primary screen
		void SetDrawTarget(Sprite *target);

		// Change the pixel mode for different optimisations
		// olc::Pixel::NORMAL = No transparency
		// olc::Pixel::MASK   = Transparent if alpha is < 255
		// olc::Pixel::ALPHA  = Full transparency
		void SetPixelMode(Pixel::Mode m);

		Pixel::Mode GetPixelMode();

		// Use a custom blend function
		void SetPixelMode(
				std::function<olc::Pixel(const int x, const int y, const olc::Pixel &pSource,
										 const olc::Pixel &pDest)> pixelMode);

		// Change the blend factor form between 0.0f to 1.0f;
		void SetPixelBlend(float fBlend);

		// Offset texels by sub-pixel amount (advanced, do not use)
		void SetSubPixelOffset(float ox, float oy);

		// Draws a single Pixel
		virtual bool Draw(int32_t x, int32_t y, Pixel p = olc::WHITE);

		// Draws a line from (x1,y1) to (x2,y2)
		void DrawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2, Pixel p = olc::WHITE,
					  uint32_t pattern = 0xFFFFFFFF);

		// Draws a circle located at (x,y) with radius
		void
		DrawCircle(int32_t x, int32_t y, int32_t radius, Pixel p = olc::WHITE, uint8_t mask = 0xFF);

		// Fills a circle located at (x,y) with radius
		void FillCircle(int32_t x, int32_t y, int32_t radius, Pixel p = olc::WHITE);

		// Draws a rectangle at (x,y) to (x+w,y+h)
		void DrawRect(int32_t x, int32_t y, int32_t w, int32_t h, Pixel p = olc::WHITE);

		// Fills a rectangle at (x,y) to (x+w,y+h)
		void FillRect(int32_t x, int32_t y, int32_t w, int32_t h, Pixel p = olc::WHITE);

		// Draws a triangle between points (x1,y1), (x2,y2) and (x3,y3)
		void DrawTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3,
						  Pixel p = olc::WHITE);

		// Flat fills a triangle between points (x1,y1), (x2,y2) and (x3,y3)
		void FillTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3,
						  Pixel p = olc::WHITE);

		// Draws an entire sprite at location (x,y)
		void DrawSprite(int32_t x, int32_t y, Sprite *sprite, uint32_t scale = 1);

		// Draws an area of a sprite at location (x,y), where the
		// selected area is (ox,oy) to (ox+w,oy+h)
		void
		DrawPartialSprite(int32_t x, int32_t y, Sprite *sprite, int32_t ox, int32_t oy, int32_t w,
						  int32_t h, uint32_t scale = 1);

		// Draws a single line of text
		void DrawString(int32_t x, int32_t y, std::string sText, Pixel col = olc::WHITE,
						uint32_t scale = 1);

		// Clears entire draw target to Pixel
		void Clear(Pixel p);

	public: // Branding
		std::string sAppName;
		static std::string ROOTPATH;	// BASE system dir

	private: // Inner mysterious workings
		Sprite *pDefaultDrawTarget = nullptr;
		Sprite *pDrawTarget = nullptr;
		Pixel::Mode nPixelMode = Pixel::NORMAL;
		float fBlendFactor = 1.0f;
		uint32_t nScreenWidth = 256;
		uint32_t nScreenHeight = 240;
		uint32_t nPixelWidth = 4;
		uint32_t nPixelHeight = 4;
		int32_t nMousePosX = 0;
		int32_t nMousePosY = 0;
		int32_t nMouseWheelDelta = 0;
		int32_t nMousePosXcache = 0;
		int32_t nMousePosYcache = 0;
		int32_t nMouseWheelDeltaCache = 0;
		int32_t nWindowWidth = 0;
		int32_t nWindowHeight = 0;
		int32_t nViewX = 0;
		int32_t nViewY = 0;
		int32_t nViewW = 0;
		int32_t nViewH = 0;
		bool bFullScreen = false;
		float fPixelX = 1.0f;
		float fPixelY = 1.0f;
		float fSubPixelOffsetX = 0.0f;
		float fSubPixelOffsetY = 0.0f;
		bool bHasInputFocus = false;
		bool bHasMouseFocus = false;
		float fFrameTimer = 1.0f;
		int nFrameCount = 0;
		Sprite *fontSprite = nullptr;
		std::function<olc::Pixel(const int x, const int y, const olc::Pixel &,
								 const olc::Pixel &)> funcPixelMode;

		static std::map<uint16_t, uint8_t> mapKeys;
		bool pKeyNewState[256]{0};
		bool pKeyOldState[256]{0};
		HWButton pKeyboardState[256];

		bool pMouseNewState[5]{0};
		bool pMouseOldState[5]{0};
		HWButton pMouseState[5];


#ifdef _WIN32
				HDC			glDeviceContext = nullptr;
				HGLRC		glRenderContext = nullptr;
		#elif defined  __APPLE__ || defined ANDROID

				unsigned int vao;
				unsigned int vbo;
				unsigned int ebo;

			protected: // RLP so derived classes can use their own shader
				unsigned int shader;

			private:
				unsigned int texture1;
				float vertices[32]{
						// positions          // colors           // texture coords
						1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // top right
						1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // bottom right
						-1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
						-1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f  // top left
				};
				unsigned int indices[6]{
						0, 1, 3, // first triangle
						1, 2, 3  // second triangle
				};
		#elif LINUX
				GLXContext	glDeviceContext = nullptr;
				GLXContext	glRenderContext = nullptr;
		#endif

		GLuint glBuffer;

		void EngineThread();

		// If anything sets this flag to false, the engine
		// "should" shut down gracefully
		static std::atomic<bool> bAtomActive;

		// Common initialisation functions
		void olc_UpdateMouse(int32_t x, int32_t y);

		void olc_UpdateMouseWheel(int32_t delta);

		void olc_UpdateWindowSize(int32_t x, int32_t y);

		void olc_UpdateViewport();

	protected:
		// RLP override to set shader
		virtual bool olc_OpenGLCreate();

	public:

		// RLP EngineThread parts
		bool olca_thread_init();
		bool olca_thread_tick(float fElapsedTime);
		void olca_thread_deinit();

	private:

		void olc_ConstructFontSheet();



#ifdef _WIN32
		// Windows specific window handling
		HWND olc_hWnd = nullptr;
		HWND olc_WindowCreate();
		std::wstring wsAppName;
		static LRESULT CALLBACK olc_WindowEvent(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
#elif  __APPLE__
		// Mac specific window handling
		olc::rcode olc_WindowCreate();
		void olc_ProcessWindowEvents();
#elif ANDROID
		// Android specific window handling + platform helpers
		olc::rcode olc_WindowCreate();
		void olc_ProcessWindowEvents();
		
	public:

		static PixelGameEngine *BOOTINSTANCE;	// OLC engine to run

		void olca_on_motionevent(MotionEvent_t event);

	private:
		LoneScreenKey 	*cLoneKeys;				// screenkeys helper class
		LoneSensor		*pLoneSensor;			// gyroscope joystick helper class
		ASensorEvent	tCurrentEvent;			// current sensor event
#elif LINUX
		// Non-Windows specific window handling
		Display*				olc_Display = nullptr;
		Window					olc_WindowRoot;
		Window					olc_Window;
		XVisualInfo*            olc_VisualInfo;
		Colormap                olc_ColourMap;
		XSetWindowAttributes    olc_SetWindowAttribs;
		Display*				olc_WindowCreate();
#endif

	};


	class PGEX {
		friend class olc::PixelGameEngine;

	protected:
		static PixelGameEngine *pge;
	};

	//=============================================================
}

#endif // OLC_PGE_DEF




/*
 Object Oriented Mode
 ~~~~~~~~~~~~~~~~~~~~
 
 If the olcPixelGameEngine.h is called from several sources it can cause
 multiple definitions of objects. To prevent this, ONLY ONE of the pathways
 to including this file must have OLC_PGE_APPLICATION defined before it. This prevents
 the definitions being duplicated.
 
 If all else fails, create a file called "olcPixelGameEngine.cpp" with the following
 two lines. Then you can just #include "olcPixelGameEngine.h" as normal without worrying
 about defining things. Dont forget to include that cpp file as part of your build!
 
 #define OLC_PGE_APPLICATION
 #include "olcPixelGameEngine.h"
 
 */

#ifdef OLC_PGE_APPLICATION
#undef OLC_PGE_APPLICATION

namespace olc {

	Pixel::Pixel() {
		r = 0;
		g = 0;
		b = 0;
		a = 255;
	}

	Pixel::Pixel(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) {
		r = red;
		g = green;
		b = blue;
		a = alpha;
	}

	Pixel::Pixel(uint32_t p) {
		n = p;
	}

	//==========================================================

	template<typename T>
	inline void fillarray(T *buffer, const T &value, size_t count) {
		for (int i = 0; i < count; ++i)
			buffer[i] = value;
	}

	std::wstring ConvertS2W(std::string s) {
#ifdef _WIN32
		int count = MultiByteToWideChar(CP_UTF8, 0, s.c_str(), -1, NULL, 0);
		wchar_t* buffer = new wchar_t[count];
		MultiByteToWideChar(CP_UTF8, 0, s.c_str(), -1, buffer, count);
		std::wstring w(buffer);
		delete[] buffer;
		return w;
#else
		return L"SVN FTW!";
#endif
	}

	Sprite::Sprite() {
		pColData = nullptr;
		width = 0;
		height = 0;
	}

	Sprite::Sprite(std::string sImageFile) {
		LoadFromFile(sImageFile);
	}

	Sprite::Sprite(std::string sImageFile, olc::ResourcePack *pack) {
		LoadFromPGESprFile(sImageFile, pack);
	}

	Sprite::Sprite(int32_t w, int32_t h) {
		if (pColData) delete[] pColData;
		width = w;
		height = h;
		pColData = new Pixel[width * height];
		for (int32_t i = 0; i < width * height; i++)
			pColData[i] = Pixel();
	}

	Sprite::~Sprite() {
		if (pColData) delete pColData;
	}

	// RLP fade sprite instead of clearing
	inline void fadearray(Pixel *buffer, const float value, size_t count) {
		for (int i = 0; i < count; ++i)
			buffer[i].a = (int) (buffer[i].a * value);
	}

	void Sprite::clear(olc::Pixel pixel) {
		fillarray(pColData, pixel, width * height);
	}

	void Sprite::fade(float perc) {
		fadearray(pColData, perc, width * height);
	}

	olc::rcode Sprite::LoadFromPGESprFile(std::string sImageFile, olc::ResourcePack *pack) {
		if (pColData) delete[] pColData;

		auto ReadData = [&](std::istream &is) {
			is.read((char *) &width, sizeof(int32_t));
			is.read((char *) &height, sizeof(int32_t));
			pColData = new Pixel[width * height];
			is.read((char *) pColData, width * height * sizeof(uint32_t));
		};

		// These are essentially Memory Surfaces represented by olc::Sprite
		// which load very fast, but are completely uncompressed
		if (pack == nullptr) {
			std::ifstream ifs;
			ifs.open(sImageFile, std::ifstream::binary);
			if (ifs.is_open()) {
				ReadData(ifs);
				return olc::OK;
			} else
				return olc::FAIL;
		} else {
			auto streamBuffer = pack->GetStreamBuffer(sImageFile);
			std::istream is(&streamBuffer);
			ReadData(is);
		}


		return olc::FAIL;
	}

	olc::rcode Sprite::SaveToPGESprFile(std::string sImageFile) {
		if (pColData == nullptr) return olc::FAIL;

		std::ofstream ofs;
		ofs.open(sImageFile, std::ifstream::binary);
		if (ofs.is_open()) {
			ofs.write((char *) &width, sizeof(int32_t));
			ofs.write((char *) &height, sizeof(int32_t));
			ofs.write((char *) pColData, width * height * sizeof(uint32_t));
			ofs.close();
			return olc::OK;
		}

		return olc::FAIL;
	}

	olc::rcode Sprite::LoadFromFile(std::string sImageFile, olc::ResourcePack *pack) {
#ifdef _WIN32
		// Use GDI+
		std::wstring wsImageFile;
#ifdef __MINGW32__
		wchar_t *buffer = new wchar_t[sImageFile.length() + 1];
		mbstowcs(buffer, sImageFile.c_str(), sImageFile.length());
		buffer[sImageFile.length()] = L'\0';
		wsImageFile = buffer;
		delete [] buffer;
#else
		wsImageFile = ConvertS2W(sImageFile);
#endif
		Gdiplus::Bitmap *bmp = Gdiplus::Bitmap::FromFile(wsImageFile.c_str());
		if (bmp == nullptr)
			return olc::NO_FILE;
		
		width = bmp->GetWidth();
		height = bmp->GetHeight();
		pColData = new Pixel[width * height];
		
		for(int x=0; x<width; x++)
			for (int y = 0; y < height; y++)
			{
				Gdiplus::Color c;
				bmp->GetPixel(x, y, &c);
				SetPixel(x, y, Pixel(c.GetRed(), c.GetGreen(), c.GetBlue(), c.GetAlpha()));
			}
		delete bmp;
		return olc::OK;
#else
		////////////////////////////////////////////////////////////////////////////
		// Use libpng, Thanks to Guillaume Cottenceau
		// https://gist.github.com/niw/5963798
		png_structp png;
		png_infop info;

#ifdef __APPLE__
		std::string currentDir(get_current_working_directory());
		currentDir += "/";
		sImageFile = currentDir + sImageFile;
	#ifdef _DEBUG
			std::cout << "sImageFile = " + sImageFile << std::endl;
	#endif
#endif
#ifdef ANDROID
			sImageFile = PixelGameEngine::ROOTPATH + "/" + sImageFile;
	#ifdef _DEBUG
			std::cout << "sImageFile = " + sImageFile << std::endl;
	#endif
#endif

		FILE *f = fopen(sImageFile.c_str(), "rb");
		if (!f) return olc::NO_FILE;

		png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
		if (!png) goto fail_load;

		info = png_create_info_struct(png);
		if (!info) goto fail_load;

		if (setjmp(png_jmpbuf(png))) goto fail_load;

		png_init_io(png, f);
		png_read_info(png, info);

		png_byte color_type;
		png_byte bit_depth;
		png_bytep *row_pointers;
		width = png_get_image_width(png, info);
		height = png_get_image_height(png, info);
		color_type = png_get_color_type(png, info);
		bit_depth = png_get_bit_depth(png, info);

#ifdef _DEBUG
		std::cout << "Loading PNG: " << sImageFile << "\n";
		std::cout << "W:" << width << " H:" << height << " D:" << (int)bit_depth << "\n";
#endif

		if (bit_depth == 16) png_set_strip_16(png);
		if (color_type == PNG_COLOR_TYPE_PALETTE) png_set_palette_to_rgb(png);
		if (color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8) png_set_expand_gray_1_2_4_to_8(png);
		if (png_get_valid(png, info, PNG_INFO_tRNS)) png_set_tRNS_to_alpha(png);
		if (color_type == PNG_COLOR_TYPE_RGB ||
			color_type == PNG_COLOR_TYPE_GRAY ||
			color_type == PNG_COLOR_TYPE_PALETTE)
			png_set_filler(png, 0xFF, PNG_FILLER_AFTER);
		if (color_type == PNG_COLOR_TYPE_GRAY ||
			color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
			png_set_gray_to_rgb(png);

		png_read_update_info(png, info);
		row_pointers = (png_bytep *) malloc(sizeof(png_bytep) * height);
		for (int y = 0; y < height; y++) {
			row_pointers[y] = (png_byte *) malloc(png_get_rowbytes(png, info));
		}
		png_read_image(png, row_pointers);
		////////////////////////////////////////////////////////////////////////////

		// Create sprite array
		pColData = new Pixel[width * height];

		// Iterate through image rows, converting into sprite format
		for (int y = 0; y < height; y++) {
			png_bytep row = row_pointers[y];
			for (int x = 0; x < width; x++) {
				png_bytep px = &(row[x * 4]);
				SetPixel(x, y, Pixel(px[0], px[1], px[2], px[3]));
			}
		}

		fclose(f);
		return olc::OK;

		fail_load:
		width = 0;
		height = 0;
		fclose(f);
		pColData = nullptr;
		return olc::FAIL;
#endif
	}

	void Sprite::SetSampleMode(olc::Sprite::Mode mode) {
		modeSample = mode;
	}


	Pixel Sprite::GetPixel(int32_t x, int32_t y) {
		if (modeSample == olc::Sprite::Mode::NORMAL) {
			if (x >= 0 && x < width && y >= 0 && y < height)
				return pColData[y * width + x];
			else
				return Pixel(0, 0, 0, 0);
		} else {
			return pColData[abs(y % height) * width + abs(x % width)];
		}
	}

	bool Sprite::SetPixel(int32_t x, int32_t y, Pixel p) {

#ifdef OLC_DBG_OVERDRAW
		nOverdrawCount++;
#endif

		if (x >= 0 && x < width && y >= 0 && y < height) {
			pColData[y * width + x] = p;
			return true;
		} else
			return false;
	}

	Pixel Sprite::Sample(float x, float y) {
		int32_t sx = std::min((int32_t) ((x * (float) width)), width - 1);
		int32_t sy = std::min((int32_t) ((y * (float) height)), height - 1);
		return GetPixel(sx, sy);
	}

	Pixel Sprite::SampleBL(float u, float v) {
		u = u * width - 0.5f;
		v = v * height - 0.5f;
		int x = (int) floor(u); // cast to int rounds toward zero, not downward
		int y = (int) floor(v); // Thanks @joshinils
		float u_ratio = u - x;
		float v_ratio = v - y;
		float u_opposite = 1 - u_ratio;
		float v_opposite = 1 - v_ratio;

		olc::Pixel p1 = GetPixel(std::max(x, 0), std::max(y, 0));
		olc::Pixel p2 = GetPixel(std::min(x + 1, (int) width - 1), std::max(y, 0));
		olc::Pixel p3 = GetPixel(std::max(x, 0), std::min(y + 1, (int) height - 1));
		olc::Pixel p4 = GetPixel(std::min(x + 1, (int) width - 1),
								 std::min(y + 1, (int) height - 1));

		return olc::Pixel(
				(uint8_t) ((p1.r * u_opposite + p2.r * u_ratio) * v_opposite +
						   (p3.r * u_opposite + p4.r * u_ratio) * v_ratio),
				(uint8_t) ((p1.g * u_opposite + p2.g * u_ratio) * v_opposite +
						   (p3.g * u_opposite + p4.g * u_ratio) * v_ratio),
				(uint8_t) ((p1.b * u_opposite + p2.b * u_ratio) * v_opposite +
						   (p3.b * u_opposite + p4.b * u_ratio) * v_ratio));
	}

	Pixel *Sprite::GetData() { return pColData; }

	//==========================================================

	ResourcePack::ResourcePack() {

	}

	ResourcePack::~ResourcePack() {
		ClearPack();
	}

	olc::rcode ResourcePack::AddToPack(std::string sFile) {
		std::ifstream ifs(sFile, std::ifstream::binary);
		if (!ifs.is_open()) return olc::FAIL;

		// Get File Size
		std::streampos p = 0;
		p = ifs.tellg();
		ifs.seekg(0, std::ios::end);
		p = ifs.tellg() - p;
		ifs.seekg(0, std::ios::beg);

		// Create entry
		sEntry e;
		e.data = nullptr;
		e.nFileSize = (uint32_t) p;

		// Read file into memory
		e.data = new uint8_t[(uint32_t) e.nFileSize];
		ifs.read((char *) e.data, e.nFileSize);
		ifs.close();

		// Add To Map
		mapFiles[sFile] = e;
		return olc::OK;
	}

	olc::rcode ResourcePack::SavePack(std::string sFile) {
		std::ofstream ofs(sFile, std::ofstream::binary);
		if (!ofs.is_open()) return olc::FAIL;

		// 1) Write Map
		size_t nMapSize = mapFiles.size();
		ofs.write((char *) &nMapSize, sizeof(size_t));
		for (auto &e : mapFiles) {
			size_t nPathSize = e.first.size();
			ofs.write((char *) &nPathSize, sizeof(size_t));
			ofs.write(e.first.c_str(), nPathSize);
			ofs.write((char *) &e.second.nID, sizeof(uint32_t));
			ofs.write((char *) &e.second.nFileSize, sizeof(uint32_t));
			ofs.write((char *) &e.second.nFileOffset, sizeof(uint32_t));
		}

		// 2) Write Data
		std::streampos offset = ofs.tellp();
		for (auto &e : mapFiles) {
			e.second.nFileOffset = (uint32_t) offset;
			ofs.write((char *) e.second.data, e.second.nFileSize);
			offset += e.second.nFileSize;
		}

		// 3) Rewrite Map (it has been updated with offsets now)
		ofs.seekp(std::ios::beg);
		ofs.write((char *) &nMapSize, sizeof(size_t));
		for (auto &e : mapFiles) {
			size_t nPathSize = e.first.size();
			ofs.write((char *) &nPathSize, sizeof(size_t));
			ofs.write(e.first.c_str(), nPathSize);
			ofs.write((char *) &e.second.nID, sizeof(uint32_t));
			ofs.write((char *) &e.second.nFileSize, sizeof(uint32_t));
			ofs.write((char *) &e.second.nFileOffset, sizeof(uint32_t));
		}
		ofs.close();

		return olc::OK;
	}

	olc::rcode ResourcePack::LoadPack(std::string sFile) {
		std::ifstream ifs(sFile, std::ifstream::binary);
		if (!ifs.is_open()) return olc::FAIL;

		// 1) Read Map
		size_t nMapEntries;
		ifs.read((char *) &nMapEntries, sizeof(size_t));
		for (size_t i = 0; i < nMapEntries; i++) {
			size_t nFilePathSize = 0;
			ifs.read((char *) &nFilePathSize, sizeof(size_t));

			std::string sFileName(nFilePathSize, ' ');
			for (size_t j = 0; j < nFilePathSize; j++)
				sFileName[j] = ifs.get();

			sEntry e;
			e.data = nullptr;
			ifs.read((char *) &e.nID, sizeof(uint32_t));
			ifs.read((char *) &e.nFileSize, sizeof(uint32_t));
			ifs.read((char *) &e.nFileOffset, sizeof(uint32_t));
			mapFiles[sFileName] = e;
		}

		// 2) Read Data
		for (auto &e : mapFiles) {
			e.second.data = new uint8_t[(uint32_t) e.second.nFileSize];
			ifs.seekg(e.second.nFileOffset);
			ifs.read((char *) e.second.data, e.second.nFileSize);
			e.second._config();
		}

		ifs.close();
		return olc::OK;
	}

	olc::ResourcePack::sEntry ResourcePack::GetStreamBuffer(std::string sFile) {
		return mapFiles[sFile];
	}

	olc::rcode ResourcePack::ClearPack() {
		for (auto &e : mapFiles) {
			if (e.second.data != nullptr)
				delete[] e.second.data;
		}

		mapFiles.clear();
		return olc::OK;
	}




	//==========================================================
	std::string olc::PixelGameEngine::ROOTPATH = "";

	PixelGameEngine::PixelGameEngine() {
		sAppName = "Undefined";
		olc::PGEX::pge = this;
	}

	olc::rcode PixelGameEngine::Construct(uint32_t screen_w, uint32_t screen_h, uint32_t pixel_w,
										  uint32_t pixel_h, bool full_screen) {
		nScreenWidth = screen_w;
		nScreenHeight = screen_h;
		nPixelWidth = pixel_w;
		nPixelHeight = pixel_h;
		bFullScreen = full_screen;

		fPixelX = 2.0f / (float) (nScreenWidth);
		fPixelY = 2.0f / (float) (nScreenHeight);

		if (nPixelWidth == 0 || nPixelHeight == 0 || nScreenWidth == 0 || nScreenHeight == 0)
			return olc::FAIL;

		#if defined  _WIN32 && defined UNICODE && !defined  __MINGW32__
			wsAppName = ConvertS2W(sAppName);
		#endif

		// Load the default font sheet
		olc_ConstructFontSheet();

		// Create a sprite that represents the primary drawing target
		pDefaultDrawTarget = new Sprite(nScreenWidth, nScreenHeight);
		SetDrawTarget(nullptr);
		return olc::OK;
	}

	void PixelGameEngine::SetDrawTarget(Sprite *target) {
		if (target)
			pDrawTarget = target;
		else
			pDrawTarget = pDefaultDrawTarget;
	}

	Sprite *PixelGameEngine::GetDrawTarget() {
		return pDrawTarget;
	}

	int32_t PixelGameEngine::GetDrawTargetWidth() {
		if (pDrawTarget)
			return pDrawTarget->width;
		else
			return 0;
	}

	int32_t PixelGameEngine::GetDrawTargetHeight() {
		if (pDrawTarget)
			return pDrawTarget->height;
		else
			return 0;
	}

	bool PixelGameEngine::IsFocused() {
		return bHasInputFocus;
	}

	HWButton PixelGameEngine::GetKey(Key k) {
		return pKeyboardState[k];
	}

	HWButton PixelGameEngine::GetMouse(uint32_t b) {
		return pMouseState[b];
	}

	int32_t PixelGameEngine::GetMouseX() {
		return nMousePosX;
	}

	int32_t PixelGameEngine::GetMouseY() {
		return nMousePosY;
	}

	int32_t PixelGameEngine::GetMouseWheel() {
		return nMouseWheelDelta;
	}

	int32_t PixelGameEngine::ScreenWidth() {
		return nScreenWidth;
	}

	int32_t PixelGameEngine::ScreenHeight() {
		return nScreenHeight;
	}

	bool PixelGameEngine::Draw(int32_t x, int32_t y, Pixel p) {
		if (!pDrawTarget) return false;


		if (nPixelMode == Pixel::NORMAL) {
			return pDrawTarget->SetPixel(x, y, p);
		}

		if (nPixelMode == Pixel::MASK) {
			if (p.a == 255)
				return pDrawTarget->SetPixel(x, y, p);
		}

		if (nPixelMode == Pixel::ALPHA) {
			Pixel d = pDrawTarget->GetPixel(x, y);
			float a = (float) (p.a / 255.0f) * fBlendFactor;
			float c = 1.0f - a;
			float r = a * (float) p.r + c * (float) d.r;
			float g = a * (float) p.g + c * (float) d.g;
			float b = a * (float) p.b + c * (float) d.b;
			return pDrawTarget->SetPixel(x, y, Pixel((uint8_t) r, (uint8_t) g, (uint8_t) b));
		}

		if (nPixelMode == Pixel::CUSTOM) {
			return pDrawTarget->SetPixel(x, y, funcPixelMode(x, y, p, pDrawTarget->GetPixel(x, y)));
		}

		return false;
	}

	void PixelGameEngine::SetSubPixelOffset(float ox, float oy) {
		fSubPixelOffsetX = ox * fPixelX;
		fSubPixelOffsetY = oy * fPixelY;
	}

	void PixelGameEngine::DrawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2, Pixel p,
								   uint32_t pattern) {
		int x, y, dx, dy, dx1, dy1, px, py, xe, ye, i;
		dx = x2 - x1;
		dy = y2 - y1;

		auto rol = [&](void) {
			pattern = (pattern << 1) | (pattern >> 31);
			return pattern & 1;
		};

		// straight lines idea by gurkanctn
		if (dx == 0) // Line is vertical
		{
			if (y2 < y1) std::swap(y1, y2);
			for (y = y1; y <= y2; y++)
				if (rol()) Draw(x1, y, p);
			return;
		}

		if (dy == 0) // Line is horizontal
		{
			if (x2 < x1) std::swap(x1, x2);
			for (x = x1; x <= x2; x++)
				if (rol()) Draw(x, y1, p);
			return;
		}

		// Line is Funk-aye
		dx1 = abs(dx);
		dy1 = abs(dy);
		px = 2 * dy1 - dx1;
		py = 2 * dx1 - dy1;
		if (dy1 <= dx1) {
			if (dx >= 0) {
				x = x1;
				y = y1;
				xe = x2;
			} else {
				x = x2;
				y = y2;
				xe = x1;
			}

			if (rol()) Draw(x, y, p);

			for (i = 0; x < xe; i++) {
				x = x + 1;
				if (px < 0)
					px = px + 2 * dy1;
				else {
					if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0)) y = y + 1; else y = y - 1;
					px = px + 2 * (dy1 - dx1);
				}
				if (rol()) Draw(x, y, p);
			}
		} else {
			if (dy >= 0) {
				x = x1;
				y = y1;
				ye = y2;
			} else {
				x = x2;
				y = y2;
				ye = y1;
			}

			if (rol()) Draw(x, y, p);

			for (i = 0; y < ye; i++) {
				y = y + 1;
				if (py <= 0)
					py = py + 2 * dx1;
				else {
					if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0)) x = x + 1; else x = x - 1;
					py = py + 2 * (dx1 - dy1);
				}
				if (rol()) Draw(x, y, p);
			}
		}
	}

	void PixelGameEngine::DrawCircle(int32_t x, int32_t y, int32_t radius, Pixel p, uint8_t mask) {
		int x0 = 0;
		int y0 = radius;
		int d = 3 - 2 * radius;
		if (!radius) return;

		while (y0 >= x0) // only formulate 1/8 of circle
		{
			if (mask & 0x01) Draw(x + x0, y - y0, p);
			if (mask & 0x02) Draw(x + y0, y - x0, p);
			if (mask & 0x04) Draw(x + y0, y + x0, p);
			if (mask & 0x08) Draw(x + x0, y + y0, p);
			if (mask & 0x10) Draw(x - x0, y + y0, p);
			if (mask & 0x20) Draw(x - y0, y + x0, p);
			if (mask & 0x40) Draw(x - y0, y - x0, p);
			if (mask & 0x80) Draw(x - x0, y - y0, p);
			if (d < 0) d += 4 * x0++ + 6;
			else d += 4 * (x0++ - y0--) + 10;
		}
	}

	void PixelGameEngine::FillCircle(int32_t x, int32_t y, int32_t radius, Pixel p) {
		// Taken from wikipedia
		int x0 = 0;
		int y0 = radius;
		int d = 3 - 2 * radius;
		if (!radius) return;

		auto drawline = [&](int sx, int ex, int ny) {
			for (int i = sx; i <= ex; i++)
				Draw(i, ny, p);
		};

		while (y0 >= x0) {
			// Modified to draw scan-lines instead of edges
			drawline(x - x0, x + x0, y - y0);
			drawline(x - y0, x + y0, y - x0);
			drawline(x - x0, x + x0, y + y0);
			drawline(x - y0, x + y0, y + x0);
			if (d < 0) d += 4 * x0++ + 6;
			else d += 4 * (x0++ - y0--) + 10;
		}
	}

	void PixelGameEngine::DrawRect(int32_t x, int32_t y, int32_t w, int32_t h, Pixel p) {
		DrawLine(x, y, x + w, y, p);
		DrawLine(x + w, y, x + w, y + h, p);
		DrawLine(x + w, y + h, x, y + h, p);
		DrawLine(x, y + h, x, y, p);
	}

	void PixelGameEngine::Clear(Pixel p) {
		int pixels = GetDrawTargetWidth() * GetDrawTargetHeight();
		Pixel *m = GetDrawTarget()->GetData();
		for (int i = 0; i < pixels; i++)
			m[i] = p;
#ifdef OLC_DBG_OVERDRAW
		olc::Sprite::nOverdrawCount += pixels;
#endif
	}

	void PixelGameEngine::FillRect(int32_t x, int32_t y, int32_t w, int32_t h, Pixel p) {
		int32_t x2 = x + w;
		int32_t y2 = y + h;

		if (x < 0) x = 0;
		if (x >= (int32_t) nScreenWidth) x = (int32_t) nScreenWidth;
		if (y < 0) y = 0;
		if (y >= (int32_t) nScreenHeight) y = (int32_t) nScreenHeight;

		if (x2 < 0) x2 = 0;
		if (x2 >= (int32_t) nScreenWidth) x2 = (int32_t) nScreenWidth;
		if (y2 < 0) y2 = 0;
		if (y2 >= (int32_t) nScreenHeight) y2 = (int32_t) nScreenHeight;

		for (int i = x; i < x2; i++)
			for (int j = y; j < y2; j++)
				Draw(i, j, p);
	}

	void PixelGameEngine::DrawTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3,
									   int32_t y3, Pixel p) {
		DrawLine(x1, y1, x2, y2, p);
		DrawLine(x2, y2, x3, y3, p);
		DrawLine(x3, y3, x1, y1, p);
	}

	// https://www.avrfreaks.net/sites/default/files/triangles.c
	void PixelGameEngine::FillTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3,
									   int32_t y3, Pixel p) {
		auto SWAP = [](int &x, int &y) {
			int t = x;
			x = y;
			y = t;
		};
		auto drawline = [&](int sx, int ex, int ny) {
			for (int i = sx; i <= ex; i++)
				Draw(i, ny, p);
		};

		int t1x, t2x, y, minx, maxx, t1xp, t2xp;
		bool changed1 = false;
		bool changed2 = false;
		int signx1, signx2, dx1, dy1, dx2, dy2;
		int e1, e2;
		// Sort vertices
		if (y1 > y2) {
			SWAP(y1, y2);
			SWAP(x1, x2);
		}
		if (y1 > y3) {
			SWAP(y1, y3);
			SWAP(x1, x3);
		}
		if (y2 > y3) {
			SWAP(y2, y3);
			SWAP(x2, x3);
		}

		t1x = t2x = x1;
		y = y1;   // Starting points
		dx1 = (int) (x2 - x1);
		if (dx1 < 0) {
			dx1 = -dx1;
			signx1 = -1;
		}
		else signx1 = 1;
		dy1 = (int) (y2 - y1);

		dx2 = (int) (x3 - x1);
		if (dx2 < 0) {
			dx2 = -dx2;
			signx2 = -1;
		}
		else signx2 = 1;
		dy2 = (int) (y3 - y1);

		if (dy1 > dx1) {   // swap values
			SWAP(dx1, dy1);
			changed1 = true;
		}
		if (dy2 > dx2) {   // swap values
			SWAP(dy2, dx2);
			changed2 = true;
		}

		e2 = (int) (dx2 >> 1);
		// Flat top, just process the second half
		if (y1 == y2) goto next;
		e1 = (int) (dx1 >> 1);

		for (int i = 0; i < dx1;) {
			t1xp = 0;
			t2xp = 0;
			if (t1x < t2x) {
				minx = t1x;
				maxx = t2x;
			}
			else {
				minx = t2x;
				maxx = t1x;
			}
			// process first line until y value is about to change
			while (i < dx1) {
				i++;
				e1 += dy1;
				while (e1 >= dx1) {
					e1 -= dx1;
					if (changed1) t1xp = signx1;//t1x += signx1;
					else goto next1;
				}
				if (changed1) break;
				else t1x += signx1;
			}
			// Move line
			next1:
			// process second line until y value is about to change
			while (1) {
				e2 += dy2;
				while (e2 >= dx2) {
					e2 -= dx2;
					if (changed2) t2xp = signx2;//t2x += signx2;
					else goto next2;
				}
				if (changed2) break;
				else t2x += signx2;
			}
			next2:
			if (minx > t1x) minx = t1x;
			if (minx > t2x) minx = t2x;
			if (maxx < t1x) maxx = t1x;
			if (maxx < t2x) maxx = t2x;
			drawline(minx, maxx, y);    // Draw line from min to max points found on the y
			// Now increase y
			if (!changed1) t1x += signx1;
			t1x += t1xp;
			if (!changed2) t2x += signx2;
			t2x += t2xp;
			y += 1;
			if (y == y2) break;

		}
		next:
		// Second half
		dx1 = (int) (x3 - x2);
		if (dx1 < 0) {
			dx1 = -dx1;
			signx1 = -1;
		}
		else signx1 = 1;
		dy1 = (int) (y3 - y2);
		t1x = x2;

		if (dy1 > dx1) {   // swap values
			SWAP(dy1, dx1);
			changed1 = true;
		} else changed1 = false;

		e1 = (int) (dx1 >> 1);

		for (int i = 0; i <= dx1; i++) {
			t1xp = 0;
			t2xp = 0;
			if (t1x < t2x) {
				minx = t1x;
				maxx = t2x;
			}
			else {
				minx = t2x;
				maxx = t1x;
			}
			// process first line until y value is about to change
			while (i < dx1) {
				e1 += dy1;
				while (e1 >= dx1) {
					e1 -= dx1;
					if (changed1) {
						t1xp = signx1;
						break;
					}//t1x += signx1;
					else goto next3;
				}
				if (changed1) break;
				else t1x += signx1;
				if (i < dx1) i++;
			}
			next3:
			// process second line until y value is about to change
			while (t2x != x3) {
				e2 += dy2;
				while (e2 >= dx2) {
					e2 -= dx2;
					if (changed2) t2xp = signx2;
					else goto next4;
				}
				if (changed2) break;
				else t2x += signx2;
			}
			next4:

			if (minx > t1x) minx = t1x;
			if (minx > t2x) minx = t2x;
			if (maxx < t1x) maxx = t1x;
			if (maxx < t2x) maxx = t2x;
			drawline(minx, maxx, y);
			if (!changed1) t1x += signx1;
			t1x += t1xp;
			if (!changed2) t2x += signx2;
			t2x += t2xp;
			y += 1;
			if (y > y3) return;
		}
	}

	void PixelGameEngine::DrawSprite(int32_t x, int32_t y, Sprite *sprite, uint32_t scale) {
		if (sprite == nullptr)
			return;

		if (scale > 1) {
			for (int32_t i = 0; i < sprite->width; i++)
				for (int32_t j = 0; j < sprite->height; j++)
					for (uint32_t is = 0; is < scale; is++)
						for (uint32_t js = 0; js < scale; js++)
							Draw(x + (i * scale) + is, y + (j * scale) + js,
								 sprite->GetPixel(i, j));
		} else {
			for (int32_t i = 0; i < sprite->width; i++)
				for (int32_t j = 0; j < sprite->height; j++)
					Draw(x + i, y + j, sprite->GetPixel(i, j));
		}
	}

	void
	PixelGameEngine::DrawPartialSprite(int32_t x, int32_t y, Sprite *sprite, int32_t ox, int32_t oy,
									   int32_t w, int32_t h, uint32_t scale) {
		if (sprite == nullptr)
			return;

		if (scale > 1) {
			for (int32_t i = 0; i < w; i++)
				for (int32_t j = 0; j < h; j++)
					for (uint32_t is = 0; is < scale; is++)
						for (uint32_t js = 0; js < scale; js++)
							Draw(x + (i * scale) + is, y + (j * scale) + js,
								 sprite->GetPixel(i + ox, j + oy));
		} else {
			for (int32_t i = 0; i < w; i++)
				for (int32_t j = 0; j < h; j++)
					Draw(x + i, y + j, sprite->GetPixel(i + ox, j + oy));
		}
	}

	void PixelGameEngine::DrawString(int32_t x, int32_t y, std::string sText, Pixel col,
									 uint32_t scale) {
		int32_t sx = 0;
		int32_t sy = 0;
		Pixel::Mode m = nPixelMode;
		if (col.ALPHA != 255) SetPixelMode(Pixel::ALPHA);
		else SetPixelMode(Pixel::MASK);
		for (auto c : sText) {
			if (c == '\n') {
				sx = 0;
				sy += 8 * scale;
			} else {
				int32_t ox = (c - 32) % 16;
				int32_t oy = (c - 32) / 16;

				if (scale > 1) {
					for (uint32_t i = 0; i < 8; i++)
						for (uint32_t j = 0; j < 8; j++)
							if (fontSprite->GetPixel(i + ox * 8, j + oy * 8).r > 0)
								for (uint32_t is = 0; is < scale; is++)
									for (uint32_t js = 0; js < scale; js++)
										Draw(x + sx + (i * scale) + is, y + sy + (j * scale) + js,
											 col);
				} else {
					for (uint32_t i = 0; i < 8; i++)
						for (uint32_t j = 0; j < 8; j++)
							if (fontSprite->GetPixel(i + ox * 8, j + oy * 8).r > 0)
								Draw(x + sx + i, y + sy + j, col);
				}
				sx += 8 * scale;
			}
		}
		SetPixelMode(m);
	}

	void PixelGameEngine::SetPixelMode(Pixel::Mode m) {
		nPixelMode = m;
	}

	Pixel::Mode PixelGameEngine::GetPixelMode() {
		return nPixelMode;
	}

	void PixelGameEngine::SetPixelMode(
			std::function<olc::Pixel(const int x, const int y, const olc::Pixel &,
									 const olc::Pixel &)> pixelMode) {
		funcPixelMode = pixelMode;
		nPixelMode = Pixel::Mode::CUSTOM;
	}

	void PixelGameEngine::SetPixelBlend(float fBlend) {
		fBlendFactor = fBlend;
		if (fBlendFactor < 0.0f) fBlendFactor = 0.0f;
		if (fBlendFactor > 1.0f) fBlendFactor = 1.0f;
	}

	// User must override these functions as required. I have not made
	// them abstract because I do need a default behaviour to occur if
	// they are not overwritten
	bool PixelGameEngine::OnUserCreate() { return false; }

	bool PixelGameEngine::OnUserUpdate(float fElapsedTime) { return false; }

	bool PixelGameEngine::OnUserDestroy() { return true; }
	//////////////////////////////////////////////////////////////////

	void PixelGameEngine::olc_UpdateViewport() {
		int32_t ww = nScreenWidth * nPixelWidth;
		int32_t wh = nScreenHeight * nPixelHeight;
		float wasp = (float) ww / (float) wh;

		nViewW = (int32_t) nWindowWidth;
		nViewH = (int32_t) ((float) nViewW / wasp);

		if (nViewH > nWindowHeight) {
			nViewH = nWindowHeight;
			nViewW = (int32_t) ((float) nViewH * wasp);
		}

		nViewX = (nWindowWidth - nViewW) / 2;
		nViewY = (nWindowHeight - nViewH) / 2;
	}

	void PixelGameEngine::olc_UpdateWindowSize(int32_t x, int32_t y) {
		nWindowWidth = x;
		nWindowHeight = y;
		olc_UpdateViewport();

	}

	void PixelGameEngine::olc_UpdateMouseWheel(int32_t delta) {
		nMouseWheelDeltaCache += delta;
	}

	void PixelGameEngine::olc_UpdateMouse(int32_t x, int32_t y) {
		// Mouse coords come in screen space
		// But leave in pixel space

		//if (bFullScreen)
		{
			// Full Screen mode may have a weird viewport we must clamp to
			x -= nViewX;
			y -= nViewY;
		}

		nMousePosXcache = (int32_t) (((float) x / (float) (nWindowWidth - (nViewX * 2)) *
									  (float) nScreenWidth));
		nMousePosYcache = (int32_t) (((float) y / (float) (nWindowHeight - (nViewY * 2)) *
									  (float) nScreenHeight));

		if (nMousePosXcache >= (int32_t) nScreenWidth)
			nMousePosXcache = nScreenWidth - 1;
		if (nMousePosYcache >= (int32_t) nScreenHeight)
			nMousePosYcache = nScreenHeight - 1;

		if (nMousePosXcache < 0)
			nMousePosXcache = 0;
		if (nMousePosYcache < 0)
			nMousePosYcache = 0;
	}


	void PixelGameEngine::olc_ConstructFontSheet() {
		std::string data;
		data += "?Q`0001oOch0o01o@F40o0<AGD4090LAGD<090@A7ch0?00O7Q`0600>00000000";
		data += "O000000nOT0063Qo4d8>?7a14Gno94AA4gno94AaOT0>o3`oO400o7QN00000400";
		data += "Of80001oOg<7O7moBGT7O7lABET024@aBEd714AiOdl717a_=TH013Q>00000000";
		data += "720D000V?V5oB3Q_HdUoE7a9@DdDE4A9@DmoE4A;Hg]oM4Aj8S4D84@`00000000";
		data += "OaPT1000Oa`^13P1@AI[?g`1@A=[OdAoHgljA4Ao?WlBA7l1710007l100000000";
		data += "ObM6000oOfMV?3QoBDD`O7a0BDDH@5A0BDD<@5A0BGeVO5ao@CQR?5Po00000000";
		data += "Oc``000?Ogij70PO2D]??0Ph2DUM@7i`2DTg@7lh2GUj?0TO0C1870T?00000000";
		data += "70<4001o?P<7?1QoHg43O;`h@GT0@:@LB@d0>:@hN@L0@?aoN@<0O7ao0000?000";
		data += "OcH0001SOglLA7mg24TnK7ln24US>0PL24U140PnOgl0>7QgOcH0K71S0000A000";
		data += "00H00000@Dm1S007@DUSg00?OdTnH7YhOfTL<7Yh@Cl0700?@Ah0300700000000";
		data += "<008001QL00ZA41a@6HnI<1i@FHLM81M@@0LG81?O`0nC?Y7?`0ZA7Y300080000";
		data += "O`082000Oh0827mo6>Hn?Wmo?6HnMb11MP08@C11H`08@FP0@@0004@000000000";
		data += "00P00001Oab00003OcKP0006@6=PMgl<@440MglH@000000`@000001P00000000";
		data += "Ob@8@@00Ob@8@Ga13R@8Mga172@8?PAo3R@827QoOb@820@0O`0007`0000007P0";
		data += "O`000P08Od400g`<3V=P0G`673IP0`@3>1`00P@6O`P00g`<O`000GP800000000";
		data += "?P9PL020O`<`N3R0@E4HC7b0@ET<ATB0@@l6C4B0O`H3N7b0?P01L3R000000020";

		fontSprite = new olc::Sprite(128, 48);
		int px = 0, py = 0;
		for (int b = 0; b < 1024; b += 4) {
			uint32_t sym1 = (uint32_t) data[b + 0] - 48;
			uint32_t sym2 = (uint32_t) data[b + 1] - 48;
			uint32_t sym3 = (uint32_t) data[b + 2] - 48;
			uint32_t sym4 = (uint32_t) data[b + 3] - 48;
			uint32_t r = sym1 << 18 | sym2 << 12 | sym3 << 6 | sym4;

			for (int i = 0; i < 24; i++) {
				int k = r & (1 << i) ? 255 : 0;
				fontSprite->SetPixel(px, py, olc::Pixel(k, k, k, k));
				if (++py == 48) {
					px++;
					py = 0;
				}
			}
		}
	}

	// Need a couple of statics as these are singleton instances
	// read from multiple locations
	std::atomic<bool> PixelGameEngine::bAtomActive{false};
	std::map<uint16_t, uint8_t> PixelGameEngine::mapKeys;
	olc::PixelGameEngine *olc::PGEX::pge = nullptr;
#ifdef OLC_DBG_OVERDRAW
	int olc::Sprite::nOverdrawCount = 0;
#endif
	//=============================================================
}

#endif
