#include"calculator.h"
#include<iostream>
#include<stdexcept>
#include<string>
#include<cstdlib>//调用atof函数
#include<cstdio>
#include<stack>
#include<cmath>
#define M 65536
using namespace std;
const string function[6]={"sin(","cos(","tan(","asin(","acos(","atan("};

//初始化异常
const string calculator::iexcept[5]={"NONE.","Division by Zero!","Grammatical error!","No number!","Unknown error!"};
//初始化基数
const int calculator::basenumber[4]={2,8,10,16};

//infix的取值设置函数
void calculator::setinfix(string a){infix.assign(a);}
string calculator::getinfix() { return infix; }

//answer的取值设置函数
void calculator::setanswer(double x) { answer = x; }
CString calculator::getanswer(){
  CString t_t;
  if(!isexception)
  {
	  modify();
	  t_t.Format("%s",ansstring.c_str());
  }else t_t.Format("%s",iexcept[isexception].c_str());
  return t_t;
}

//isexception的设置取值函数
void calculator::setisexception(int x){isexception=x;}
int calculator::getisexception(){return isexception;}

//判断是否为数字
bool calculator::isnumber(char x){
  if(x>='0'&&x<='9')return true;
  if(x>='A'&&x<='F')return true;
  return (x=='.')?true:false;
}

//判定运算符的优先级
int calculator::priority(char x){
  if(x=='*'||x=='/')return 10;
  if(x=='+'||x=='-')return 8;
  if(x=='&')return 5;
  if(x=='^')return 4;
  if(x=='|')return 3;
  if (x == '(')return -1;
  return 0;
}
//C4018 "<": 有符号 / 无符号不匹配   length()是无符号位整型  
//所以用循环变量与其比较时循环变量也应该声明为无符号位整型  size_t  否则会有警报（也可运行）

void calculator::setsuffix(){
  string s;
  int tot,position,o;
  for(int i=0;i<infix.length();){
	  //将数字压入栈中
	  s = "";
	  while(i<infix.length()&&isnumber(infix[i]))
		  s+=infix[i++];
	  tot=0;
	  position=s.find(".");
	  while(position!=string::npos){
	    tot++;
		position=s.find(".",position+1);
	  }
	  //检查小数点
	  if(tot>=2)throw 2;
	  if (s.length())
		  suffix.push_back(s);
      
	  //处理运算符
	  while(i<infix.length()&&!isnumber(infix[i]))
		if(isalpha(infix[i]))
		{//处理函数
		  s="";
          while(isalpha(infix[i]))
		    s+=infix[i++];
		  if(infix[i]!='(')
			  throw 2;
		  s+=infix[i++];
		  operation.push(s);
		}else
		  if(infix[i]=='(')
		  {//处理 ( 
			s="";s+=infix[i++];
			operation.push(s);
		  }else if (infix[i] == ')')
		  { //处理 )

  
		    while(!operation.empty())
			{
			    s=operation.top();
                if(s[s.length()-1]=='(')
			  	    break;
			    suffix.push_back(s);
			    operation.pop();
			}

		    //检查括号
		    if(operation.empty())
		  	    throw 2;
             
		    //将函数和一般的括号分开处理
			operation.pop();
		    if(s.length()>1) 
			{
				for(o=0;o<6;o++)
					if(function[o]==s)
					  break;
				char ch='U'+o;
				s="";s+=ch;
				suffix.push_back(s);
			}

		    i++;
		  }
	      else 
		  {
		    //运算符栈弹出操作
		    tot=0;

		    while (!operation.empty())
			{
				s=operation.top();
				if(priority(s[s.length()-1])<priority(infix[i]))
					break;
			    suffix.push_back(s);
			    operation.pop();
			}

		    //当前运算符压栈
			tot++;
			s="";s+=infix[i++];
			operation.push(s);

			//检查是否有连续的操作运算符
			if(tot>=2)throw 2;
		  }
  }
  

  //清空运算符栈
  char ch;
  while(!operation.empty()){
    s=operation.top();
    ch=s[s.length()-1];
	//检查括号
	if(ch=='('||ch==')')
		throw 2;
	s="";s+=ch;
	suffix.push_back(s);
	operation.pop();
 }
}

