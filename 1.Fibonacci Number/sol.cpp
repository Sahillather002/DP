// top down
#include<bits/stdc++.h>
using namespace std;

int fib(int n,vector<int>& dp){
        if(n<=1)return n;
        if(dp[n]!=-1)return dp[n];
        dp[n]=fib(n-1,dp)+fib(n-2,dp);
        return dp[n];
}
int main()
{
        int n;
        cin>>n;
        vector<int> dp(n+1,-1);
        cout<<fib(n,dp)<<endl;
        return 0;
}


// leetcode one

class Solution {
public:
    int solve(int n,vector<int>& dp){
        if(n==1 || n==0){
            return 1;
        }
        if(dp[n]!=-1)return dp[n];
        dp[n]=solve(n-1,dp)+solve(n-2,dp);
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};
