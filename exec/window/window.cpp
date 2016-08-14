#include <QWidget>

#include "renderer/renderer.hpp"
#include "window.hpp"

LLCCEP_exec::window::window():
	_rnd(0),
	_layout(0)
{
	
}

void LLCCEP_exec::window::~window()
{
	QWidget::~QWidget();
	
	delete _rnd;
	delete _layout;
}

void LLCCEP_exec::window::attachRenderer()
{
	Q_ASSERT(maximumWidth() && maximumHeight()); // check for the window has assigned metrics
	Q_ASSERT(!_rnd && !_layout);

	_layout = new (::std::nothrow) QGridLayout;
	_rnd = new (::std::nothrow) renderer(maximumWidth(), maximumHeight());
	
	_layout->addWidget(_rnd);
	setLayout(_layout)
	
	Q_ASSERT(OK());
}

LLCCEP_exec::renderer &LLCCEP_exec::window::getRenderer() const
{
	Q_ASSERT(OK());
	
	return *_rnd;
}

bool LLCCEP_exec::window::OK() const
{
	return _rnd && _layout && maximumWidth() && maximumHeight();
}