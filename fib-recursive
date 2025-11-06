#include <iostream>
using namespace std;

int stepCount = 0;

int fib(int n) {
    stepCount++;
    if (n == 0 || n == 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Fibonacci(" << n << ") = " << fib(n) << endl;
    cout << "Step count = " << stepCount << endl;
    return 0;
}
