TC- O(n*2)
SC= O(n)

class Solution {
public:
    vector<int>price;
    int n;
    int maxProfit(vector<int>& prices) {
        price=prices;
        n= prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return go(0,1,dp);
        
        
    }
    int go(int i, int buy ,vector<vector<int>>&dp){
        if(i==n)return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        int profit=0;
        if(buy==1){
            profit= max(-price[i]+go(i+1,0,dp), go(i+1,1,dp));
        }
        else {
            profit= max(price[i]+go(i+1,1,dp), go(i+1,0,dp));
        }
        return dp[i][buy]= profit;
    }
};
