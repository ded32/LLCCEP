#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <QWidget>
#include <QCloseEvent>
#include "renderer/renderer.hpp"

namespace LLCCEP_exec {
	class window: public renderer {
		Q_OBJECT

	public:
		window();

	protected:
		virtual void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;
	};
}

#endif // WINDOW_HPP
