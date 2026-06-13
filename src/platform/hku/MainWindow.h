#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <DirectWindow.h>
#include "GameView.h"


class MainWindow : public BDirectWindow
{
public:
							MainWindow();
	virtual					~MainWindow();
private:
	GameView*				fGameView;
};


#endif // MAINWINDOW_H
