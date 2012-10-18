#ifndef STRATEGY_H
#define STRATEGY_H

#include <iostream>
using namespace std;

enum Type
{
	NORMAL,
	REBATE,
	RETURN,
};

class Cash
{
public:
	Cash(){};
	virtual double acceptCash(double money)=0;
};

class CashNormal : public Cash
{
public:
	CashNormal(){cout << "NORMAL\n";};
	double acceptCash(double money);
};

class CashRebate : public Cash
{
public:
	CashRebate(double moneyRebate);
	double acceptCash(double money);

private:
	double moneyRebate;
};

class CashReturn : public Cash
{
public:
	CashReturn(double moneyCondition, double moneyReturn);
	double acceptCash(double money);

private:
	double moneyCondition;
	double moneyReturn;
};

class CashFactory
{
public:
	CashFactory(Type type);
	Cash *cash;
	double get_result(double money);
};
#endif
