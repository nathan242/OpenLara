#include "App.h"

const char* kApplicationSignature = "application/x-vnd.nathan242-OpenLara";


App::App()
	:
	BApplication(kApplicationSignature)
{
	MainWindow* mainWindow = new MainWindow();
	mainWindow->Show();
}

App::~App()
{
}
