Recursion tc- O(2^n)    
           sc- (N)- AST

TC- O(n*2)
SC= O(n*2)+O(n)

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

Tc- O(n*2)
SC- O(n*2)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2,0));
        dp[n][1]=dp[n][0]=0;
        
        for(int i=n-1 ; i>=0 ; i--){
            for(int canbuy=0 ; canbuy<=1 ; canbuy++){
                 int profit = 0;

                if(canbuy ==1 ){
                    profit= max (-prices[i]+ dp[i+1][0],dp[i+1][1]);

                }
                else {
                    profit = max(prices[i] +dp[i+1][1], dp[i+1][0]);
                }
                 dp[i][canbuy]= profit;
            }
        }
        
        
        
        
        return dp[0][1];
    }
    
};

TC- O(n*2)
SC- O(4)=constant 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>>dp(n+1, vector<int>(2,0));
        // dp[n][1]=dp[n][0]=0;
        vector<int>ahead(2,0),cur(2,0);
        
        for(int i=n-1 ; i>=0 ; i--){
            for(int canbuy=0 ; canbuy<=1 ; canbuy++){
                 int profit = 0;

                if(canbuy ==1 ){
                    profit= max (-prices[i]+ ahead[0],ahead[1]);

                }
                else {
                    profit = max(prices[i] +ahead[1], ahead[0]);
                }
                 cur[canbuy]= profit;
            }
            ahead=cur;
        }
        
        
        
        
        return ahead[1];
    }
    
};
