#include <iostream>
#include <iomanip>
//#include <cstdlib>
//#include <stdio.h>
#include <stdlib.h>
//#include <ctype.h>
#include<cmath>
#include <assert.h>
#include"Stack.h"
#include<string>
using namespace std;

Stack<char> operat;
Stack<float> operand;
void readexp(int argc,char*argv[]);
int Fact (int op);
bool ifdigit(string arg1);
bool ifbrack(string arg1);
bool ifopbrack(string arg1);
bool ifclbrack(string arg1);
bool ifop(string arg1);
bool ifFact(string arg1);
bool Min=true;bool ok1=true;bool finish=false;bool ok2=true;
float add(float op1,float op2);
float sub(float op1,float op2);
int main(int argc,char* argv[])
{int brack=0;int brack2=0;
 if(argc==1){cout<<fixed << setprecision(2)<<0.0;}
  else{//check all elements if valid or not
        for(int k=1;k<=argc-1;k++)
        {if(!(ifbrack(argv[k])||ifop(argv[k])|| ifFact(argv[k])||ifdigit(argv[k])|| argv[k]=="/n")){ok1=false; break;}}
        //check no. of brackets
        for(int k=1;k<=argc-1;k++)
        {if(ifopbrack(argv[k])){brack++;}
         if(ifclbrack(argv[k])){brack2++;}}
        if(brack!=brack2){ok1=false;}
         //check  the starting is invalid      /
        if(!(ifopbrack(argv[1])|| ifdigit(argv[1]))){ok1=false;}
         //check each two successive elements
         for(int k=1;k<=argc-2;k++)
         {if(ifopbrack(argv[k]) && !(ifopbrack(argv[k+1])|| ifdigit(argv[k+1]))){ok1=false;break;}
          if(ifclbrack(argv[k]) && (ifopbrack(argv[k+1])|| ifdigit(argv[k+1]))){ok1=false;break;}
          if(ifdigit(argv[k])&& (ifopbrack(argv[k+1])|| ifdigit(argv[k+1]))){ok1=false;break;}
          if(ifop(argv[k]) && (ifop(argv[k+1])|| ifFact(argv[k+1]) || ifclbrack(argv[k+1]))){ok1=false;break;}
          if(ifFact(argv[k]) && (ifdigit(argv[k+1]) || ifopbrack(argv[k+1]))){ok1=false;break;}
         }
         //check operator syntax

         if(ok1==true){readexp(argc,argv);}
         else{cout<<"Invalid Expression";}
      }
return 0;
}


