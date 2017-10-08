#include "wolfandsheep_qtver.h"
#include <QtCore>
#include <QGraphicsScene>
#include <QTimer>
#include <QtGui>
#include "CSheep.h"
#include "CWolf.h"
#include "CGrass.h"
#include <time.h>
#include <stdlib.h>



WolfAndSheep_qtver::WolfAndSheep_qtver(QWidget *parent, Qt::WFlags flags)
	: QDialog(parent, flags)
{
	ui.setupUi(this);
	srand((unsigned)time(NULL));
	qsrand(QTime::currentTime().msec());

	numSheep=500;
	numWolf=50;

	 //设置坐标轴的名称
	ui.qwtPlot->setAxisTitle(QwtPlot::xBottom,"Iterations");
	ui.qwtPlot->setAxisTitle(QwtPlot::yLeft,"Number");

	//设置坐标轴的范围
	ui.qwtPlot->setAxisScale(ui.qwtPlot->xBottom, 0, 300);
	ui.qwtPlot->setAxisScale(ui.qwtPlot->yLeft, 0, 600);

	//设置右边标注 
	ui.qwtPlot->insertLegend(new QwtLegend(), QwtPlot::RightLegend);

	//使用鼠标左键平移
	(void) new QwtPlotPanner(ui.qwtPlot->canvas());
	

	sheepCurve=new QwtPlotCurve("sheep");
	wolfCurve=new QwtPlotCurve("wolf");

	sheepCurve->setStyle(QwtPlotCurve::Lines);
	sheepCurve->setCurveAttribute(QwtPlotCurve::Fitted,true);//是曲线更光滑 
	sheepCurve->setPen(QPen(Qt::blue,3));//设置画笔

	wolfCurve->setStyle(QwtPlotCurve::Lines);
	wolfCurve->setCurveAttribute(QwtPlotCurve::Fitted,true);//是曲线更光滑 
	wolfCurve->setPen(QPen(Qt::red,3));//设置画笔



	//把曲线附加到qwtplot上 
	sheepCurve->attach(ui.qwtPlot);
	wolfCurve->attach(ui.qwtPlot);

	initializeWorld();


	connect(ui.initializeB,SIGNAL(clicked()),this,SLOT(initializeWorld()));
	connect(&steptimer,SIGNAL(timeout()),this,SLOT(Simulate()));
	connect(&steptimer,SIGNAL(timeout()),this,SLOT(drawnumline()));
	connect(ui.startB,SIGNAL(clicked()),this,SLOT(startSimulate()));
	connect(ui.speedS,SIGNAL(valueChanged(int)),this,SLOT(changeSpeed(int)));
	/*connect(ui.startB,SIGNAL(clicked()),this,SLOT(Simulate()));*/
	connect(ui.pauseB,SIGNAL(clicked()),this,SLOT(pauseSimulate()));
	connect(ui.endB,SIGNAL(clicked()),this,SLOT(close()));

}

WolfAndSheep_qtver::~WolfAndSheep_qtver()
{

}

void WolfAndSheep_qtver::initializeWorld()
{
	wsWorld.clearWorld();
	numSheep=ui.sheepnumSB->value();
	numWolf=ui.wolfnumSB->value();

	vec_sheepnum.clear();
	vec_wolfnum.clear();
	drawnumline();
	if (steptimer.isActive())
	{
		steptimer.stop();
	}



	int sheepcount = 0;
	int nrow=0,ncol=0;
	while(sheepcount<numSheep)
	{
		nrow=(qrand()*qrand()+qrand())%GRIDROW;
		ncol=(qrand()*qrand()+qrand())%GRIDCOL;
		if (wsWorld.getAt(nrow,ncol)==ISEMPTY && ((nrow>=0 && nrow<GRIDROW) && (ncol>=0 && ncol<GRIDCOL)))
		{
			sheepcount++;
			CSheep *s=new CSheep(&wsWorld,nrow,ncol);
		}
	}

	int wolfcount = 0;
	while(wolfcount<numWolf)
	{
		nrow=(qrand()*qrand()+qrand())%GRIDROW;
		ncol=(qrand()*qrand()+qrand())%GRIDCOL;
		if (wsWorld.getAt(nrow,ncol)==ISEMPTY && ((nrow>=0 && nrow<GRIDROW) && (ncol>=0 && ncol<GRIDCOL)))
		{
			wolfcount++;
			CWolf *w=new CWolf(&wsWorld,nrow,ncol);
		}
	}

	for (int nr=0;nr<GRIDROW;nr++)
	{
		for (int nc=0;nc<GRIDCOL;nc++)
		{
			CGrass *g=new CGrass(&wsWorld,nr,nc);
		}
	}

	display();
	
}

