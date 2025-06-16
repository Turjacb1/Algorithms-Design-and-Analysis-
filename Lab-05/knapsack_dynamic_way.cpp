#include <iostream>
#include <vector>
using namespace std;

int knapsack_dp(int W, int wt[], int val[], int n) {
    
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    
  
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (wt[i - 1] <= w) {
                
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
               
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    
    return dp[n][W];
}


int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = 3;
    
    cout << "Maximum value (DP): " << knapsack_dp(W, wt, val, n) << endl;
    return 0;
}