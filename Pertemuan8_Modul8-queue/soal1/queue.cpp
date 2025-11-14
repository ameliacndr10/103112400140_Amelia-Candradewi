#include "queue.h"
using namespace std;

void CreateQueue(Queue &Q){
    Q.head = -1;
    Q.tail = -1;
}
bool isEmptyQueue(Queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    }else{
        return false;
    }
}
bool isFullQueue(Queue Q){
    if(Q.tail == 5 -1){
        return true;
    }else{
        return false;
    }
}
void enqueue(Queue &Q, infotype x){
    if(isFullQueue(Q)== true){
        cout << "Queue sudah penuh!" << endl;
    }else{
        if (isEmptyQueue(Q) == true){
            Q.head = Q.tail = 0;
        }else{
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue (Queue &Q){
    if(isEmptyQueue(Q) == true){
        cout << "Empty queue" << endl;
    }else{
        for(int i = 0; i < Q.tail; i++){
            Q.info[i] = Q.info[i+1];
        }
        Q.tail--;
        if(Q.tail < 0){
            Q.head = -1;
            Q.tail = -1;
        }
    }
}
void printInfo(Queue Q){
    cout << Q.head << "-" << Q.tail << "\t | ";

    if(isEmptyQueue(Q) == true){
        cout << "Empty queue" << endl;
    }else{
        for (int i = Q.head; i <= Q.tail; i++){
            cout << Q.info[i] << " ";
        }
        cout << endl;
    }
}