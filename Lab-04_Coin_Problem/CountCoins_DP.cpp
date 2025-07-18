#include <vector>
#include <iostream>
using namespace std;



class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        
        dp[0] = 1;
        
      
        for (int coin :coins) {
        
            for (int i =coin; i<=amount; i++) {
                dp[i] += dp[i - coin];
            }
        }
        
        return dp[amount];
    }
};

int main() {
    Solution sol;
    vector<int>coins = {1, 2, 5};
    int amount = 5;
    cout << "number of ways: " << sol.change(amount,coins) <<endl;
    return 0;
}