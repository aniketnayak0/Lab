#include <iostream>
using namespace std;

int main() {
    int num1, num2, num3;
    int maxNum, minNum;
    cout << "Enter three numbers: ";
    cin >> num1 >> num2 >> num3;
    maxNum = num1;
    if (num2 > maxNum) {
        maxNum = num2;
    }
    if (num3 > maxNum) {
        maxNum = num3;
    }

    minNum = num1;
    if (num2 < minNum) {
        minNum = num2;
    }
    if (num3 < minNum) {
        minNum = num3;
    }
    cout << "The maximum number is: " << maxNum << endl;
    cout << "The minimum number is: " << minNum << endl;

    return 0;
}
