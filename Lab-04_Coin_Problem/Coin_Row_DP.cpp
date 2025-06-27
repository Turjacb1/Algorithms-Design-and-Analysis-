#include <bits/stdc++.h>
using namespace std;

int coinRow(vector<int>& coins) {
    int n = coins.size();
    if (n == 0) return 0; 

    
    vector<int> dp(n + 1);
    
    
    dp[0] = 0; 
    dp[1] = coins[0]; 

    
    for (int i = 2; i <= n; i++) {
        dp[i] = max(dp[i-1], dp[i-2] + coins[i-1]);
    }

    return dp[n]; 
}

int main() {
    int n;
    cout << "coin number: ";
    cin >> n;

    vector<int> coins(n);
    cout << "the value of coin: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int result = coinRow(coins);
    cout << "highest value: " << result << endl;

    return 0;
}