void WolfAndSheep_qtver::startSimulate()
{
	int dtime;
	dtime=450*double(101-ui.speedS->value())/100.0+50;
	steptimer.start(dtime);
}

void WolfAndSheep_qtver::pauseSimulate()
{
	if (steptimer.isActive())
	{
		steptimer.stop();
	}
}

void WolfAndSheep_qtver::display()
{
	//显示当前World
	QImage gridimg(GRIDROW,GRIDCOL,QImage::Format_RGB32);
	QRgb colorv;

	for (int nr=0;nr<GRIDROW;nr++)
	{
		for (int nc=0;nc<GRIDCOL;nc++)
		{
			if (wsWorld.getAt(nr,nc)!=ISEMPTY)
			{
				if (wsWorld.getAt(nr,nc)->getType()==ISMSHEEP ||wsWorld.getAt(nr,nc)->getType()==ISFSHEEP)
				{
					colorv=qRgb(255,255,255);
				}
				if (wsWorld.getAt(nr,nc)->getType()==ISMWOLF ||wsWorld.getAt(nr,nc)->getType()==ISFWOLF)
				{
					colorv=qRgb(0,0,0);
				}
			}
			else
			{
				colorv=qRgb(0,200,0);
			}
			gridimg.setPixel(nr,nc,colorv);
		}
	}

	gridimg=gridimg.scaled(546,250,Qt::KeepAspectRatio);
	ui.gridview->setPixmap(QPixmap::fromImage(gridimg));
}

void WolfAndSheep_qtver::Simulate()
{
	wsWorld.SimulateOneStep();
	Statistics();
	display();
	//drawnumline();
}

void WolfAndSheep_qtver::changeSpeed(int ts)
{
	int dtime;
	dtime=450*double(101-ts)/100.0+50;
	steptimer.setInterval(dtime);
}

void WolfAndSheep_qtver::Statistics()
{
	numSheep=0;
	numWolf=0;
	for (int nr=0;nr<GRIDROW;nr++)
	{
		for (int nc=0;nc<GRIDCOL;nc++)
		{
			if (wsWorld.getAt(nr,nc)!=ISEMPTY)
			{
				if (wsWorld.getAt(nr,nc)->getType()==ISFSHEEP || wsWorld.getAt(nr,nc)->getType()==ISMSHEEP)
				{
					numSheep++;
				}
				if (wsWorld.getAt(nr,nc)->getType()==ISFWOLF || wsWorld.getAt(nr,nc)->getType()==ISMWOLF)
				{
					numWolf++;
				}
			}
		}
	}
}

void WolfAndSheep_qtver::drawnumline()
{
	vec_sheepnum.append(numSheep);
	vec_wolfnum.append(numWolf);

	QVector<qreal> numidex;
	numidex.clear();
	for (int i=0;i<vec_sheepnum.size();i++)
	{
		numidex.append(i);
	}

	//构造曲线数据
	sheepCurve->setSamples(numidex,vec_sheepnum);
	wolfCurve->setSamples(numidex,vec_wolfnum);

	//sheepCurve->attach(ui.qwtPlot);
	//wolfCurve->attach(ui.qwtPlot);

	ui.qwtPlot->replot();
	//update();
}