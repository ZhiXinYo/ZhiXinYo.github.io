#include "String.h"
#include <iostream>
#include <cstring>
using namespace std;

void test1() {
	cout << "=====================构造、拷贝、赋值函数及运算符测试=====================" << endl;
	cout << "\t通过不同的方式初始化若干字符串，利用运算符构成句子" << endl;
	String s1 = "i ", s2("am "), s3("in ", 3), s4, s5;
	cout << "String s1 = \"i \"\t\ts1 = " << s1 << endl;
	cout << "String s2(\"am \")\t\ts2 = " << s2 << endl;
	cout << "String s3(\"in \", 3)\t\ts3 = " << s3 << endl;
	cout << "请输入s4：（测试>>）" << endl;
	cin >> s4;
	cout << "cin >> s4\t\t\ts4 =" << s4 << endl;
	s5 = s1 + s2 + s3 + s4;
	cout << "s5 = s1 + s2 + s3 + s4（测试+）\ts5 = " << s5 << endl;
	s5[0] = 'I';
	cout << "s5[0] = 'I'（测试[]）\t\ts5 = " << s5 << endl;
	String s6="I am happy.";
	cout << "String s6=\"I am happy.\"\t\ts6 = " << s6 << endl;
	s5 += s6;
	cout << "s5 += s6\t\t\ts5 = " << s5 << endl;
	s5.Insert(11, ",");
	cout << "s5.Insert(11, \", \")插入逗号得到完整的句子：s5 = " << s5 << endl << endl;
	
	cout << "\t\t未涉及到的构造、拷贝函数测试" << endl;
	String s8(9, '6'), s9(s8, 0, 3), s10(s9);
	cout << "String s8(9, 'c')\t\ts8 = " << s8 << endl;
	cout << "String s9(s8, 0, 2)\t\ts9 = " << s9 << endl;
	cout << "String s10(s9)\t\t\ts10 = " << s10 << endl << endl;

	cout << "\t\t关系运算符测试" << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s9 = " << s9 << endl;
	cout << "s10 = " << s10 << endl;
	cout << boolalpha << "(s3 > s1) \tis:" << (s3 > s1) << endl;
	cout << boolalpha << "(s3 < s1) \tis:" << (s3 < s1) << endl;
	cout << boolalpha << "(s3 >= s1) \tis:" << (s3 >= s1) << endl;
	cout << boolalpha << "(s9 <= s10) \tis:" << (s9 <= s10) << endl;
	cout << boolalpha << "(s9 == s10) \tis:" << (s9 == s10) << endl;
	cout << boolalpha << "(s9 != s10) \tis:" << (s9 != s10) << endl;
	
	cout << "测试完毕！" << endl << endl;
	return;
}

