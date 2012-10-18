#include "cash.h"

double CashNormal::acceptCash(double money)
{
	return money;
}

CashRebate::CashRebate(double moneyRebate)
{
	this->moneyRebate = moneyRebate;
}

double CashRebate::acceptCash(double money)
{
	return money*moneyRebate;
}

CashReturn::CashReturn(double moneyCondition, double moneyReturn)
{
	this->moneyCondition = moneyCondition;
	this->moneyReturn = moneyReturn;
}

double CashReturn::acceptCash(double money)
{
	double result = money;
	if(money >= moneyCondition)
	{
		result = money - (money / moneyCondition) * moneyReturn;
	}
	return result;
}

CashFactory::CashFactory(Type type)
{
	cash = NULL;
	switch(type)
	{
		case NORMAL:
			{
				CashNormal *cash_tmp_1 = new CashNormal();
				cash = cash_tmp_1;
			}
			break;
		case REBATE:
			{
				CashRebate *cash_tmp_2 = new CashRebate(0.8);
				cash = cash_tmp_2;
			}
			break;
		case RETURN:
			{
				CashReturn *cash_tmp_3 = new CashReturn(300,100);
				cash = cash_tmp_3;
			}
			break;
	}
}

double CashFactory::get_result(double money)
{
	return cash->acceptCash(money);
}

int main(int argc,char *argv[])
{
	CashFactory factory_1(NORMAL);
	double i = factory_1.get_result(1000);

	CashFactory factory_2(REBATE);
	double j = factory_2.get_result(1000);

	CashFactory factory_3(RETURN);
	double k = factory_3.get_result(1000);

	cout << "factory_1 result is " << i << "\n"
	     << "factory_2 result is " << j << "\n"
		 << "factory_3 result is " << k << "\n";
}
