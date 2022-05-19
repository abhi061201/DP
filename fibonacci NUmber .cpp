Method 1:

Tc= O(2^n)
SC= O(1)

CODE:
class Solution {
public:
    int fib(int n) {
        
        if(n<2)return n;
        return fib(n-1)+fib(n-2);
        
    }
};

Method 2:   // memoisation

TC O(n)
SC O(n)
Code:
class Solution {
public:
    
    int fib(int n) {
        vector<int>dp(n+1,-1);
        return f(n,dp);
    }
    int f(int n , vector<int>&dp){
        if(dp[n]!=-1)return dp[n];
        if(n<2)return n;
        return dp[n]=f(n-1,dp)+f(n-2,dp);
    }
};



Method 3:  Bottom up
TC   O(N)
Sc   O(N)
Code:

class Solution {
public:
    
    int fib(int n) {
        if(n<1)return n;
        vector<int>dp(n+1, -1);
        dp[0]=0;
        dp[1]=1;
        for(int i=2 ; i<=n ; i++){
            dp[i]= dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
  
};

method 4

TC  o(N)
SC  O(2)= constant
Code:
class Solution {
public:
    
    int fib(int n) {
        if(n<2)return n;
        int f=0, s=1,ans=0;
        for(int i=2 ; i<=n ; i++){
            ans= s+f;
            f=s;
            s=ans;
        }
        return ans;
        
    }
  
};

