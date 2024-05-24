#include <iostream>
using namespace std;

int main(){
    char *p1;
    int *p2;
    double *p3;
    cout<<sizeof(p1)<<endl<<sizeof(p2)<<endl<<sizeof(p3)<<endl; 
    //хэд хэд гэсэн утга хэвлэж байна вэ?  Яагаад?
    
    // Хувьсагчдын төрлөөс үл хамааран бүгд хаяган хувьсагч  тул 8 гэсэн утгыг буцааж байна.
    // 64-bit processor дээр хаяган хувьсагч 8 bytes санах ой эзэлдэг байдаг бол 
    // 32-bit processor дээр 4 bytes санах ой эзэлдэг
}

