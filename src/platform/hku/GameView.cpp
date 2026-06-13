#include "GameView.h"

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
	extern bool isQuit;
	extern void waitVBlank();
}

GameView::GameView(BRect frame)
	:
	BGLView(frame, "gameView", B_FOLLOW_ALL, B_WILL_DRAW,
		BGL_RGB | BGL_DOUBLE | BGL_DEPTH)
{
   	
}

GameView::~GameView()
{
}

void GameView::AttachedToWindow()
{
	BGLView::AttachedToWindow();
	_CreateGameRenderThread();
}

void GameView::_CreateGameRenderThread()
{
	fGameRenderThread = spawn_thread(GameView::_GameRenderThreadEntry, "gameRenderThread", B_NORMAL_PRIORITY, this);
	resume_thread(fGameRenderThread);
}

int32 GameView::_GameRenderThreadEntry(void* pointer)
{
	reinterpret_cast<GameView*>(pointer)->_GameRenderLoop();
}

void GameView::_GameRenderLoop()
{
	LockGL();
   	Game::init(nullptr);
   	UnlockGL();
   	
   	while (!Core::isQuit) {
       	//inputUpdate();

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
