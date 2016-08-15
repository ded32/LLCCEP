#include <QPen>
#include <QBrush>
#include <QColor>
#include <QPixmap>
#include <QFont>
#include <QPainter>
#include <QPaintEvent>
#include <QKeyEvent>

#include <cstdio>
#include <cstdarg>
#include <string>

#include "./../../window/window.hpp"

#include "display.hpp"

LLCCEP_exec::display::display():
	window(),
	_char(0),
	_line(0),
	_startedText(0),
	_textPainter(0),
	_textMap(0)
{ }

void LLCCEP_exec::display::start(::std::string title, int width, int height)
{
	setFixedSize(width, height);
	show();
	setWindowTitle(QString(title.c_str()));

	begin(width, height);
	setAntialiased(true);

	_textMap = new (::std::nothrow) QPixmap(width, height);
	_textPainter = new (::std::nothrow) QPainter(_textMap);
	Q_ASSERT(_textMap && _textPainter);

	_startedText = true;
}

void LLCCEP_exec::display::setColor(COLORREF color)
{
	setPen(QPen(QColor(color), 1));
}

COLORREF LLCCEP_exec::display::getColor() const
{
	QColor clr = painter().pen().color();
	return RGB(clr.red(), clr.green(), clr.blue());
}

void LLCCEP_exec::display::drawPoint(int x, int y)
{
	painter().drawPoint(x, y);
}

COLORREF LLCCEP_exec::display::getPointColor(int x, int y) const
{
	QPixmap pix = QPixmap::grabWidget(window::QWidget::window(), x, y, x, y);
	return pix.toImage().pixel(0, 0);
}

bool LLCCEP_exec::display::getKeyboardButtonState(uint8_t id) const
{
	return _kb[id];
}

int LLCCEP_exec::display::getMouseButtonsState() const
{
	return _mouseButtons;
}

int LLCCEP_exec::display::getMouseX() const
{
	return _mousePos.x();
}

int LLCCEP_exec::display::getMouseY() const
{
	return _mousePos.y();
}

void LLCCEP_exec::display::printOut(::std::string str)
{
	Q_ASSERT(OK());

	int _width = _textPainter->window().width(),
	    _height = _textPainter->window().height();
	for (size_t i = 0; i < str.length(); i++) {
		if (i && i % 80)
			_line++;

		if (_line == 40) {
			QPixmap *map = new (::std::nothrow) QPixmap(_width, _height);
			QPainter *newMapPainter = new (::std::nothrow) QPainter(map);
			Q_ASSERT(map && newMapPainter);

			newMapPainter->drawPixmap(0, 0, _width, _height,
						 *_textMap, 0, _height / 40,
						 _width, _height - _height / 40);

			_textPainter->fillRect(_textPainter->window(), QBrush(Qt::black));
			_textPainter->drawPixmap(_textPainter->window(), *map);

			delete newMapPainter;
			delete map;
		}

		_textPainter->drawText(_char * width() / 80, _line * height() / 40, width() / 80, height() / 40,
				       0, QString(str[i]));

		_char++;
	}

	Q_ASSERT(OK());
}

void LLCCEP_exec::display::writeOut(::std::string fmt, ...)
{
	va_list args;
	va_start(args, fmt);

	char buffer[1024 * 8] = ""; // 8KB
	vsnprintf(buffer, sizeof(buffer) - 1, fmt.c_str(), args);

	printOut(buffer);

	va_end(args);
}

void LLCCEP_exec::display::paintEvent(QPaintEvent *event)
{
	if (OK()) {
		QPixmap *pix = new (::std::nothrow)
			       QPixmap(painter().window().width(),
				       painter().window().height());
		QPainter *paint = new (::std::nothrow) QPainter(pix);
		Q_ASSERT(pix && paint);

		paint->drawImage(QPoint(0, 0), getImage());
		painter().drawPixmap(0, 0, *_textMap);

		delete paint;
		delete pix;
	}

	window::paintEvent(event);
}

void LLCCEP_exec::display::keyEvent(QKeyEvent *event)
{
	printOut(event->text().toStdString());
	window::keyEvent(event);
}

bool LLCCEP_exec::display::OK() const
{
	return window::OK() && _startedText && _textPainter && _textMap;
}
