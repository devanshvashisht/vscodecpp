#include <iostream>
#include <vector>

using namespace std;

// Function to solve 0/1 knapsack problem
int knapsack(int W, const vector<int>& weights, const vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int W; // Knapsack capacity
    cout << "Enter knapsack capacity: ";
    cin >> W;

    int n; // Number of items
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> weights(n); // Array to store weights of items
    vector<int> values(n);  // Array to store values of items

    cout << "Enter weights of items:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    cout << "Enter values of items:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    int max_value = knapsack(W, weights, values, n);
    cout << "Maximum value that can be obtained: " << max_value << endl;

    return 0;
}
