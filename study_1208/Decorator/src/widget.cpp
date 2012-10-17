#include "widget.h"

Button::Button(int i,QWidget *parent)
	:QPushButton(parent)
{
	this->i = i;
}

void Button::emit_num()
{
	emit cur_num(this->text(),i);
}

Widget::Widget(QWidget *parent)
	:QWidget(parent)
{
	//text_label = new QTextEdit(this);
	text_label = new QTextBrowser(this);
	//text_label = new QLabel(this);
	text_label->resize(200,30);
	//text_label->setText("");
	text_label->move(50,20);

	num_tmp = "";
	num_A = "";
	num_B = "";
	symbol = EMPTY;

	QWidget *container = new QWidget(this);
	container->resize(200,200);
	container->move(50,110);

	for(int i = 0;i<12;i++)
	{
		if(i == 9)
		{
			//num[i] = new QPushButton(this);
			num[i] = new Button(1, container);
			num[i]->setText(QString("0"));
			num[i]->resize(45,45);
			num[i]->move(50,150);
		}
		else if(i == 10)
		{
			num[i] = new Button(1,container);
			num[i]->setText(QString("."));
			num[i]->resize(45,45);
			num[i]->move(0,150);
		}
		else if(i == 11)
		{
			num[i] = new Button(1,container);
			num[i]->setText(QString("="));
			num[i]->resize(45,45);
			num[i]->move(100,150);
		}
		else
		{
			num[i] = new Button(1,container);
			num[i]->setText(QString("%1").arg(i+1));
			num[i]->resize(45,45);
			num[i]->move(50*(i%3),50*(i/3));
		}

		if(i == 11)
		{
			connect(num[i], SIGNAL(clicked()), num[i], SLOT(emit_num()));
			connect(num[i], SIGNAL(clicked()), this, SLOT(equal()));
		}
		else
		{
			connect(num[i], SIGNAL(clicked()), num[i], SLOT(emit_num()));
			connect(num[i], SIGNAL(cur_num(QString,int)), this, SLOT(test(QString,int)));
		}
	}

	for(int i = 0; i < 4; i++)
	{
		type[i] = new Button(0,container);
		switch(i)
		{
			case 0:
				type[i]->setText(QString("+"));
				break;
			case 1:
				type[i]->setText(QString("-"));
				break;
			case 2:
				type[i]->setText(QString("*"));
				break;
			case 3:
				type[i]->setText(QString("/"));
				break;
		}
		type[i]->resize(45,45);
		type[i]->move(150,50*i);

		connect(type[i], SIGNAL(clicked()), type[i], SLOT(emit_num()));
		connect(type[i], SIGNAL(cur_num(QString,int)), this, SLOT(test(QString,int)));
	}

	delete_all = new Button(1,this);
	delete_all->setText(QString("Delete"));
	delete_all->resize(200,45);
	delete_all->move(50,57);
	connect(delete_all, SIGNAL(clicked()), this, SLOT(clear_all()));

	setFixedSize(300,350);
}

void Widget::test(QString str, int i)
{
	if(i)
	{
		num_tmp.append(str);
		QString tmp = text_label->toPlainText();
		text_label->setText(tmp+str);
	}
	else
	{
		num_A = num_tmp;
		num_tmp = "";
		/*qDebug() << "num_A  :" << num_A 
			   << "\num_tmp :" << num_tmp;*/
		//text_label->clear();
		text_label->setText(text_label->toPlainText()+str);
		if(str == "+")
		{
			this->symbol = ADD;
		}
		else if(str == "-")
		{
			this->symbol = SUB;
		}
		else if(str == "*")
		{
			this->symbol = MUL;
		}
		else if(str == "/")
		{
			this->symbol = DIV;
		}
	}
}

void Widget::clear_num_tmp()
{
	num_tmp = "";
	text_label->clear();
}

void Widget::equal()
{
	num_B = num_tmp;
	num_tmp = "";
	qDebug() << "num_A  :" << num_A
		   << "\nnum_B  :" << num_B
		   << "\nnum_tmp :" << num_tmp;

	text_label->clear();

	Operation *oper = NULL;
	OperationFactory factory;
	oper = factory.createOperate(this->symbol);

	bool ok_1;
	bool ok_2;

	oper->num_A = this->num_A.toDouble(&ok_1);
	oper->num_B = this->num_B.toDouble(&ok_2);

	if(ok_1 && ok_2)
	{
		double result = oper->get_result();
		text_label->setPlainText(QString("%1").arg(result));

		num_A = "";
		num_B = "";
	}
	else
	{
		text_label->setPlainText(QString("ERROR"));
	}
}

void Widget::clear_all()
{
	text_label->clear();
	num_A = "";
	num_B = "";
	num_tmp = "";
	symbol = EMPTY;
}
