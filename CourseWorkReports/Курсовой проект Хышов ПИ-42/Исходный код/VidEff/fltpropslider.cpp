#include "fltpropslider.h"
#include "ui_fltpropslider.h"

FltPropSlider::FltPropSlider(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::FltPropSlider)
{
	ui->setupUi(this);
	minValue = 0.0;
	maxValue = 1.0;
	valStep = 0.1;
	divisor = 1.0;
}

FltPropSlider::FltPropSlider(QString caption, float minVal, float maxVal, float step, float divisor, QWidget *parent) : FltPropSlider(parent)
{
	ui->lblCaption->setText(caption);
	minValue = minVal;
	maxValue = maxVal;
	valStep = step;
	this->divisor = divisor;
	ui->slider->setRange(minValue * divisor, maxValue * divisor);
	ui->slider->setSingleStep(step * divisor);
}

FltPropSlider::~FltPropSlider()
{
	delete ui;
}

float FltPropSlider::getValue()
{
	float result = ui->slider->value();
	result /= divisor;
	return result;
}

void FltPropSlider::setValue(float val)
{
	ui->slider->setValue((int)clamp(val * divisor, minValue, maxValue));
}

void FltPropSlider::on_slider_valueChanged(int value)
{
	ui->lcd->display(value);
	emit valChanged(value / divisor);
}
