#include <QWidget>
#include <QPixmap>
#include <QPen>
#include <QBrush>
#include <QtGlobal>

#include "renderer.hpp"

LLCCEP_exec::renderer::renderer(QWidget *parent = 0):
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

virtual ~renderer() const
{
	delete _painter;
	delete _pix;
	_started = false;
	
	QWidget::~QWidget();
}

void begin(int sX, int sY)
{
	_pix = new QPixmap(sX, sY);
	_painter = new QPainter(_pix);
	_started = true;
}

void LLCCEP_exec::renderer::setAffineTransformData(
	double translateX, double translateY,
	double rotateX, double rotateY,
	double scaleX, double scaleY)
{
	Q_ASSERT(OK());
	
	_painter->translate(translateX, translateY);
	_painter->rotate(rotateX, rotateY);
	_painter->scale(scaleX, scaleY);
	
	Q_ASSERT(OK());
}

void LLCCEP_exec::renderer::setPen(const QPen &pen)
{
	Q_ASSERT(OK())
	
	_painter->setPen(pen);
	
	Q_ASSERT(OK())
}

void LLCCEP_exec::renderer::setAntialiased(bool antialiased)
{
	Q_ASSERT(OK())
	
	_antialiased = antialiased;
	
	Q_ASSERT(OK())
}

void LLCCEP_exec::renderer::lock()
{
	Q_ASSERT(OK());
	
	_locked = !_locked;
	
	Q_ASSERT(OK());
}

QPainter &LLCCEP_exec::renderer::painter() const
{
	Q_ASSERT(OK())
	
	return *_painter;
}

void LLCCEP_exec::renderer::paintEvent(QPaintEvent *event) const
{
	Q_ASSERT(OK());
	
	QPainter painter(this);
	
	if (!_locked)
		painter.drawPixmap(0, 0, *_pix);
	
	Q_ASSERT(OK());
}

bool LLCCEP_exec::renderer::OK() const
{
	return _painter && _pix && _started;
}