#include <iostream>
using namespace std;

int knapsack(int value[], int weight[], int n, int capacity) {
    int dp[n + 1][capacity + 1];

    // Build DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0; // Base condition
            else if (weight[i - 1] <= w)
                dp[i][w] = max(value[i - 1] + dp[i - 1][w - weight[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][capacity]; // Final answer
}

int main() {
    int value[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int capacity = 50;
    int n = 3;

    cout << "Maximum value in 0/1 Knapsack = " << knapsack(value, weight, n, capacity);
    return 0;
}
