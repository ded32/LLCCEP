#ifndef EXEC_MESSAGEBOX_HPP
#define EXEC_MESSAGEBOX_HPP

#include <QMessageBox>
#include <string>

namespace LLCCEP_exec {
	class messageBox: private QMessageBox {
	public:
		messageBox(::std::string title,
			   ::std::string subtitle,
			   StandardButtons buttons,
			   StandardButton selected,
			   Icon icon = QMessageBox::Information);

		int spawn();
	};
}

#endif // EXEC_MESSAGEBOX_HPP
