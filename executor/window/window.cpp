#include <QWidget>
#include <QCloseEvent>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QPoint>
#include "../messageBox/messageBox.hpp"
#include "renderer/renderer.hpp"

#include "window.hpp"

LLCCEP_exec::window::window():
	renderer(),
	_kb(),
	_mouseButtons(0),
	_mayClose(false)
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

void LLCCEP_exec::window::setMayClose(bool newMayClose)
{
	_mayClose = newMayClose;
}

bool LLCCEP_exec::window::mayClose() const
{
	return _mayClose;
}

void LLCCEP_exec::window::closeEvent(QCloseEvent *event)
{
	if (_mayClose) {
		event->accept();
	} else {
		int res = LLCCEP_exec::messageBox("Program is still executing!\n",
						  "Terminating it now may cause\n"
						  "problems with the future execution.\n"
						  "Do you really want to quit?",
						  QMessageBox::No | QMessageBox::Yes,
						  QMessageBox::No, QMessageBox::Warning).spawn();

		if (res == QMessageBox::Yes) {
			end();
			event->accept();
		} else {
			event->ignore();
		}
	}
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
