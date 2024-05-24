#include <iostream>
#include <limits>
using namespace std;

void findMaxMin(int numbers[], int n, int& maxNum, int& minNum) {
    maxNum = numbers[0];
    minNum = numbers[0];

    for (int i = 1; i < n; ++i) {
        if (numbers[i] > maxNum) {
            maxNum = numbers[i];
        }
        if (numbers[i] < minNum) {
            minNum = numbers[i];
        }
    }
}

int main() {
    int n;
    cout << "Heden too bnwe: ";
    cin >> n;

    int *numbers = new int[n];

    cout << n << " toog oruul:\n";
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    int maxNum, minNum;
    findMaxMin(numbers, n, maxNum, minNum);

    cout << "Hamgiin ih too ni : " << maxNum << endl;
    cout << "Hamgiin baga too ni : " << minNum << endl;
    return 0;
}
