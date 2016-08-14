#include <QWidget>
#include <QPixmap>
#include <QPen>
#include <QBrush>
#include <QtGlobal>
#include <QPainter>
#include <QPaintEvent>
#include <QResizeEvent>

#include <algorithm>

#include "renderer.hpp"

LLCCEP_exec::renderer::renderer(QWidget *parent /*= 0*/):
	QWidget(parent),
	_painter(0),
	_pix(0),
	_antialiased(false),
	_started(false),
	_locked(false)
{
	setBackgroundRole(QPalette::Base);
	setAutoFillBackground(true);
}

LLCCEP_exec::renderer::~renderer()
{
	delete _painter;
	delete _pix;
	_started = false;

	QWidget::~QWidget();
}

void LLCCEP_exec::renderer::begin(int sX, int sY)
{
	_pix = new QPixmap(sX, sY);
	_painter = new QPainter(_pix);
	_painter->setPen(QPen(Qt::white, 1));
	_started = true;
}

void LLCCEP_exec::renderer::setAffineTransformData(
	double translateX, double translateY,
	double rotate,
	double scaleX, double scaleY)
{
	Q_ASSERT(OK());
	
	_painter->translate(translateX, translateY);
	_painter->rotate(rotate);
	_painter->scale(scaleX, scaleY);
	
	Q_ASSERT(OK());
}

void LLCCEP_exec::renderer::setPen(const QPen &pen)
{
	Q_ASSERT(OK());
	
	_painter->setPen(pen);
	
	Q_ASSERT(OK());
}

void LLCCEP_exec::renderer::setAntialiased(bool antialiased)
{
	Q_ASSERT(OK());
	
	_antialiased = antialiased;
	
	Q_ASSERT(OK());
}

void LLCCEP_exec::renderer::lock()
{
	Q_ASSERT(OK());
	
	_locked = !_locked;
	
	Q_ASSERT(OK());
}

QPainter &LLCCEP_exec::renderer::painter() const
{
	Q_ASSERT(OK());
	
	return *_painter;
}

void LLCCEP_exec::renderer::paintEvent(QPaintEvent *event)
{
	(void)event;

	QPainter painter(this);

	if (_antialiased)
		painter.setRenderHint(QPainter::Antialiasing);

	if (!_locked && OK()) // only if initialization has been proceeded
		painter.drawPixmap(0, 0, *_pix);

	painter.setRenderHint(QPainter::Antialiasing, false);
}

void LLCCEP_exec::renderer::resizeEvent(QResizeEvent *event)
{
	if (!OK()) // if setup wasn't already proceeded, don't do the actions
		return;

	int w0 = _pix->size().width(), h0 = _pix->size().height(),
	    w1 = event->size().width(), h1 = event->size().height();

	if (w1 > w0 || h1 > h0) {
		QPixmap *newPixmap = new QPixmap(::std::max(w0, w1), ::std::max(h0, h1));
		QPainter *newPainter = new QPainter(newPixmap);

		newPainter->drawPixmap(0, 0, *_pix);

		delete _painter;
		delete _pix;

		_painter = newPainter;
		_pix = newPixmap;
	}

	Q_ASSERT(OK());
}

bool LLCCEP_exec::renderer::OK() const
{
	return _painter && _pix && _started;
}
