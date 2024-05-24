#include <iostream>
using namespace std;

#define max2(a, b) ((a) > (b) ? (a) : (b))
#define max3(a, b, c) max2(max2(a, b), c)

int main() {
    int a, b, c;
    cout << "Toonuudiig oruul:  ";
    cin >> a >> b >> c;
    cout << "Hamgiin ih too ni: " << max3(a, b, c) << endl;
    return 0;
}
