#include "mainWin.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	mainWin w;
	w.show();
	return a.exec();
}
