#include "MainWindow.h"

extern void handleKeyPress(const char* keyBytes, int index);
extern void handleModifierKeyPress(int32 keys, int index);

namespace Core {
	extern void reset();
}

static const uint32 kMsgGameStart = 'gmst';
static const uint32 kMsgGameOpen = 'gmop';
static const uint32 kMsgGameResetRenderer = 'gmrr';

MainWindow::MainWindow()
	:
	BDirectWindow(BRect(100, 100, 420, 300), "OpenLara", B_TITLED_WINDOW,
		B_ASYNCHRONOUS_CONTROLS | B_QUIT_ON_WINDOW_CLOSE)
{
    BMenuBar* menuBar = _BuildMenu();
    AddChild(menuBar);

    BRect menuBounds = menuBar->Bounds();
    fGameViewTop = menuBounds.bottom;
    ResizeBy(0, fGameViewTop);
    
    fOpenPanel = new BFilePanel(B_OPEN_PANEL);
    fOpenPanel->SetTarget(this);
}

MainWindow::~MainWindow()
{
	
}

void MainWindow::_StartGame(const char *lvlName)
{
    fMenuStart->SetEnabled(false);
    fMenuOpen->SetEnabled(false);

    BRect gameViewBounds = Bounds();
    gameViewBounds.top = fGameViewTop;
	AddChild(new GameView(gameViewBounds));
}

void MainWindow::MessageReceived(BMessage* message)
{
    message->PrintToStream();
    switch (message->what) {
        case B_KEY_DOWN:
		{
            const char *keyBytes;
            message->FindString("bytes", &keyBytes);
            handleKeyPress(keyBytes, 1);
            break;
		}
        
        case B_KEY_UP:
        {
            const char *keyBytes;
            message->FindString("bytes", &keyBytes);
            handleKeyPress(keyBytes, 0);
            break;
        }

        case B_UNMAPPED_KEY_DOWN:
        case B_UNMAPPED_KEY_UP:
            int32 keys;
            message->FindInt32("modifiers", &keys);
            handleModifierKeyPress(keys, 1);
            break;
            
        case kMsgGameStart:
            _StartGame();
            break;
            
        case kMsgGameOpen:
            fOpenPanel->Show();
            break;
            
        case kMsgGameResetRenderer:
            Core::reset();
            break;

        default:
            BDirectWindow::MessageReceived(message);
    }
}

BMenuBar* MainWindow::_BuildMenu()
{
    BMenuBar* menuBar = new BMenuBar(Bounds(), "menuBar");
    BMenu* gameMenu = new BMenu("Game");
    
    fMenuStart = new BMenuItem("Start", new BMessage(kMsgGameStart));
    gameMenu->AddItem(fMenuStart);
    
    fMenuOpen = new BMenuItem("Open", new BMessage(kMsgGameOpen));
    gameMenu->AddItem(fMenuOpen);
    
    gameMenu->AddSeparatorItem();

    BMenuItem* item = new BMenuItem("Reset renderer", new BMessage(kMsgGameResetRenderer));
    gameMenu->AddItem(item);
    
    gameMenu->AddSeparatorItem();
    
    item = new BMenuItem("Quit", new BMessage(B_QUIT_REQUESTED), 'Q');
    gameMenu->AddItem(item);
    
    menuBar->AddItem(gameMenu);
    
    return menuBar;
}
