#include <QApplication>
#include <QWidget>
#include "Maze.h"
#include <QDesktopWidget>


int HEIGHT = 1000, WIDTH = 1000;

int main(int argc, char*argv[]) {
	QApplication app(argc, argv);

	Maze window;  // start the game
	window.show();

	QDesktopWidget *desktop = QApplication::desktop();
	int screenWidth = desktop->width(); // find size of screen
	int screenHeight = desktop->height();
	int x = (screenWidth-WIDTH)/2;  // find center of screen
	int y = (screenHeight-HEIGHT)/2;

	window.setGeometry(x,y,WIDTH,HEIGHT);
//	window.setFixedSize(WIDTH,HEIGHT);

	return app.exec();
}
