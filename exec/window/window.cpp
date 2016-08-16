#include <QWidget>
#include <QCloseEvent>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QPoint>
#include "renderer/renderer.hpp"

#include "window.hpp"

LLCCEP_exec::window::window():
	renderer()
{ }

bool LLCCEP_exec::window::getKeyboardButtonState(uint8_t id)
{
	return _kb[id];
}

QPoint LLCCEP_exec::window::getMousePos()
{
	return _mousePos;
}

int LLCCEP_exec::window::getMouseButtons()
{
	return _mouseButtons;
}

void LLCCEP_exec::window::closeEvent(QCloseEvent *event)
{
	(void)event;
	end();
}

void LLCCEP_exec::window::keyEvent(QKeyEvent *event)
{
	if (event->key() <= 0xFF)
		_kb[event->key()] = !_kb[event->key()];
}

void LLCCEP_exec::window::mouseEvent(QMouseEvent *event)
{
	_mousePos = event->pos();
	_mouseButtons = static_cast<int>(event->buttons());
}
