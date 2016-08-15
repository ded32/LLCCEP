#include <QApplication>
#include <QPainter>

#include "window.hpp"

int main(int argn, char **argv)
{
    QApplication app(argn, argv);

	LLCCEP_exec::window wnd;
	wnd.resize(800, 640);
	wnd.show();
	wnd.setWindowTitle(QApplication::translate("test", "Test QT Window"));
	wnd.begin(800, 640);
	wnd.setAntialiased(true);

	for (double i = 0; i * i < 640; i += 0.001)
		wnd.painter().drawPoint(i, i * i);

    return app.exec();
}