void test2() {
	String s1 = "abefg", s2 = "cd", s3 = "abcde123abc", s4 = "abc", s5 = "123", 
		s6 = "aBcdEFg123Abc", s7 = "abcde", s8 = "abcddefg",s9 = "abc44efg";
	cout << "========================其他成员函数测试========================" << endl;
	
	cout << "Strcpy()函数测试" << endl;
	cout << "s1=" << s1 << endl;
	cout << "s2=" << s2 << endl;
	s1.Strcpy(s2);
	cout << "s1.Strcpy(s2)\t\t\t复制后：s1=" << s1 << "\ts2=" << s2 << endl << endl;
	
	cout << "Insert()函数测试" << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "将s2插入s1中" << endl;
	cout << "s1.Insert(2, s2.C_str())\ts1 = " << s1.Insert(2, s2.C_str()) << endl << endl;

	cout << "GetSubstr()函数测试" << endl;
	cout << "s1 = " << s1 << endl;
	cout << "取s1中c-f的子串" << endl;
	cout << "s1.GetSubstr(2, 4)\t\tsubstr = " << s1.GetSubstr(2, 4) << endl << endl;

	cout << "Find()函数测试" << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s3.Find(\"bc\")\t\t\t字符串bc第一次出现的下标：" << s3.Find("bc") << endl;
	cout << "s3.Find(\"2\")\t\t\t字符2第一次出现的下标：" << s3.Find("2") << endl << endl;

	cout << "Length()函数测试" << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s3.Length()\t\t\t字符串s3的长度为：" << s3.Length() << endl << endl;

	cout << "Swap()函数测试" << endl;
	cout << "s4 = " << s4 << "  s5 = " << s5 << endl;
	s4.Swap(s5);
	cout << "s4.Swap(s5)交换后：" << "\t\ts4 = " << s4 << "\ts5 = " << s5 << endl << endl;

	cout << "Reverse()函数测试" << endl;
	cout << "s5 = " << s5 << endl;
	s5.Reverse();
	cout << "s5.Reverse()逆序后：\t\ts5 = " << s5 << endl << endl;

	cout << "Upper()和Lower()函数测试" << endl;
	cout << "s6 = " << s6 << endl;
	s6.Upper(s6);
	cout << "s6.Upper(s6)后：\t\ts6 = " << s6 << endl;
	s6.Lower(s6);
	cout << "s6.Lower(s6)后：\t\ts6 = " << s6 << endl<< endl;
	
	cout << "NumTransfer()函数测试" << endl;
	cout << "s4 = " << s4 << endl;
	int num = s4.NumTransfer();
	cout << "int num = s4.NumTransfer()\t转换为数值后：num = " << num << endl;
	cout << "num+100测试是否可以运算：\tnum + 100 = " << num + 100 << endl << endl;
	
	cout << "Erase()函数测试" << endl;
	cout << "s6 = " << s6 << endl;
	s6.Erase(3,6);
	cout << "s6.Erase(3,6)\t\t\t删除从下标3开始往后6个字符后：s6 = " << s6 << endl << endl;

	cout << "Clear()函数和Empty()测试" << endl;
	cout << "s6 = " << s6 << endl;
	s6.Clear();
	cout << "s6.Clear()\t\t\t清空后s6 = " << s6 << endl;
	cout << boolalpha << "s6.Empty()\t\t\ts6为空串：" << s6.Empty() << endl << endl;

	cout << "Replace()函数测试" << endl;
	cout << "s8 = " << s8 << endl;
	s8.Replace('d', '4');
	cout << "s8.Replace('d', '4')\t\t将s8中的'd'用'4'代替：s8 = " << s8 << endl << endl;

	cout << "Compare()函数测试" << endl;
	s7.Compare(s8);
	s8.Compare(s9);
	s9.Compare(s7);
	cout << endl;

	cout << "测试完毕！" << endl << endl;
	return;
}

void test3() {
	
	cout << "异常处理1-----拷贝构造函数越界" << endl;
	cout << "String s1 = \"12345\",执行:String s2(s1, 6, 2)" << endl;
	cout << "从s1的第6位开始开始向后取2个字符（越界）" << endl;
	String s1 = "12345", s2(s1, 6, 2);
	cout << endl;
	
	cout << "异常处理2-----Insert()函数越界" << endl;
	String s3 = "abc";
	cout << "执行：s1.Insert(6, s3.C_str())" << endl;
	s1.Insert(6, s3.C_str());
	cout << "s1 = " << s1 << endl;
	cout << endl;


	cout << "异常处理3-----GetSubstr()函数越界" << endl;
	cout << "s1 = " << s1 << endl;
	cout << "执行：s1.GetSubstr(10, 5)" << endl;
	try {
		cout << s1.GetSubstr(10, 5) << endl;
	}
	catch (int) {
		cout << "发现异常：子串的起始位置不能比原字符串长" << endl;
	}
	cout << endl;
	
	cout << "异常处理4-----Find()函数越界" << endl;
	cout << "s3 = " << s3 << endl;
	cout << "执行：s3.Find(\"abcd\");" << endl;
	s3.Find("abcd");
	cout << endl;

	String s4 = "abe";
	cout << "异常处理5-----[]下标越界" << endl;
	cout << "s1=" << s4 << endl;
	for (int i = 0; i < 5; i++) {
		try {
			cout <<"未越界：" << s4[i] << endl;	
		}
		catch (int) {
			cout << "发现异常：下标越界" << endl;
		}
	}
	cout << endl;

	String str[5] = {
		"abe","456","12.3","abcde123ab","12345"
	};
	cout << "异常处理6-----NumTransfer()函数转换失败" << endl;
	int x;
	cout << "str=" << str[0] << ", " << str[1] << ", " << str[2] << ", " << str[3] << ", " << str[4] << endl;
	for (int i = 0; i < 5; i++) {
		try {
			x = str[i].NumTransfer();
			cout << "成功转换为整型x=" << x << endl;
		}
		catch (char) {
			cout << "发现异常：输入的字符串中含有非数字类字符" << endl;
		}
		catch (double) {
			cout << "发现异常：输入的字符串为浮点数" << endl;
		}
	}

	cout << "测试完毕！" << endl << endl;
	return;
}
