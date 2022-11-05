#include "String.h"
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	void test1(), test2(), test3();
	int select = 0;
	while (true)
	{
		cout << "\t字符串类测试" << endl;
		cout << "1 --- 构造函数及运算符测试" << endl;
		cout << "2 --- 其他成员函数测试" << endl;
		cout << "3 --- 异常处理" << endl;
		cout << "0 --- 退出" << endl;
		cout << "请输入选项：" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			test1(); break;
		case 2:
			test2(); break;
		case 3:
			test3(); break;
		case 0:
			return 0;
		}
	}
	return 0;
}
