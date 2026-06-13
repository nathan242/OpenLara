/*
 * Copyright 2018, Your Name <your@email.address>
 * All rights reserved. Distributed under the terms of the MIT license.
 */


#include "MainWindow.h"

MainWindow::MainWindow()
	:
	BDirectWindow(BRect(100, 100, 400, 400), "OpenLara", B_TITLED_WINDOW,
		B_ASYNCHRONOUS_CONTROLS | B_QUIT_ON_WINDOW_CLOSE)
{
	fGameView = new GameView(Bounds());
	
	AddChild(fGameView);
}

MainWindow::~MainWindow()
{
	
}

