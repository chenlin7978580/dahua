/*
 *===========================
 *       商场收银器
 *===========================
 */
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

class CashSuper
{
public:
	virtual double acceptCash(double money) = 0;
};

class CashNormal : public CashSuper
{
public:
	virtual double acceptCash(double money)
	{
		return money;	
	}
};

class CashRebate : public CashSuper
{
public:
	bool setRebate(double _rebate){ this->rebate = _rebate; }
	virtual double acceptCash(double money)
	{
		return money*rebate;
	}

private:
	double rebate = 1.0;
};

class CashReturn : public CashSuper
{
public:
	CashReturn()
	{
		init();
	}

	//二分查找(upper_bound算法)
	double my_return_money(double key)
	{
		if(recondition.empty()) return 0.0;
		int count = recondition.size();	
		auto first = recondition.begin();
		while(count > 0)
		{
			auto it = recondition.begin();	
			int step = count/2;
			advance(it, step);
			if(it->first <= key)
			{
				first = ++it;
				count -= step+1;
			}
			else
				count = step;
		}

		if(first == recondition.begin())
			return 0.0;
		else
			return (--first)->second;
	}

	virtual double acceptCash(double money)
	{
		double retCash = 0;
		cout << my_return_money(money) << endl; 
		return money;
	}

	void init()
	{
		recondition.insert(std::make_pair(300.0,100.0));
		recondition.insert(std::make_pair(500.0,200.0));
	}
private:
	std::map<double,double> recondition;
};

//工厂
class CashFactory
{
//switch(type)
};
int main()
{
	CashReturn cr;
	for(int i = 0; i < 10; ++i)
	{
		double money = 0.0;
		cin >> money;
		cout << cr.acceptCash(money) << endl;
	}
	return 0;
}
