#include "operation.h"

Operation::Operation()
{
    num_A = 0;
    num_B = 0;
}

double Operation::get_result()
{
    return 0;
}

double OperationAdd::get_result()
{
    double result = 0;
    result = num_A + num_B;
    return result;
}

double OperationSub::get_result()
{
    double result = 0;
    result = num_A - num_B;
    return result;
}

double OperationMul::get_result()
{
    double result = 0;
    result = num_A * num_B;
    return result;
}

double OperationDiv::get_result()
{
    double result = 0;
    if(num_B == 0)
    {
        return -1;
    }
    else
    {
        result = num_A / num_B;
        return result;
    }
}

Operation *OperationFactory::createOperate(SYMBOL symbol)
{
    Operation *oper = NULL;
    switch(symbol)
    {
    	case ADD:
        	oper = new OperationAdd;
        	break;
    	case SUB:
        	oper = new OperationSub;
        	break;
    	case MUL:
        	oper = new OperationMul;
        	break;
    	case DIV:
        	oper = new OperationDiv;
        	break;
		case EMPTY:
			break;
    }
    return oper;
}

/*int main(int argc,char *argv[])
{
	Operation *oper = NULL;
	OperationFactory factory;
	oper = factory.createOperate("+");
	oper->num_A = 1;
	oper->num_B = 2;
	double result = oper->get_result();
	//cout << oper->num_A << "\t" << oper->num_B;
	cout << result << "+++++++++++\n";
}

*/
