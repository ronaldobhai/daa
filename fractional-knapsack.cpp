#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int value, weight;
};

// Comparison function for sorting (descending by value/weight)
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(Item arr[], int n, int capacity) {
    sort(arr, arr + n, compare); // Step 1: Sort items by ratio
    double totalValue = 0.0;     // Step 2: Track total profit
    int currentWeight = 0;       // Step 3: Track used capacity

    for (int i = 0; i < n; i++) {
        if (currentWeight + arr[i].weight <= capacity) {
            // Take full item
            currentWeight += arr[i].weight;
            totalValue += arr[i].value;
        } else {
            // Take fraction of item
            int remaining = capacity - currentWeight;
            totalValue += arr[i].value * ((double)remaining / arr[i].weight);
            break; // Knapsack is full
        }
    }
    return totalValue;
}

int main() {
    int n = 3;
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int capacity = 50;

    cout << "Maximum value in Knapsack = " 
         << fractionalKnapsack(arr, n, capacity);
    return 0;
}
