#include <iostream>
using namespace std;

void tukar(int &x, int &y, int &z) {
    int temp;
    temp = x;
    x = y;
    y = z;
    z = temp;
}
int main() {
    int a = 20, b = 30, c = 40;
    int& ref = a;

    cout << "Value of a : " << a << endl;
    cout << "Addres of : " << &a << endl;
    cout << "Value stured in ptrs (address of a): " << ref << endl;
    cout << "Value pointed to by ptr : " << &ref << endl;


    ref = 50;
    cout << "\nSetelah ref = 50;" << endl;
    cout << "Nilai a:" << a << endl;
    cout << "Nilai ref: " << ref << endl;

    tukar(a, b, c);
    cout << "After swapping, value of a = " <<a << ", b = " << b << " dan c = " << c << endl;
    return 0;
}