#include <QApplication>
#include "widget.h"

int main(int argc,char *argv[])
{
	QApplication a(argc,argv);

	Widget *w = new Widget;
	w->show();

	a.exec();
	delete w;
	return 0;
}
