#ifndef EXEC_RENDERER_HPP
#define EXEC_RENDERER_HPP

#include <QWidget>
#include <QPixmap>
#include <QPen>
#include <QPainter>

namespace LLCCEP_exec {
	class renderer: public QWidget {
		Q_OBJECT
		
	public:
		renderer(QWidget *parent = 0);
		virtual ~renderer() Q_DECL_OVERRIDE;
		
		void begin(int sX, int sY);
		
		void setAffineTransformData(
			double translateX, double translateY,
			double rotate,
			double scaleX, double scaleY);
		void setPen(const QPen &pen);
		void setAntialiased(bool antialiased);
		void lock();
		void end();

		QPainter &painter() const;
		QImage getImage() const;

		bool OK() const;
		
	protected:
		virtual void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
		virtual void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;
		
	private:
		QTimer *_timer;
		QPainter *_painter;
		QPixmap *_pix;
		bool _antialiased;
		bool _started;
		bool _locked;
	};
}

#endif // RENDERER_HPP
