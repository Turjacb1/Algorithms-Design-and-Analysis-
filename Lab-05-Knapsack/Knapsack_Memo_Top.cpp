
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int topdown(int W,int n,vector<int>&wt,vector<int>&val,vector<vector<int>>&dp)
{
    if(n==0 || W==0)
    {
        return 0;
    }

    if(dp[n][W]!=-1)
    {
        return dp[n][W];
    }

    if(wt[n-1]<=W)
    {
        int include=val[n-1]+topdown(W-wt[n-1],n-1,wt,val,dp);
        int exclude=topdown(W,n-1,wt,val,dp);
        return dp[n][W]=max(include,exclude);

    }
    else{
        return dp[n][W]=topdown(W,n-1,wt,val,dp);
    }

   

}

int main()
{
    int n=4;
    int W=8;
    vector< int> wt={2,3,4,5};
    vector<int> val={3,4,5,6};

    vector<vector<int>> dp(n+1,vector<int>(W+1,-1));

    cout<<"maximum value = "<<topdown(W,n,wt,val,dp)<<endl;
}