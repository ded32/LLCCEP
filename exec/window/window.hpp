#ifndef EXEC_WINDOW_HPP
#define EXEC_WINDOW_HPP

#include <QWidget>
#include <QCloseEvent>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QPoint>
#include "renderer/renderer.hpp"

namespace LLCCEP_exec {
	class window: public renderer {
		Q_OBJECT

	public:
		window();

		bool getKeyboardButtonState(uint8_t id);
		QPoint getMousePos();
		int getMouseButtons();

		void setMayClose(bool newMayClose = true);
		bool mayClose() const;

	protected:
		virtual void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;
		virtual void keyEvent(QKeyEvent *event);
		virtual void mouseEvent(QMouseEvent *event);

		bool _kb[0xFF + 1];
		QPoint _mousePos;
		int _mouseButtons;
		bool _mayClose;
	};
}

#endif // WINDOW_HPP