void readexp(int argc,char*argv[])
{float operand1=0;float operand2=0;float operand3=0;char oper;float result=0;char top;float j=0;int prior_top=0;int prior=0;string arg;
    for(int i=1;i<=argc-1;i++)
    {arg=argv[i];prior=prior_top=0;
     if(ifopbrack(argv[i])){operat.push('(');}
     else if(ifdigit(argv[i])){operand.push(atof(argv[i]));}
     else if(ifop(argv[i])||ifFact(argv[i]))
        {if(!operat.isEmpty()){ if(argv[i][0]=='!'){prior=4;}
                                else if(argv[i][0]=='^'){prior=3;}
                                else if(argv[i][0]=='/' || argv[i][0]=='x' || argv[i][0]=='X' || argv[i][0]=='%'){prior=2;}
                                else if(argv[i][0]=='+' || argv[i][0]=='-'){prior=1;}
                               while(!operat.isEmpty())
                                {top=operat.top();
                                if(top=='(' || top==')'){prior_top=0;}
                               else if(top=='!'){prior_top=4;}
                               else if(top=='^'){prior_top=3;}
                               else if(top=='/' || top=='x' || top=='X' || top=='%'){prior_top=2;}
                               else if(top=='+' || top=='-'){prior_top=1;}
        // cout<<prior<<" "<<prior_top<<" ";
                              if(prior_top>=prior){oper=operat.pop();//cout<<oper;
                              if(prior_top==4){if(!operand.isEmpty()){operand3=operand.pop();}
                                                 else{cout<<"Invalid Expression";ok2=false;break;}}
                              else {if(!operand.isEmpty()){operand2=operand.pop();}
                                      else{cout<<"Invalid Expression";ok2=false;break;}
                                     if(!operand.isEmpty()){operand1=operand.pop();}
                                      else{cout<<"Invalid Expression";ok2=false;break;}}

                            if(oper=='!'){if(operand3>=0){result=Fact(int(operand3));}
                                          else{cout<<"Invalid Expression";ok2=false;break;}}
                            else if(oper=='^'){result=pow(operand1,operand2);}
                            else if(oper=='x' || oper=='X'){result=operand1*operand2;}
                            else if(oper=='/'){if(operand2!=0){result=operand1/operand2;}
                                               else{cout<<"Invalid Expression";ok2=false;break;}}
                            else if(oper=='%'){result=int(operand1)%int(operand2);}
                            else if(oper=='+'){result=add(operand1,operand2);}
                            else if(oper=='-'){result=sub(operand1,operand2);}
                            operand.push(result);}
                            else{break;}}
                             operat.push(argv[i][0]);}
         else{operat.push(argv[i][0]);}
        }
     else if(argv[i][0]==')'){  oper=operat.pop();
                                while(oper!='(')
                               {if(oper=='!'){if(!operand.isEmpty()){operand3=operand.pop();}
                                                 else{cout<<"Invalid Expression";ok2=false;break;}}
                                else{if(!operand.isEmpty()){operand2=operand.pop();}
                                      else{cout<<"Invalid Expression";ok2=false;break;}
                                     if(!operand.isEmpty()){operand1=operand.pop();}
                                      else{cout<<"Invalid Expression";ok2=false;break;}}

                                if(oper=='!'){if(operand3>=0){result=Fact(int(operand3));}
                                               else{cout<<"Invalid Expression";ok2=false;break;}}
                                else if(oper=='^'){result=pow(operand1,operand2);}
                                else if(oper=='x' || oper=='X'){result=operand1*operand2;}
                                else if(oper=='/'){if(operand2!=0){result=operand1/operand2;}
                                               else{cout<<"Invalid Expression";ok2=false;break;}}
                                else if(oper=='%'){result=int(operand1)%int(operand2);}
                                else if(oper=='+'){result=add(operand1,operand2);}
                                else if(oper=='-'){result=sub(operand1,operand2);}
                                operand.push(result);
                                oper=operat.pop();}
                             }
       else if(arg=="/n"){if(operat.isEmpty()){while(!operand.isEmpty())
                                                  {cout<<fixed << setprecision(2)<<operand.pop();}}
                          else{while(!operat.isEmpty()&&operat.top()!='(')
                                  {oper=operat.pop();
                                   if(oper=='!'){if(!operand.isEmpty()){operand3=operand.pop();}
                                                 else{cout<<"Invalid Expression";ok2=false;break;}}
                                   else{if(!operand.isEmpty()){operand2=operand.pop();}
                                        else{cout<<"Invalid Expression";ok2=false;break;}
                                        if(!operand.isEmpty()){operand1=operand.pop();}
                                        else{cout<<"Invalid Expression";ok2=false;break;}}

                                if(oper=='!'){if(operand3>=0){result=Fact(int(operand3));}
                                               else{cout<<"Invalid Expression";ok2=false;break;}}
                                else if(oper=='^'){result=pow(operand1,operand2);}
                                else if(oper=='x' || oper=='X'){result=operand1*operand2;}
                                else if(oper=='/'){if(operand2!=0){result=operand1/operand2;}
                                               else{cout<<"Invalid Expression";ok2=false;break;}}
                                else if(oper=='%'){result=int(operand1)%int(operand2);}
                                else if(oper=='+'){result=add(operand1,operand2);}
                                else if(oper=='-'){result=sub(operand1,operand2);}
                                operand.push(result);}
                                if(ok2==true)
                                  {cout<<fixed << setprecision(2)<<result;}
                                finish=true;
                               }
                         }
       else{cout<<"Invalid Expression";ok2=false;break;}
    }


    if(finish==false){if(operat.isEmpty()){while(!operand.isEmpty())
                                                  {cout<<fixed << setprecision(2)<<operand.pop();}
                                               }
                            else{
                                while(!operat.isEmpty()&&operat.top()!='(')
                               {oper=operat.pop();//cout<<oper;
                                if(oper=='!'){if(!operand.isEmpty()){operand3=operand.pop();}
                                               else{cout<<"Invalid Expression";ok2=false;break;}}
                                else{if(!operand.isEmpty()){operand2=operand.pop();}
                                      else{cout<<"Invalid Expression";ok2=false;break;}
                                     if(!operand.isEmpty()){operand1=operand.pop();}
                                      else{cout<<"Invalid Expression";ok2=false;break;}}
                                if(oper=='!'){if(operand3>=0){result=Fact(int(operand3));}
                                               else{cout<<"Invalid Expression";ok2=false;break;}}
                                else if(oper=='^'){result=pow(operand1,operand2);}
                                else if(oper=='x' || oper=='X'){result=operand1*operand2;}
                                else if(oper=='/'){if(operand2!=0){result=operand1/operand2;}
                                               else{cout<<"Invalid Expression";ok2=false;break;}}
                                else if(oper=='%'){result=int(operand1)%int(operand2);}
                                else if(oper=='+'){result=add(operand1,operand2);}
                                else if(oper=='-'){result=sub(operand1,operand2);}
                                operand.push(result);}
                                if(ok2==true)
                                  {cout<<fixed << setprecision(2)<<result;}
                                finish=true;
                                }
                     }





}


