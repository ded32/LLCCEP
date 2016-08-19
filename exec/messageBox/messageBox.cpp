#include <QMessageBox>
#include "messageBox.hpp"

LLCCEP_exec::messageBox::messageBox(::std::string title,
				    ::std::string subtitle,
				    StandardButtons buttons,
				    StandardButton selected,
				    Icon icon):
	QMessageBox()
{
	setText(title.c_str());
	setInformativeText(subtitle.c_str());
	setStandardButtons(buttons);
	setDefaultButton(selected);
	setIcon(icon);
}

int LLCCEP_exec::messageBox::spawn()
{
	return exec();
}
