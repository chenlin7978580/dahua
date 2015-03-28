/*
*====================================== 
*             简易计算器实现
*  update: 将计算和显示分开-封装特性的实现
*======================================
*/
#include <string>
#include <regex>
#include <iostream>
using namespace std;

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
	int numA = getNum();
	string op = getOperator();
	int numB = getNum();
	cout << "运算结果: " << getResult(numA, numB, op) << endl;
	cout << (12/43) << endl;
	return 0;
}

