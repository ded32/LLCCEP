#include <QApplication>

#include "display.hpp"

int main(int argn, char **argv)
{
	QApplication app(argn, argv);

	LLCCEP_exec::display display;
	display.start("Test QT Display", 800, 640);

	for (double i = 0; i * i < 640; i += 0.001)
		display.drawPoint(i, i * i);

	return app.exec();
}
