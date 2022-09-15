#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <iostream>
#include <iomanip>
//#include <cstdlib>
//#include <stdio.h>
#include <stdlib.h>
//#include <ctype.h>
#include<cmath>
#include <assert.h>
//#include<string>
using namespace std;
template<class StackElemType>
class Stack
{private: struct Node;
          typedef Node* Link;
          struct Node{StackElemType elem;
                      Link next;};
          Link head;

public: Stack();
        bool push(const StackElemType & e);
        StackElemType pop();
        StackElemType top();
        bool isEmpty();
};

template<class StackElemType>
Stack<StackElemType>::Stack()
{head=NULL;}

template<class StackElemType>
bool Stack<StackElemType>::push(const StackElemType & e)
{Link AddedNode=new Node;
if(AddedNode==NULL){return false;}
AddedNode->elem=e;
AddedNode->next=head;
head=AddedNode;
//cout<<head->elem;
//if(head->next !=NULL){cout<<head->next->elem;}
return true;
}

template<class StackElemType>
StackElemType Stack<StackElemType>::pop()
{assert(head!=NULL);
StackElemType data=head->elem;
Link temp=head;
head=head->next;
delete temp;
return data;
}

template<class StackElemType>
StackElemType Stack<StackElemType>::top()
{assert(head!=NULL);
StackElemType data=head->elem;
return data;
}

template<class StackElemType>
bool Stack<StackElemType>::isEmpty()
{return bool(head==NULL);
}

#endif // STACK_H_INCLUDED
