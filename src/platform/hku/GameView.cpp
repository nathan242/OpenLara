#include "GameView.h"
#include <cstdio>
//extern char *lvlName;
//extern char cacheDir[255];
//extern char saveDir[255];
//extern char contentDir[255];

namespace Game {
	extern void init(const char *lvlName = NULL);
	extern bool update();
	extern bool render();
	extern void deinit();
}

namespace Core {
    extern int width;
    extern int height;
	extern bool isQuit;
	extern void waitVBlank();
}

GameView::GameView(BRect frame)
	:
	BGLView(frame, "gameView", B_FOLLOW_ALL, B_WILL_DRAW,
		BGL_RGB | BGL_DOUBLE | BGL_DEPTH)
{
   	Core::width  = frame.Width();
   	Core::height = frame.Height();
    printf("width = %f  height = %f\n", frame.Width(), frame.Height());
}

GameView::~GameView()
{
}

void GameView::AttachedToWindow()
{
	BGLView::AttachedToWindow();
	_CreateGameRenderThread();
}

void GameView::FrameResized(float width, float height)
{
	Core::width  = width;
   	Core::height = height;
	BGLView::FrameResized(width, height);
}

void GameView::_CreateGameRenderThread()
{
	fGameRenderThread = spawn_thread(GameView::_GameRenderThreadEntry, "gameRenderThread", B_NORMAL_PRIORITY, this);
	resume_thread(fGameRenderThread);
}

int32 GameView::_GameRenderThreadEntry(void* pointer)
{
	reinterpret_cast<GameView*>(pointer)->_GameRenderLoop();
    
    return 0;
}

void GameView::_GameRenderLoop()
{
	LockGL();
   	Game::init(nullptr);
   	UnlockGL();
   	
   	while (!Core::isQuit) {
		LockGL();
       	if (Game::update()) {
           	Game::render();
           	Core::waitVBlank();
           	SwapBuffers(false);
       	}
       	
       	UnlockGL();
   	}
   	
    Game::deinit();
  	UnlockGL();
}
