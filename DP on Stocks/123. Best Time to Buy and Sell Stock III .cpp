/*
TC---> O(n*2*3);
SC---> O(n*2*3);
*/

class Solution {
public:
    vector<int>prices;
    int maxProfit(vector<int>&Prices) {
        prices=Prices;
        int n= prices.size();
        
        int transaction=2;
        // Since 3 parameters are changing therefore 3d dp
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return go(0, 1, transaction,dp);
        
        
    }
    
    // complete Transaction
        // BUY----> SELL
    int go(int i, int canbuy, int transaction,vector<vector<vector<int>>>&dp){
        if(i==prices.size() || transaction==0 ){
            return 0;
        }
        
        
        if(dp[i][canbuy][transaction]!=-1)return dp[i][canbuy][transaction];
        int profit= 0;
        // on buying a stock no transaction complete 
        if(canbuy==1){
            profit= max(-prices[i]+ go(i+1, 0, transaction,dp), go(i+1, 1, transaction,dp));
        }
        // on selling a stock  transaction complete therefore dectresed buy one . 
        else {
            
            // here in first case we sell stock, in second case we dosent sell stock therefore no decrement
            profit= max(prices[i]+ go(i+1, 1, transaction-1,dp), go(i+1, 0, transaction,dp));
        }
        return  dp[i][canbuy][transaction] =profit;
    }
};
