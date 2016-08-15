#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <QObject>
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QKeyEvent>

#include <string>
#include <cstdint>
#include "./../../window/window.hpp"

#if !defined(RGBA) && !defined(RGB)
#define RGBA(r, g, b, a) (((a) & 0xFF) << 24) | \
                         (((b) & 0xFF) << 16) | \
                         (((g) & 0xFF) <<  8) | \
                          ((r) & 0xFF)

#define RGB(r, g, b) RGBA(r, g, b, 0xFF)
#endif

#if !defined(RGBA_R) && !defined(RGBA_G) && \
    !defined(RGBA_B) && !defined(RGBA_A)
#define RGBA_R(clr) ((clr) & 0xFF)
#define RGBA_G(clr) (((clr) >>  8) & 0xFF)
#define RGBA_B(clr) (((clr) >> 16) & 0xFF)
#define RGBA_A(clr) (((clr) >> 24) & 0xFF)
#endif

typedef long unsigned COLORREF;

namespace LLCCEP_exec {
	class display: protected window {
		Q_OBJECT

	public:
		display();

		void start(::std::string title, int width, int height);

		void setColor(COLORREF color);
		COLORREF getColor() const;

		void drawPoint(int x, int y);
		COLORREF getPointColor(int x, int y) const;

		bool getKeyboardButtonState(uint8_t id) const;

		int getMouseButtonsState() const;
		int getMouseX() const;
		int getMouseY() const;

		void printOut(::std::string str);
		void writeOut(::std::string fmt, ...);

	protected:
		void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
		void keyEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
		virtual bool OK() const;

	private:
		int _char;
		int _line;

		bool _startedText;
		QPainter *_textPainter;
		QPixmap *_textMap;
	};
}

#endif // DISPLAY_HPP
