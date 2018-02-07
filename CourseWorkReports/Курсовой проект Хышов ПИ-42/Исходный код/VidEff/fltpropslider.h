#ifndef FLTPROPSLIDER_H
#define FLTPROPSLIDER_H

#include <QWidget>
#include "util.h"

namespace Ui {
	class FltPropSlider;
}

class FltPropSlider : public QWidget
{
		Q_OBJECT

	public:
		explicit FltPropSlider(QWidget *parent = 0);
		FltPropSlider(QString caption, float minVal, float maxVal, float step, float divisor, QWidget *parent = 0);
		~FltPropSlider();
		float getValue();
		void setValue(float val);

	public slots:

	signals:
		void valChanged(float val);

	private slots:
		void on_slider_valueChanged(int value);

	private:
		Ui::FltPropSlider *ui;
		float minValue, maxValue, valStep, divisor;
};

#endif // FLTPROPSLIDER_H
