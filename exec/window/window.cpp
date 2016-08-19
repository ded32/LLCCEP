#include <QWidget>
#include <QCloseEvent>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QPoint>
#include <QMessageBox>
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
		QMessageBox mb;
		mb.setWindowTitle(windowTitle());
		mb.setText("Program is still executing!\n");
		mb.setInformativeText("Terminating it now may cause\n"
				      "problems with the future execution.\n"
				      "Do you really want to quit?");
		mb.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
		mb.setDefaultButton(QMessageBox::Yes);
		mb.setIcon(QMessageBox::Warning);

		if (mb.exec() == QMessageBox::Yes) {
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
