#ifndef STACK
#define STACK

#include <iostream>
using namespace std;

typedef int infotype;

struct Stack{
    infotype info[20];
    int top;
};

bool isEmpty(Stack S);
bool isFull(Stack S);
void CreateStack( Stack &S);

void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack( Stack &S);

void pushAscending(Stack &S, infotype x);
void getInputStream(Stack &S);
#endif