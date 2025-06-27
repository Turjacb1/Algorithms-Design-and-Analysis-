#include <bits/stdc++.h>
using namespace std;

int coinCollect(vector<vector<int>>& coin) {
    int n = coin.size(); 
    int m = coin[0].size(); 
    
    if (n == 0 || m == 0) return 0; 

    
    vector<vector<int>> dp(n, vector<int>(m, 0));
    
    
    dp[0][0] = coin[0][0];
    
   
    for (int j = 1; j < m; j++) {
        dp[0][j] = dp[0][j-1] + coin[0][j];
    }
    
    
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i-1][0] + coin[i][0];
    }
    
    
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + coin[i][j];
        }
    }
    
    return dp[n-1][m-1]; 
}

int main() {
    int n, m;
    cout << "row and column n and m: ";
    cin >> n >> m;

    vector<vector<int>> coin(n, vector<int>(m));
    cout << "the value of coin in table " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> coin[i][j];
        }
    }

    int result = coinCollect(coin);
    cout << "highest coin value: " << result << endl;

    return 0;
}