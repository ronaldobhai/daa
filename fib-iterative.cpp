#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int stepCount = 0;

    if (n == 0) {
        cout << "Fibonacci(" << n << ") = 0" << endl;
        cout << "Step count = 1" << endl;
        return 0;
    }

    if (n == 1) {
        cout << "Fibonacci(" << n << ") = 1" << endl;
        cout << "Step count = 1" << endl;
        return 0;
    }

    int f0 = 0, f1 = 1, f;
    stepCount = 2;  // for initializations

    for (int i = 2; i <= n; i++) {
        f = f0 + f1;    stepCount++;  // addition
        f0 = f1;        stepCount++;  // assignment
        f1 = f;         stepCount++;  // assignment
    }

    cout << "Fibonacci(" << n << ") = " << f << endl;
    cout << "Step count = " << stepCount << endl;

    return 0;
}
