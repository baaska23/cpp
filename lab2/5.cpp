//хаяган хувьсагч ашиглан (функцын параметер нь хаяган хувьсагч байна) хоёр хувьсагчийн утгыг солих хэрэглэгчийн функц бич.
#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int a = 10, b = 20;
    cout << "Before a = " << a << ", b = " << b << endl;
    swap(&a, &b);
    cout << "After a = " << a << ", b = " << b << endl;
}

