#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <QWidget>

#include "renderer/renderer.hpp"

namespace LLCCEP_exec {
	class window: public QWidget {
		Q_OBJECT
		
	public:
		window();
		virtual ~window() Q_DECL_OVERRIDE;
		void attachRenderer();
		renderer &getRenderer() const;
		
	protected:
		bool OK() const;
		
	private:
		renderer *_rnd;
		QGridLayout *_layout;
	};
}

#endif // WINDOW_HPP