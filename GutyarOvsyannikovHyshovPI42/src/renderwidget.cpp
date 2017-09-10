#include "renderwidget.h"

RenderWidget::RenderWidget(QWidget *parent) : QWidget(parent)
{
	isDesignMode = false;
	isClickMode = true;
	this->setAttribute(Qt::WA_Hover, true);
}

void RenderWidget::paintEvent(QPaintEvent *)
{
	QPainter pntr(this);
	pntr.setRenderHint(QPainter::HighQualityAntialiasing);
	QRectF geom = QRectF(0.0, 0.0, (qreal)this->width() - 1, (qreal)this->height() - 1);
	readyToPaint(&pntr, geom);
}

void RenderWidget::setDesignMode(bool state)
{
	isDesignMode = state;
}

void RenderWidget::mousePressEvent(QMouseEvent *e)
{
	oldPos = e->pos();
	mouseDown = true;
}

void RenderWidget::mouseMoveEvent(QMouseEvent *e)
{
	pos = e->pos();
	if (!mouseDown && this->geometry().contains(e->pos()))
		hoverAtCoord(QPointF(e->pos()));
}

void RenderWidget::mouseReleaseEvent(QMouseEvent *e)
{
	mouseDown = false;
	pos = e->pos();
	if (pos == oldPos)
	clickAtCoord(QPointF(e->pos()), QRectF(0.0, 0.0, (qreal)this->width() - 1, (qreal)this->height() - 1));
}
