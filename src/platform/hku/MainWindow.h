#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <DirectWindow.h>
#include "GameView.h"


class MainWindow : public BDirectWindow
{
public:
							MainWindow();
	virtual					~MainWindow();

    virtual void		    MessageReceived(BMessage* message);
private:
	GameView*				fGameView;
};


#endif // MAINWINDOW_H
