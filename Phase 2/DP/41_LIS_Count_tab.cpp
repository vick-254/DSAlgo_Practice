#include<bits/stdc++.h>
using namespace std;

int longestSubsequence(int n, int a[])
{
   vector<vector<int>> dp(n+1,vector<int>(n+1,0));
   for(int ind=n-1; ind>=0; ind--){
       for(int prev = ind-1; prev>=-1; prev--){
              int take = dp[ind+1][prev+1];
              int nottake = INT_MIN;
              if(prev==-1 || a[prev] < a[ind]){
              nottake = 1+ dp[ind+1][ind+1];
            }
            dp[ind][prev+1] = max(take,nottake);
       }
   }
   return dp[0][0];
}