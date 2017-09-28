#ifndef Calculator_H
#define Calculator_H
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<afx.h>//CString 头文件
using namespace std;

class calculator{
public:
	calculator(string&a,int base) :infix(a),answer(0),isexception(0){
		suffix.clear();
		bas=basenumber[base];
	}//初始化计算器
    calculator(CString&a,int base) :infix(a.GetBuffer(a.GetLength())){
		answer=isexception=0;
		suffix.clear();
		bas=basenumber[base];
	}//初始化计算器
	void setinfix(string);//设置中缀表达式
	string getinfix();    //获取
	void setanswer(double=0);//设置答案
	CString getanswer();//获取答案
    void setisexception(int=0);//isexception设置函数
    int getisexception();//isexception取值函数
    double turnnumber(string);//转换数字

	bool isnumber(char);//判断是否为数字
	int priority(char);//运算符优先级函数

    void setsuffix();//求逆波兰表达式
	void calculate();//求解逆波兰表达式的值
	void operate();//求逆波兰表达式并求值
	void modify();//计算结果进制转换

    static const string iexcept[5];//静态常量异常类型
	static const int basenumber[4];//静态基数

private:
  string infix;
  vector<string>suffix;
  stack<string>operation;
  stack<double>calcul;
  string ansstring;
  int isexception;
  double answer;
  int bas;
};

#endif