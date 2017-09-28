#ifndef Calculator_H
#define Calculator_H
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<afx.h>//CString ͷ�ļ�
using namespace std;

class calculator{
public:
	calculator(string&a,int base) :infix(a),answer(0),isexception(0){
		suffix.clear();
		bas=basenumber[base];
	}//��ʼ��������
    calculator(CString&a,int base) :infix(a.GetBuffer(a.GetLength())){
		answer=isexception=0;
		suffix.clear();
		bas=basenumber[base];
	}//��ʼ��������
	void setinfix(string);//������׺���ʽ
	string getinfix();    //��ȡ
	void setanswer(double=0);//���ô�
	CString getanswer();//��ȡ��
    void setisexception(int=0);//isexception���ú���
    int getisexception();//isexceptionȡֵ����
    double turnnumber(string);//ת������

	bool isnumber(char);//�ж��Ƿ�Ϊ����
	int priority(char);//��������ȼ�����

    void setsuffix();//���沨�����ʽ
	void calculate();//����沨�����ʽ��ֵ
	void operate();//���沨�����ʽ����ֵ
	void modify();//����������ת��

    static const string iexcept[5];//��̬�����쳣����
	static const int basenumber[4];//��̬����

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