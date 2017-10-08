#ifndef WOLFANDSHEEP_QTVER_H
#define WOLFANDSHEEP_QTVER_H

#include <QtGui/QDialog>
#include "ui_wolfandsheep_qtver.h"
#include <QTimer>
#include "QVector"
#include "Organism.h"
#include "CWorld.h"
#include "global_define.h"

#include <qwt_legend.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_curve.h>
#include <qwt_plot.h>
#include "qwt_series_data.h"
#include "qwt_math.h"

class WolfAndSheep_qtver : public QDialog
{
	Q_OBJECT

public:
	WolfAndSheep_qtver(QWidget *parent = 0, Qt::WFlags flags = 0);
	~WolfAndSheep_qtver();

	void display();
	
	void Statistics();


public slots:
	void initializeWorld();
	void startSimulate();
	void pauseSimulate();
	void Simulate();
	void changeSpeed(int);
	void drawnumline();

private:
	Ui::WolfAndSheep_qtverClass ui;

private:
	QTimer steptimer;

	CWorld wsWorld;
	int numSheep;
	int numWolf;

	QVector<qreal> vec_sheepnum;
	QVector<qreal> vec_wolfnum;

	QwtPlotCurve* sheepCurve;
	QwtPlotCurve* wolfCurve;
};

#endif // WOLFANDSHEEP_QTVER_H
