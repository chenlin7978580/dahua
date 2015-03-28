/*
*====================================== 
*             简易计算器实现
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

int main()
{
	cout << "请求输入A:";
	string str1;
	str1.clear();
	cin >> str1;
	if(!isAllDigit(str1))
	{
		cout << "非法的输入" << endl;
		return -1;
	}
	int numA = 0;
	stringstream stream1;
	stream1 << str1;
	stream1 >> numA;

	cout << "请输入运算符:";
	string op;
	cin >> op;
	if(!isOperator(op))
	{
		cout << "非法的输入" << endl;
		return -1;
	}

	cout << "请求输入B:";
	str1.clear();
	cin >> str1;
	if(!isAllDigit(str1))
	{
		cout << "非法的输入" << endl;
		return -1;
	}
	int numB = 0;
	stream1.clear();
	stream1.str("");
	stream1 << str1;
	stream1 >> numB;

	//NND不能用case...
	if(op == "+")
		cout << (numA + numB) << endl;
	else if(op == "-")
		cout << (numA - numB) << endl;
	else if(op == "*")
		cout << (numA * numB) << endl;
	else if(op == "/")
		cout << (numA / numB) << endl;

	return 0;
}


