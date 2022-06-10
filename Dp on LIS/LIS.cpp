MEMOISATION

TC- O(N*N+1)
sc= O(N*N+1)
  
  
  class Solution {
public:
    vector<int>nums;
    int lengthOfLIS(vector<int>& Nums) {
        nums= Nums;
        int n=nums .size();
        vector<vector<int>>dp(n, vector<int>(n+1,-1));
        return go(0,-1,dp);
        
    }
    int go(int i,int prev,vector<vector<int>>&dp){
        
        if(i==nums.size())return 0;
        if( dp[i][prev+1]!=-1)return dp[i][prev+1];
        int take=0,n_take=0;
        n_take= go(i+1, prev,dp);
        if(prev==-1 || nums[i]>nums[prev]){
            take =1+go(i+1, i,dp);
        }
        return dp[i][prev+1]= max(take , n_take);
        
    }
};