int Fact (int op)
{
if (op == 1 || op==0)
return 1;
return (op * Fact(op-1));
}

float add(float op1,float op2)
{
    if(!operat.isEmpty()&& operat.top()=='-'){return -(-op1+op2);}
    else{return op1+op2;}
}

float sub(float op1,float op2)
{if(!operat.isEmpty()&& operat.top()=='-'){return -(-op1-op2);}
   else{return op1-op2;}
}

bool ifdigit(string arg1)
{int h=0;
 if((arg1[0]=='-' || arg1[0]=='+' || arg1[0]=='.') && !isprint(arg1[1])){return false;}
 if(arg1[0]=='-' || arg1[0]=='+')
   {int a=0;h++;
    while(arg1[h]!='\0')
     {if(isdigit(arg1[h])){h++;}
      else if(arg1[h]=='.'){a++;h++;}
      else{return false;}}
    if(a>1){return false;}
      else{return true;}
    }
 else if(arg1[0]=='.')
    {h++;
     while(arg1[h]!='\0')
     {if (isdigit(arg1[h])){h++;}
      else{return false;}}
     return true;
    }
 else{int a=0;
    while(arg1[h]!='\0')
     {if (isdigit(arg1[h])){h++;}
      else if(arg1[h]=='.'){a++;h++;}
      else{return false;}}
    if(a>1){return false;}
      else{return true;}}
}



bool ifbrack(string arg1)
{if(arg1[0]=='(' || arg1[0]==')')
   {if(isprint(arg1[1])){return false;}
     else{return true;}}
 else{return false;}
}

bool ifop(string arg1)
{if(arg1[0]=='x' || arg1[0]=='X' || arg1[0]=='/' || arg1[0]=='^' || arg1[0]=='+' || arg1[0]=='-' || arg1[0]=='%')
   {if(isprint(arg1[1])){return false;}
     else{return true;}}
 else{return false;}
}

bool ifFact(string arg1)
{if(arg1[0]=='!')
   {if(isprint(arg1[1])){return false;}
     else{return true;}}
 else{return false;}

}

bool ifopbrack(string arg1)
{if(arg1[0]=='(')
   {if(isprint(arg1[1])){return false;}
     else{return true;}}
 else{return false;}
}

bool ifclbrack(string arg1)
{if(arg1[0]==')')
   {if(isprint(arg1[1])){return false;}
     else{return true;}}
 else{return false;}
}
