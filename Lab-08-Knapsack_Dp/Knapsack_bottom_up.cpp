#include <iostream>
#include <vector>
using namespace std;

int buttomup(int W,int wt[],int val[],int n)
{
    vector<vector<int>>dp(n+1,vector<int>(W+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int w=0;w<=W;w++)
        {
            if(wt[i-1]<=w)
            {
                dp[i][w] = max(val[i-1] +dp[i-1][w-wt[i-1]],dp[i-1][w]);
               
            }
            else{
                dp[i][w]=dp[i-1][w];

            }
        }
    }
    return dp[n][W];

}

int main()
{
    int val[]={12,10,20,15};
    int wt[]={2,1,3,2};
    int W=5;
    int n=4;

    cout<<"maximum value = "<<buttomup(W,wt,val,n)<<endl;
    return 0;
}