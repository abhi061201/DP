// Memoisation
// TC- O(n*2*k)
// Sc= O(n*2*k)+O(n)AST


class Solution {
public:
    vector<int>prices;
    int maxProfit(int k, vector<int>& Prices) {
        prices= Prices;
        int n= prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2,vector<int>(k+1,-1)));
        return go(0,1,k,dp);
    }
    int go(int i, int canbuy, int k,vector<vector<vector<int>>>&dp){
        if(i==prices.size()||k==0)return 0;
        if(dp[i][canbuy][k]!=-1)return dp[i][canbuy][k];
        int profit=0;
        if(canbuy){
            profit= max(-prices[i] + go(i+1,0,k,dp), go(i+1,1,k,dp));
        }
        else{
            profit= max(prices[i]+ go(i+1,1,k-1,dp),go(i+1,0,k,dp));
        }
        return  dp[i][canbuy][k] =profit;
    }
};


// BOTTOM UP
// TC- O(n*2*k)
// Sc= O(n*2*k)

class Solution {
public:
    vector<int>prices;
    int maxProfit(int K, vector<int>& Prices) {
        prices= Prices;
        int n= prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2,vector<int>(K+1,0)));
        
        for(int i=n-1; i>=0 ; i--){
            for(int canbuy= 0; canbuy<=1 ; canbuy++){
                for(int k=1 ; k<=K ; k++){
                    int profit=0;
                    if(canbuy){
                        profit= max(-prices[i] + dp[i+1][0][k], dp[i+1][1][k]);
                    }
                    else{
                        profit= max(prices[i]+ dp[i+1][1][k-1],dp[i+1][0][k]);
                    }
                 dp[i][canbuy][k] =profit;
                }
            }
        }
        
        
        return dp[0][1][K];
    }
};


// SPACE OPTIMISED

// TC- O(n*2*k)
// Sc= O(2*k)

class Solution {
public:
    vector<int>prices;
    int maxProfit(int K, vector<int>& Prices) {
        prices= Prices;
        int n= prices.size();
       vector<vector<int>>after(2,vector<int>(K+1,0));
       vector<vector<int>>cur(2,vector<int>(K+1,0));
        
        for(int i=n-1; i>=0 ; i--){
            for(int canbuy= 0; canbuy<=1 ; canbuy++){
                for(int k=1 ; k<=K ; k++){
                    int profit=0;
                    if(canbuy){
                        profit= max(-prices[i] + after[0][k], after[1][k]);
                    }
                    else{
                        profit= max(prices[i]+ after[1][k-1],after[0][k]);
                    }
                 cur[canbuy][k] =profit;
                }
            }
            after=cur;
        }
        
        
        return after[1][K];
    }
};
