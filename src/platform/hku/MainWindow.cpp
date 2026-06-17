#include "MainWindow.h"

extern void handleKeyPress(const char* keyBytes, int index);
extern void handleModifierKeyPress(int32 keys, int index);

MainWindow::MainWindow()
	:
	BDirectWindow(BRect(320, 200), "OpenLara", B_TITLED_WINDOW,
		B_ASYNCHRONOUS_CONTROLS | B_QUIT_ON_WINDOW_CLOSE)
{
	fGameView = new GameView(Bounds());
	
	AddChild(fGameView);
}

MainWindow::~MainWindow()
{
	
}

void MainWindow::MessageReceived(BMessage* message)
{
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

        default:
            BDirectWindow::MessageReceived(message);
    }
}
