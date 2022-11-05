#pragma warning(disable:4996)
#ifndef STRING_H
#define STRING_H
#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char* str;

public:
    String(const char* s = "");            //构造函数
    String(const char* s, int n);
    String(int n, char c);
    String(const String& s);        //拷贝构造函数
    String(const String& s, int pos, int n);
    String& operator=(const String& s);      //赋值运算
    virtual ~String();                       //析构函数
    
    void Strcpy(const String& s2);          //字符串复制
    String& Insert(int n, const char* s);   //将s所指向的字符串插入在本串位置n之后
    String GetSubstr(int pos, int n) const throw(int);   //取子串，取从m位置开始的n个字符
    int Find(const String& s) const;       //获取s在本串中首次出现的位置
    const size_t Length() const;          //获取字符串长度
    const char* C_str();                //转换为C字符串
    void Swap(String& s2);              //交换两个字符串
    char& operator[](int index) throw(int);     //下标运算符，引用返回可做左值，右值
    void Reverse();             //将字符串逆序
    void Upper(String& s);        //将字符串中小写字母转换为大写字母
    void Lower(String& s);        //将字符串中大写字母转换为小写字母
    int NumTransfer() throw(double, char);  //throw(double, int);    //将字符串转为整数
    void Compare(const String& s);     //比较两个字符串
    void Erase(int pos, int n);     //删除字符串中从pos开始到n位置的字符
    void Clear();            //清空字符串
    bool Empty() const;      //判断字符串是否为空
    void Replace(const char ch1, const char ch2);  //将该字符串中字符str1用字符str2替换
  
    friend String operator+(const String& s1, const String& s2);  //字符串拼接
    String& operator+=(const String& s2);        //重载运算符+=
    //重载运算关系
    friend bool operator==(const String& s1, const String& s2);
    friend bool operator!=(const String& s1, const String& s2);
    friend bool operator>(const String& s1, const String& s2);
    friend bool operator>=(const String& s1, const String& s2);
    friend bool operator<(const String& s1, const String& s2);
    friend bool operator<=(const String& s1, const String& s2);
    //重载io流运算符
    friend ostream& operator<<(ostream& out, const String& s);   //重载运算符>>
    friend istream& operator>>(istream& in, String& s);          //重载运算符<<
};
#endif
