#include <QApplication>
#include <QPainter>

#include "window.hpp"

int main(int argn, char **argv)
{
	QApplication app(argn, argv);
	
	LLCCEP_exec::window wnd;
	wnd.resize(800, 640);
	wnd.show();
	wnd.setWindowTitle(QApplication::translate("Test QT Window", "Test QT Window"));
	wnd.begin(800, 640);
	wnd.setAntialiased(true);
	wnd.painter().drawLine(0, 0, 800, 640);
	
	return app.exec();
}
