/*
TC---> O(n*2*3);
SC---> O(n*2*3) + O(n)AST;
*/

  // complete Transaction
        // BUY----> SELL

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

/*
TC---> O(n*2*3);
SC---> O(n*2*3) ;
*/

class Solution {
public:
    vector<int>prices;
    int maxProfit(vector<int>&Prices) {
        prices=Prices;
        int n= prices.size();
        
        int transaction=2;
        // Since 3 parameters are changing therefore 3d dp
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        
        // Base condition no need as already initialised with zero
        dp[n][0][0]=0;
        dp[n][0][1]=0;
        dp[n][1][0]=0;
        dp[n][1][1]=0;
            
            
        for(int i=n-1 ; i>=0 ; i--){
            for(int canbuy=0 ; canbuy<=1 ; canbuy++){
               // transaction =0 no need as base case for every transaction=0 the value should be zero
                for(transaction=1 ; transaction<=2 ; transaction++){
                     
                    int profit= 0;

                    if(canbuy==1){
                        profit= max(-prices[i]+ dp[i+1][0][transaction],dp[i+1][1][transaction]);
                    }
                    // on selling a stock  transaction complete therefore dectresed buy one . 
                    else {

                        // here in first case we sell stock, in second case we dosent sell stock therefore no decrement
                        profit= max(prices[i]+ dp[i+1][1][transaction-1], dp[i+1][0][transaction]);
                    }
                     dp[i][canbuy][transaction] =profit;
                }
            }
        }
        
        
        return dp[0][1][2];
        
        
    }
    
  
};
// Space optimised

/*
TC---> O(n*2*3);
SC---> O(2*3) = constant;
*/

class Solution {
public:
    vector<int>prices;
    int maxProfit(vector<int>&Prices) {
        prices=Prices;
        int n= prices.size();
        
        int transaction=2;
        // Since 3 parameters are changing therefore 3d dp
       vector<vector<int>>after(2,vector<int>(3,0));
        vector<vector<int>>cur(2,vector<int>(3,0));
        
        
      
            
            
        for(int i=n-1 ; i>=0 ; i--){
            for(int canbuy=0 ; canbuy<=1 ; canbuy++){
                for(transaction=1 ; transaction<=2 ; transaction++){
                     
                    int profit= 0;

                    if(canbuy==1){
                        profit= max(-prices[i]+ after[0][transaction],after[1][transaction]);
                    }
                    // on selling a stock  transaction complete therefore dectresed buy one . 
                    else {

                        // here in first case we sell stock, in second case we dosent sell stock therefore no decrement
                        profit= max(prices[i]+ after[1][transaction-1], after[0][transaction]);
                    }
                     cur[canbuy][transaction] =profit;
                }
            }
            after=cur;
        }
        
        
        return after[1][2];
        
        
    }
    
    // complete Transaction
        // BUY----> SELL
};
