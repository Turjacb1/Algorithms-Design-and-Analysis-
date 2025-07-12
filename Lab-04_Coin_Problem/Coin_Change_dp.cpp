#include <bits/stdc++.h>
using namespace std;

int coinchange(vector<int>& coins, int amount) {
   
    vector<int> dp(amount + 1, INT_MAX);
    
    
    dp[0] = 0;
    
    
    for (int i = 1; i <= amount; i++) {
        
        for (int c : coins) {
            if (c <= i && dp[i - c] != INT_MAX) {
                dp[i]=min(dp[i],dp[i - c] + 1);
            }
        }
    }
    
    
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    int n, amount;
    cout << "the number of coin: ";
    cin >> n;
    
    vector<int> coins(n);
    cout << "the value of coin: ";
    for (int i =0; i<n; i++) {
        cin >> coins[i];
    }
    
    cout << "amount: ";
    cin >> amount;
    
    int result = coinchange(coins, amount);
    cout << "need minimum number of coins: " << result << endl;
    
    return 0;
}