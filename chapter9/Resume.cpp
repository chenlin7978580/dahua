#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
//简历
class Resume
{
private:
		string name;
		string sex;
		string age;
		string timeArea;
		string company;
public:
		Resume(string name)
		{
				this->name = name;
		}

		//设置个人信息
		void SetPersonalInfo(string sex, string age)
		{
				this->sex = sex;
				this->age = age;
		}

		//设置工作经历
		void SetWorkExperience(string timeArea, string company)
		{
				this->timeArea = timeArea;
				this->company = company;
		}

		//显示
		void Display()
		{
				printf("个人信息：%s, %s ,%s\n", name.c_str(), sex.c_str(), age.c_str());
				printf("工作经历：{%s} {%s}\n", timeArea.c_str(), company.c_str());
				cout << "======================="<<endl;
		}
};

int main()
{
		Resume* a = new Resume("大鸟");
		a->SetPersonalInfo("男", "29");
		a->SetWorkExperience("1998-2000", "XX公司");

		Resume* b = new Resume("大鸟");
		b->SetPersonalInfo("男", "29");
		b->SetWorkExperience("1998-2000", "XX公司");

		Resume* c = new Resume("大鸟");
		c->SetPersonalInfo("男", "29");
		c->SetWorkExperience("1998-2000", "XX公司");


		a->Display();
		b->Display();
		c->Display();

		return 0;
}

