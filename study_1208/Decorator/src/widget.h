#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui>
#include <QtCore>
#include "operation.h"

class Button : public QPushButton
{
	Q_OBJECT
public:
	Button(int i,QWidget *parent = 0);
	int i;

public slots:
	void emit_num();

signals:
	void cur_num(QString str, int i);
};

class Widget : public QWidget
{
	Q_OBJECT
public:
	Widget(QWidget *parent = 0);

public slots:
	void test(QString str,int i);
	void clear_num_tmp();
	void equal();
	void clear_all();

private:
	//QPushButton *num[9];
	Button *num[12];
	Button *type[4];
	Button *delete_all;
	//QTextEdit *text_label;
	QTextBrowser *text_label;
	//QLabel *text_label;

	QString num_tmp;
	QString num_A;
	QString num_B;
	SYMBOL symbol;
};
#endif
