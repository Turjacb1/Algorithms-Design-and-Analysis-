#include<bits/stdc++.h>
using namespace std;


int fib_memo(int n,vector<int>memo)
{
    if(n<=1)
    {
        return n;
    }
    if(memo[n]!=-1)
    {
        return memo[n];
    }

    memo[n]=fib_memo(n-1,memo)+fib_memo(n-2,memo);
    return memo[n];

}

int fib(int n)
{
    vector<int>memo(n+1,-1);
    return fib_memo(n,memo);
}

int main()
{
    int n;
    cin>>n;
    cout<<n<<" "<<"number of fibo"<<" "<<fib(n)<<endl;
}