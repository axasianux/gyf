#ifndef OPERATION_H
#define OPERATION_H

#include <QtCore>
#include <QtGui>
#include <iostream>

using namespace std;

enum SYMBOL
{
	EMPTY = 0,
	ADD   = 1, 
	SUB   = 2, 
	MUL   = 3, 
	DIV   = 4,
};

class Operation
{
public:
	Operation();
	virtual double get_result();
	//double get_result();

	double num_A;
	double num_B;
};

class OperationAdd : public Operation
{
public:
	OperationAdd(){cout << "OperationAdd\n";};
	double get_result();
};

class OperationSub : public Operation
{
public:
	OperationSub(){};
	double get_result();
};

class OperationMul : public Operation
{
public:
	OperationMul(){};
	double get_result();
};

class OperationDiv : public Operation
{
public:
	OperationDiv(){};
	double get_result();
};

class OperationFactory
{
public:
	OperationFactory(){};
	SYMBOL symbol;
	Operation *createOperate(SYMBOL symbol);
};

/*int main(int argc,char *argv[])
{
	Operation oper;
	OperationFactory factory;
	oper = factory.createOperate("+");
	oper.num_A = 1;
	oper.num_B = 2;
	double result = oper.get_result();
}*/

#endif
