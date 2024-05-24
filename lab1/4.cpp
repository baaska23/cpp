#include <iostream>
using namespace std;

float meanOdd(int arr[], int size) {
    int sum = 0;
    int count = 0;
    
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 != 0) {
            sum += arr[i];
            count++;
        }
    }
    
    
    return sum/count;
}

int main() {
    int arr[] = {10, 12, 13, 17};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    float mean = meanOdd(arr, size);
    cout << "Sondgoi toonuudin dundaj ni: " << mean << endl;
    return 0;
}
