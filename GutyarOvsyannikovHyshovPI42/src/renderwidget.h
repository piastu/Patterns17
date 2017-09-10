#ifndef RENDERWIDGET_H
#define RENDERWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QEvent>
#include <QPointF>
#include <QHoverEvent>
#include <QMouseEvent>

// виджет для отрисовки схемы
class RenderWidget : public QWidget
{
		Q_OBJECT
	public:
		explicit RenderWidget(QWidget *parent = 0);
		void paintEvent(QPaintEvent *);
		void setDesignMode(bool state);

	private:
		void mousePressEvent(QMouseEvent *e);
		void mouseMoveEvent(QMouseEvent *e);
		void mouseReleaseEvent(QMouseEvent *e);
		QPointF oldPos, pos;
		bool isDesignMode;
		bool mouseDown;	// мышь опущена
		bool isClickMode; // true - щелкаем, false - перетаскиваем

	signals:
		void readyToPaint(QPainter *, QRectF);
		void hoverAtCoord(QPointF);
		void clickAtCoord(QPointF, QRectF);

	public slots:

};

#endif // RENDERWIDGET_H
