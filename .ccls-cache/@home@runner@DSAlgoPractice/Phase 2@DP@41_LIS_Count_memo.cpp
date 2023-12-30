#include<bits/stdc++.h>
using namespace std;

int solve(int ind, int prev, int a[],int n, vector<vector<int>> &dp){
    if(ind==n) return 0;
    if(dp[ind][prev+1] != -1) return dp[ind][prev+1];
    int take = solve(ind+1,prev,a,n,dp);
    int nottake = INT_MIN;
    if(prev==-1 || a[prev] < a[ind]){
        nottake = 1+ solve(ind+1,ind,a,n,dp);
    }
    return dp[ind][prev+1] = max(take,nottake);
}

int longestSubsequence(int n, int a[])
{
   vector<vector<int>> dp(n,vector<int>(n+1,-1));
   return solve(0,-1,a,n,dp);
}