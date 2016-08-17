#include <QApplication>
#include "program/program.hpp"

int main(int argn, char **argv)
{
	QApplication app(argn, argv);

	return app.exec();
}
