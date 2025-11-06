#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    char id;        // Job ID (like A, B, C)
    int deadline;   // Deadline of job
    int profit;     // Profit if job is completed before or on deadline
};

// Compare jobs based on profit (descending)
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    Job jobs[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter Job ID, Deadline, Profit: ";
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    // Step 1: Sort by descending profit
    sort(jobs, jobs + n, compare);

    // Step 2: Find max deadline
    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;

    // Step 3: Create slot array
    char result[maxDeadline];
    bool slot[maxDeadline];

    for (int i = 0; i < maxDeadline; i++)
        slot[i] = false;

    int totalProfit = 0;

    // Step 4: Schedule jobs
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (!slot[j]) {  // If slot is free
                slot[j] = true;
                result[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    // Step 5: Display result
    cout << "\nJob Sequence: ";
    for (int i = 0; i < maxDeadline; i++)
        if (slot[i])
            cout << result[i] << " ";

    cout << "\nTotal Profit = " << totalProfit << endl;

    return 0;
}
