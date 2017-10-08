#include "wolfandsheep_qtver.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	WolfAndSheep_qtver w;
	w.show();
	return a.exec();
}
