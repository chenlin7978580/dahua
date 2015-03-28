/*
*====================================== 
*             简易计算器实现
*  update: 
*	1.将计算和显示分开-封装特性的实现
*	2.运算符的扩展-多态
*======================================
*/
#include <string>
#include <regex>
#include <iostream>
using namespace std;

class Operation
{
public:
	Operation()
		: m_numberA(0.0)
		, m_numberB(0.0)
	{
	}

	virtual ~Operation(){}

	double& numberA(){ return m_numberA; }
	double& numberB(){ return m_numberB; }

	virtual double getResult()
	{
		double result = 0;
		return result;
	}
private:
	double m_numberA;
	double m_numberB;
};

//加法
class OperationAdd : public Operation
{
public:
	virtual double getResult()
	{
		double result = 0;
		result = numberA() + numberB();
		return result;
	}
};

//减法
class OperationSub : public Operation
{
public:
	virtual double getResult()
	{
		double result = 0;
		result = numberA() - numberB();
		return result;
	}
};

//乘法
class OperationMul : public Operation
{
public:
	virtual double getResult()
	{
		double result = 0;
		result = numberA() * numberB();
		return result;
	}
};

//除法
class OperationDiv : public Operation
{
public:
	virtual double getResult()
	{
		double result = numberB() ? numberA() / numberB() : 0.0;
		return result;
	}
};

class OperationFactory
{
public:
	static Operation* createOperate(string opstr)
	{
		Operation* op = NULL;

		if(opstr == "+")
			op = new OperationAdd();
		else if(opstr == "-")
			op = new OperationSub();
		else if(opstr == "*")
			op = new OperationMul();
		else if(opstr == "/")
			op = new OperationDiv();
		return op;
	}
};


bool isAllDigit(string str)
{
	if(str.empty() || !regex_match(str, std::regex("\\d*")))
		return false;

	return true;
}

bool isOperator(string str)
{
	if(str.empty() || str.size() != 1 || !regex_match(str, std::regex("[-+\\*\\/]")))
		return false;

	return true;
}

double getResult(double numA, double numB, string op)
{
	double result = 0.0; 

	if(op == "+")
		result = numA + numB;
	else if(op == "-")
		result = numA - numB;
	else if(op == "*")
		result = numA * numB;
	else if(op == "/")
		result = numB ? numA / numB : 0.0;
	return result;
}

int getNum()
{
	int result = 0;
	string str1;
	str1.clear();

	cout << "请输入数字:";
	cin >> str1;
	while(!isAllDigit(str1))
	{
		cout << "非法的输入，重新输入: ";
		str1.clear();
		cin >> str1;
	}
	stringstream stream1;
	stream1 << str1;
	stream1 >> result;
	return result;
}

string getOperator()
{
	string op;
	cout << "请输入运算符:";
	cin >> op;
	while(!isOperator(op))
	{       
		cout << "非法的输入，重新输入: ";
		op.clear();
		cin >> op;
	}

	return op;
}

int main()
{
	/*
	int numA = getNum();
	string op = getOperator();
	int numB = getNum();
	cout << "运算结果: " << getResult(numA, numB, op) << endl;
	cout << (12/43) << endl;
	*/
	Operation* oper;
	oper = OperationFactory::createOperate("+");
	oper->numberA() = 1;
	oper->numberB() = 2;
	double result = oper->getResult();
	cout << oper->numberA() << "+" << oper->numberB() << "=" << result << endl;

	oper->numberA() = 3;
	oper->numberB() = 5;
	result = oper->getResult();
	cout << oper->numberA() << "+" << oper->numberB() << "=" << result << endl;

	delete oper;
	return 0;
}

