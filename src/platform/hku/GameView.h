#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <GLView.h>

class GameView : public BGLView
{
public:
						GameView(BRect frame);
	virtual				~GameView();
	virtual void		AttachedToWindow();
	void				GameLoop();
	
protected:
	void				_CreateGameRenderThread();
	static int32		_GameRenderThreadEntry(void* pointer);
	void				_GameRenderLoop();
	
	thread_id			fGameRenderThread;
};

#endif // GAMEVIEW_H
