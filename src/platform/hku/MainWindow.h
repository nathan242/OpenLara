#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <DirectWindow.h>
#include <FilePanel.h>
#include <Menu.h>
#include <MenuBar.h>
#include <MenuItem.h>
#include "GameView.h"


class MainWindow : public BDirectWindow
{
public:
							MainWindow();
	virtual					~MainWindow();

    virtual void		    MessageReceived(BMessage* message);
private:
    BMenuBar*               _BuildMenu();
    void                    _StartGame(const char *lvlName = NULL);
    
    float                   fGameViewTop;
    BMenuItem*              fMenuStart;
    BMenuItem*              fMenuOpen;
    BFilePanel*             fOpenPanel;
};


#endif // MAINWINDOW_H
