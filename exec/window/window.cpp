#include <QWidget>
#include <QCloseEvent>
#include "renderer/renderer.hpp"

#include "window.hpp"

LLCCEP_exec::window::window():
	renderer()
{ }

void LLCCEP_exec::window::closeEvent(QCloseEvent *event)
{
	(void)event;
	end();
}
