#include "stack.h"
#include <iostream>
using namespace std;

bool isEmpty(Stack S){
    return S.top == -1;
}

bool isFull(Stack S){
    return S.top == 19;
}

void CreateStack(Stack &S){
    S.top = -1;
}

void push(Stack &S, infotype x){
    if (isFull(S)){
        cout << "Stack penuh!" << endl;
    }else{
        S.top++;
        S.info[S.top] = x;
    }
}
infotype pop(Stack &S){
    if (isEmpty(S)){
        cout << "Stack kosong!" << endl;
    }else{
        int val = S.info[S.top];
        S.top--;
        return val;
    }
}
void printInfo(Stack S){
    cout << "[TOP]";
    
    if(isEmpty(S)){
        cout << "Stack kosong!" << endl;
    }else{
        for (int i = S.top; i >= 0; --i){
            cout << S.info[i] << " ";
        }
    }
    cout << endl;
}

void balikStack( Stack &S){
    if (isEmpty(S)){
        return;
    } 

    Stack temp1;
    CreateStack(temp1);
    Stack temp2;
    CreateStack(temp2);

    // S ke temp1
    while (!isEmpty(S)) {
        push(temp1, pop(S));
        // S = 9 2 4 3
        // temp1 = 3 4 2 9
    }
    // temp1 ke temp2
    while (!isEmpty(temp1)) {
        push(temp2, pop(temp1));
        // temp1 = 3 4 2 9
        // temp2 = 9 2 4 3
    }
    // temp2 ke S (Stack S sekarang terbalik)
    while (!isEmpty(temp2)) {
        push(S, pop(temp2));
        // temp2 = 9 2 4 3
        // S= 3 4 2 9
    }
}

void pushAscending(Stack &S, infotype x){
    if(isFull(S)){
        cout << "Stack penuh!" << endl;
    }

    Stack tempstack;
    CreateStack(tempstack);
    if (!isEmpty(S)){
        while(!isEmpty(S) && S.info[S.top] > x){
            infotype tempVal = pop(S);
            push(tempstack, tempVal);
        }
    }
    push(S, x);

    while (!isEmpty(tempstack)){
        infotype tempVal = pop(tempstack);
        push(S, tempVal);
    }
}

void getInputStream(Stack &S){
    int input ;

    while((input = cin.get()) != '\n') {
        if ((input >= '0' && input <= '9')){
            infotype data = input -'0';
            push(S, data);
        }
    }
}
