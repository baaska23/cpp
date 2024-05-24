// заалтан хувьсагч (функцын параметер нь заалт байна) хоёр хувьсагчийн утгыг солих хэрэглэгчийн функц бич.
#include <iostream>
using namespace std;

void swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

int main(){
    int a = 10, b = 20;
    cout << "Before a = " << a << ", b = " << b << endl;
    swap(a, b);
    cout << "After a = " << a << ", b = " << b << endl;
}

