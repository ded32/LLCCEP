#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <QWidget>
#include <QPixmap>
#include <QPen>
#include <QBrush>

namespace LLCCEP_exec {
	class renderer: public QWidget {
		Q_OBJECT
		
	public:
		renderer(QWidget *parent = 0);
		virtual ~renderer() Q_DECL_OVERRIDE;
		
		void begin(int sX, int sY);
		
		void setAffineTransformData(
			double translateX, double translateY,
			double rotateX, double rotateY,
			double scaleX, double scaleY);
		void setPen(const QPen &pen);
		void setAntialiased(bool antialiased);
		void lock();
		
		QPainter &painter() const;
		
	protected:
		void paintEvent(QPaintEvent *event) const Q_DECL_OVERRIDE;
		bool OK() const;
		
	private:
		QPainter *_painter;
		QPixmap *_pix;
		bool _antialiased;
		bool _started;
		bool _locked;
	};
}

#endif // RENDERER_HPP
