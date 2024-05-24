#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
};
int main(){
    // int a = 12312;
    // int &a_ref=a;
    // cout<<&a<<"\n";
    // cout<<&a_ref<<"\n";
    // cout<<a<<endl;
    // cout<<a_ref<<endl;
    int a = 100;
    int b = 200;
    swap(a, b);
    cout<<"A is: "<<a<<endl;
    cout<<"B is: "<<b<<endl;
    return 0;
}



