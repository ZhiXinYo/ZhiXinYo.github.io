#include "String.h"
#include <cstring>
#include <math.h>

String::String(const char* s) {
    str = new char[strlen(s) + 1];
    strcpy(str, s);
}

String::String(const char* s, int n) {
    int i, m = strlen(s);
    if (m < n) n = m;
    if (n < 0) n = 0;
    str = new char[n + 1];
    for (i = 0; i < n; i++)
        str[i] = s[i];
    str[i] = '\0';
}

String::String(int n, char c) {
    int i;
    if (n < 0) n = 0;
    str = new char[n + 1];
    for (i = 0; i < n; i++)
        str[i] = c;
    str[i] = '\0';
}

String::String(const String& s) {
    str = new char[s.Length() + 1];
    Strcpy(s.str);
}

String::String(const String& s, int pos, int n) {
    int i, m;
    m = s.Length();
    if (pos > m) {
        str = new char[1];
        str[0] = '\0';
        cout << "发现异常：起始位置大于该字符串的长度" << endl;
        return;
    }
    if (m - pos < n) n = m - pos;
    if (n < 0) n = 0;
    str = new char[n+1];
    for (i = 0; i < n; i++)
        str[i] = s.str[pos + i];
    str[i] = '\0';
}

String& String::operator=(const String& s) {
    if (str == s.str)
        return *this;
    delete[] str;
    if (str != s.str) {
        int i = 0;
        str = new char[s.Length() + 1];
        while (s.str[i] != '\0') {
            str[i] = s.str[i];
            i++;
        }
        str[i] = '\0';
    }
    return *this;
}

String::~String() {
    if (str!=NULL)
        delete[] str;
}

void String::Strcpy(const String& s2) {
    int i;
    for (i = 0; s2.str[i] != '\0'; i++)
        str[i] = s2.str[i];
    str[i] = '\0';
}

String& String::Insert(int n, const char* s) {
    int m = Length();
    if (n > m) {
        cout << "发现异常：插入位置n大于该字符串长度，已自动将新串插入到该串末尾" << endl;
        n = m;
    } 
    char* p = new char[Length() + strlen(s) + 1];
    strncpy(p, str, n);
    p[n] = '\0';
    strcat(p, s);
    strcat(p, str + n);
    delete[] str;
    str = p;
    return *this;
}

String String::GetSubstr(int pos, int n) const throw(int) {
    if (pos > Length()) {
        throw -1;
        return "\0";
    }
    String temp(*this, pos, n);
    return temp;
}

int String::Find(const String& s) const {
    int i, j, m, n, flag;
    m = s.Length();
    n = Length();
    if (m > n) {
        cout << "发现异常：所要查找的字符串不能比原字符串长" << endl;
        return -1;
    }
        
    for (i = 0; i < n - m; i++) {
        flag = 1;
        for (j = 0; j < m; j++) {
            if (str[i + j] != s.str[j]) {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
            return i;
    }
    return -1;
}
const size_t String::Length() const {
    int length = 0;
    while (str[++length]);
    return length;
}

void String::Swap(String& s2) {
    char* temp = s2.str;
    s2.str = str;
    str = temp;
}

const char* String::C_str() {
    return str;
}

char& String::operator[](int index) throw(int) {
    if (index > Length()) throw 0;
    return str[index];
}

void String::Reverse() {
    int i = 0, j = Length() - 1;
    if (i >= j) return;
    while (i < j) {
        char t = str[i];
        str[i] = str[j];
        str[j] = t;
        i++;
        j--;
    }
    return;
}

void String::Upper(String& s) {
    for (int i = 0; i < s.Length(); i++) {
        if (s.str[i] >= 'a' && s.str[i] <= 'z')
            s.str[i] -= 'a'-'A';
    }
}

void String::Lower(String& s) {
    for (int i = 0; i < s.Length(); i++) {
        if (s.str[i] >= 'A' && s.str[i] <= 'Z')
            s.str[i] += 'a' - 'A';
    }
}

int String::NumTransfer() throw(double, char) {
    int len;
    int res = 0;
    len = Length();
    
    for (int i = 0; i < len; i++) {
        if (str[i] == '.') {
            throw 1.0;
        }
        if (!(str[i] >= '0'&&str[i]<='9')) {
            throw '0';
        }
    }
       
    for (int i = 0; i < len; i++) {
        res = res + ((int)str[len - i - 1] - (int)'0') * pow(10, i);
    }
    return res;
}

void String::Erase(int pos, int n) {
    char* temp;
    if (pos < 0 || this->str == nullptr || this->Length() < pos + n) return;
    int newLenght = this->Length() - n;
    temp = new char[newLenght + 1];
    for (int i = 0; i < newLenght + 1; i++) {
        if (i < pos)
            temp[i] = this->str[i];
        else if (i >= pos)
            temp[i] = this->str[i + n];
    }
    this->~String();
    this->str = temp;
    this->str[Length()] = '\0';
}

void String::Clear() {
    str[0] = '\0';
}

void String::Replace(const char ch1, const char ch2) {
    for (int i = 0; i < Length(); i++)
        if (str[i] == ch1)
            str[i] = ch2;
}

bool String::Empty() const {
    return (str[0] == '\0');
}

String operator+(const String& s1, const String& s2) {
    String temp;
    temp.str = new char[s1.Length() + s2.Length() + 1];
    temp.Strcpy(s1.str);
    strcat(temp.str, s2.str);
    return temp;
}

String& String::operator+=(const String& s2) {
    *this = *this + s2;
    return *this;
}

bool operator==(const String& s1, const String& s2) {
    if (strcmp(s1.str, s2.str) == 0)
        return true;
    else
        return false;
}

bool operator!=(const String& s1, const String& s2) {
    if (strcmp(s1.str, s2.str) != 0)
        return true;
    else
        return false;
}

bool operator>(const String& s1, const String& s2) {
    if (strcmp(s1.str, s2.str) > 0)
        return true;
    else
        return false;
}

bool operator>=(const String& s1, const String& s2) {
    if (strcmp(s1.str, s2.str) >= 0)
        return true;
    else
        return false;
}

bool operator<(const String& s1, const String& s2) {
    if (strcmp(s1.str, s2.str) < 0)
        return true;
    else
        return false;
}

bool operator<=(const String& s1, const String& s2) {
    if (strcmp(s1.str, s2.str) <= 0)
        return true;
    else
        return false;
}

void String::Compare(const String& s) {    
    cout << "第一个字符串 = " << str << endl;
    cout << "第二个字符串 = " << s.str;
    if (strcmp(str, s.str) == 0)
        cout << "\t\t两个字符串相等" << endl << endl;
    else {
        if (strcmp(str, s.str) < 0)
            cout << "\t\t两字符串不等 且 前者大于后者" << endl << endl;
        else
            cout << "\t\t两字符串不等 且 后者大于前者" << endl << endl;
    }
}

ostream& operator<<(ostream& out, const String& s) {
    out << s.str;
    return out;
}

istream& operator>>(istream& in, String& s) {
    char str[1000];
    in >> str;
    s = str;
    return in;
}
