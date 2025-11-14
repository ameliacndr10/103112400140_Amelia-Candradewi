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
    if((Q.tail + 1) % MAX == Q.head) {
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
            Q.tail = (Q.tail +1) % MAX;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue (Queue &Q){
    if(isEmptyQueue(Q) == true){
        cout << "Empty queue" << endl;
    }else{
        if(Q.head == Q.tail){
            Q.head = -1;
            Q.tail = -1;
        }else{
            Q.head = (Q.head +1) % MAX;
        }
    }
}
void printInfo(Queue Q){
    cout << Q.head << "-" << Q.tail << "\t | ";

    if (isEmptyQueue (Q) == true){
        cout << "Empty kosong" << endl;
    }else{
        int i = Q.head;
        int count = 1;
        while(true){
            cout << Q.info[i] << " ";
            if (i == Q.tail){
                break;
            }
            i = (i + 1) % MAX;
            count++;
        }
        cout << endl;
    }
}