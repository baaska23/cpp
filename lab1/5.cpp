#include <iostream>
using namespace std;

void findDigitsAndSum(int number, int& numOfDigits, int& sumOfDigits) {
    numOfDigits = 0;
    sumOfDigits = 0;

    while (number > 0) {
        int digit = number % 10; 
        sumOfDigits += digit; 
        numOfDigits++; 
        number /= 10; 
    }
}

int main() {
    int number;
    cout << "Toog oruul: ";
    cin >> number;

    int numOfDigits, sumOfDigits;
    findDigitsAndSum(number, numOfDigits, sumOfDigits);

    cout << "Tsifriin too: " << numOfDigits << endl;
    cout << "Tsifriin niilber: " << sumOfDigits << endl;

    return 0;
}