//表达式中数的进制转换
double calculator::turnnumber(string s){
  int base=bas;
  double count=0,answer=0,t=0;
  for(size_t i=0;i<s.length();i++){
	  if(s[i]=='.'){
		count=i;break;
	  }
	  switch(base){
	  case 2:{
		  if(s[i]>'1')throw 2;
		  answer=answer*2+s[i]-'0';
		  break;}
      case 8:{
		  if(s[i]>'7')throw 2;
		  answer=answer*8+s[i]-'0';
		  break;}
	  case 10:{
		  if(s[i]>'9')throw 2;
		  answer=answer*10+s[i]-'0';
		  break;}
	  case 16:{
		  if(s[i]>'F')throw 2;
		  if(s[i]<='9')answer=answer*16+s[i]-'0';
		  else answer=answer*16+s[i]-'A'+10;
		  break;}
	  }
  }
  if(count)
  for(size_t i=s.length()-1;i>count;i--){
	  switch(base){
	  case 2:{
		  if(s[i]>'1')throw 2;
		  t+=s[i]-'0';
		  t=double(t/2);
		  break;}
      case 8:{
		  if(s[i]>'7')throw 2;
		  t+=s[i]-'0';
		  t=double(t/8);
		  break;}
	  case 10:{
		  if(s[i]>'9')throw 2;
		  t+=s[i]-'0';
		  t=double(t/10);
		  break;}
	  case 16:{
		  if(s[i]>'F')throw 2;
		  if(s[i]<='9'){
		    t+=s[i]-'0';
		    t=double(t/16);
		  }
		  else{
		    t+=s[i]-'A'+10;
		    t=double(t/16);
		  }
		  break;}
	  }
  }
  return answer+t;
}

//结果的进制转换
void calculator::modify(){
  int i,x,flag=answer<0?-1:1;
  int integer=flag<0?ceil(answer):floor(answer);
  double Decimal=answer-integer;
  char ch;
  string s="";
  if(flag<0)s+="-";
  if(!integer)s+='0';
	else while(integer){
	   x=(integer%bas)*flag;
       if(bas==16&&x>9)ch='A'+x-10;
	   else ch='0'+x;
	   s+=ch;
       integer/=bas;
	}
  s+='.';
  for(i=0;i<6;i++){
    Decimal*=bas;
    x=floor(Decimal*flag);
	if(bas==16&&x>9)ch='A'+x-10;
	   else ch='0'+x;
	s+=ch;
	Decimal-=x*flag;
  }
  ansstring=s;
}

void calculator::calculate(){
	string astr;
	double t1,t2;
	int tx1,tx2;
	if(!suffix.size())throw 3;//检查是否有内容
	for(size_t i=0;i<suffix.size();){
	  while(i<suffix.size()&&isnumber(suffix[i][0]))//数字压入栈中
		  calcul.push(turnnumber(suffix[i++]));  
	  //atof(suffix[i++].c_str())
      while(i<suffix.size()&&!isnumber(suffix[i][0])){
		  if(calcul.empty())throw 4;
		  t1=calcul.top();calcul.pop();//取出栈顶数字
		  tx1=int(t1*M);
		  switch(suffix[i][0]){
		    case'+':
				{// + 
					if(calcul.empty())throw 4;
					t2=calcul.top();calcul.pop();//取出栈顶数字
					calcul.push(t2+t1);
					break;
				}
			case'-':
				{// - 
					if(calcul.empty())throw 4;
					t2=calcul.top();calcul.pop();//取出栈顶数字
					calcul.push(t2-t1);
					break;
				}
		    case'*':
				{// * 
					if(calcul.empty())throw 4;
					t2=calcul.top();calcul.pop();//取出栈顶数字
					calcul.push(t2*t1);
					break;
				}
		    case'/':
				{// / 
					if(calcul.empty())throw 4;
					t2=calcul.top();calcul.pop();//取出栈顶数字
					if(abs(t1)<0.0000001)throw 1;
					calcul.push(t2/t1);
					break;
				}
			case'&':
				{// & 
					if(calcul.empty())throw 4;
					t2=calcul.top();calcul.pop();//取出栈顶数字
					tx2=int(t2*M);
					t2=double(tx1&tx2);
					t2/=M;
					calcul.push(t2);
					break;
				}
			case'^':
				{// ^ 
					if(calcul.empty())throw 4;
					t2=calcul.top();calcul.pop();//取出栈顶数字
					tx2=int(t2*M);
					t2=double(tx1^tx2);
					t2/=M;
					calcul.push(t2);
					break;
				}
			case'|':
				{// | 
					if(calcul.empty())throw 4;
					t2=calcul.top();calcul.pop();//取出栈顶数字
					tx2=int(t2*M);
					t2=double(tx1|tx2);
					t2/=M;
					calcul.push(t2);
					break;
				}
			case'U'://sin 
				{
					t1=sin(t1);
					calcul.push(t1);
					break;
				}
			case'V'://cos
				{
					t1=cos(t1);
					calcul.push(t1);
					break;
				}
			case'W'://tan
				{
					t1=tan(t1);
					calcul.push(t1);
					break;
				}
		    case'X'://asin
				{
					t1=asin(t1);
					calcul.push(t1);
					break;
				}
			case'Y'://acos
				{
					t1=acos(t1);
					calcul.push(t1);
					break;
				}
			case'Z'://atan
				{
					t1=atan(t1);
					calcul.push(t1);
					break;
				}
			default:{
			  throw 4;
			  break;		
			}
		  }
		  i++;
	  }
	}
	//取出最后结果
	answer = calcul.top(); calcul.pop();
}

void calculator::operate(){
	try{
      setsuffix();
	  calculate();
	}catch(int x){
	  isexception=x;
	  suffix.clear();
	  while(!operation.empty())operation.pop();
	  while(!calcul.empty())operation.pop();
	}
}
