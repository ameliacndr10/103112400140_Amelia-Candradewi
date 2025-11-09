#include "stack.h"
#include <iostream>
using namespace std;

/// int main soal 1
int main()
{
    cout << "------------" << endl;
    cout << "Hello world!" << endl;
    Stack S;
    CreateStack(S);
    push(S,3);
    push(S,4);
    push(S,8);
    pop(S);
    push(S,2);
    push(S,3);
    pop(S);
    push(S,9);
    printInfo(S);

    cout<<"balik stack" << endl;
    balikStack(S);
    printInfo(S);
    cout <<"------------" << endl;
    return 0;
}

// int main soal 2
int main() {
    cout << "------------" << endl;
    cout << "Hello world!" << endl;
    Stack S;
    CreateStack(S);
    pushAscending(S,3);
    pushAscending(S,4);
    pushAscending(S,8);
    pushAscending(S,2);
    pushAscending(S,3);
    pushAscending(S,9);
    printInfo(S);
    cout<<"balik stack"<<endl;
    balikStack(S);
    printInfo(S);
    cout << "------------" << endl;
    return 0;

}

// int main soal 3
int main(){
    cout << "------------" << endl;
    cout << "Hello world!" << endl;
    Stack S;
    CreateStack(S);
    getInputStream(S);
    printInfo(S);
    cout<<"balik stack"<< endl;
    balikStack(S);
    printInfo(S);
    cout << "------------" << endl;
    return 0;
}

//catatan : jika ingin menjalan kan nomor 1, maka int main nomor 2 dan 3 di coment dulu