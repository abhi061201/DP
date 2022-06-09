MEMOISATION
// TC- (n*2)
// SC- (N*2) O(N)

class Solution {
public:
    vector<int>prices ;
    int fee;
    int maxProfit(vector<int>& Prices, int Fee) {
        fee=Fee;
        prices =Prices;
        int n= prices .size(); 
        vector<vector<int>>dp(n+1, vector<int>(2,-1));
        return go(0,1,dp);
        
    }
    int go(int i,int canbuy ,vector<vector<int>>&dp){
        if(i==prices.size() )return 0;
        if(dp[i][canbuy]!=-1)return dp[i][canbuy];
        int profit =0;
        if(canbuy ){
            profit= max(-prices[i]+go(i+1,0,dp), go(i+1,1,dp));
        }
        else {
            profit= max(prices[i]+go(i+1,1,dp)-fee,go(i+1,0,dp));
        }
        return dp[i][canbuy]= profit;
        
        
        
    }
};


BOTTOM UP

TC- O(N*2)
SC- o(N*2)
  
  class Solution {
public:
    vector<int>prices ;
    int fee;
    int maxProfit(vector<int>& Prices, int Fee) {
        fee=Fee;
        prices =Prices;
        int n= prices .size(); 
        vector<vector<int>>dp(n+1, vector<int>(2,0));
        for(int i=n-1; i>= 0 ; i--){
            for(int canbuy=0; canbuy<=1 ; canbuy++){
                int profit =0;
                if(canbuy ){
                    profit= max(-prices[i]+dp[i+1][0], dp[i+1][1]);
                }
                else {
                    profit= max(prices[i]+dp[i+1][1]-fee,dp[i+1][0]);
                }
                 dp[i][canbuy]= profit;
        
            }
            
        }
        
        return dp[0][1];
        
    }
    int go(int i,int canbuy ,vector<vector<int>>&dp){
        if(i==prices.size() )return 0;
        if(dp[i][canbuy]!=-1)return dp[i][canbuy];
        int profit =0;
        if(canbuy ){
            profit= max(-prices[i]+go(i+1,0,dp), go(i+1,1,dp));
        }
        else {
            profit= max(prices[i]+go(i+1,1,dp)-fee,go(i+1,0,dp));
        }
        return dp[i][canbuy]= profit;
        
        
        
    }
};

SPACE OPTIMISATION

TC- O(N*2)
SC- O(2) =CONSTANT

class Solution {
public:
    vector<int>prices ;
    int fee;
    int maxProfit(vector<int>& Prices, int Fee) {
        fee=Fee;
        prices =Prices;
        int n= prices .size(); 
       
        vector<int>after(2,0);
        vector<int>cur(2,0);
        for(int i=n-1; i>= 0 ; i--){
            for(int canbuy=0; canbuy<=1 ; canbuy++){
                int profit =0;
                if(canbuy ){
                    profit= max(-prices[i]+after[0], after[1]);
                }
                else {
                    profit= max(prices[i]+after[1]-fee,after[0]);
                }
                 cur[canbuy]= profit;
        
            }
            after=cur;
            
        }
        
        return after[1];
        
    }
};
