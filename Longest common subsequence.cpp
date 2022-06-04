// bottom up
Tc- O(n*M)
SC- O(n*M)

class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n= s1.size(); 
        int m = s2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0) );
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=m ; j++){
                if(s1[i-1]==s2[j-1])dp[i][j]= 1+dp[i-1][j-1];
                else dp[i][j]= max(dp[i][j-1], dp[i-1][j]);
            }
            
        }
        return dp[n][m];
    }
};



Top down

TC- O(n*M)
SC- O(n*m) + stack(O(n+M))
  // stack space when taken alternate elemnts of string at max
  
  
  
  class Solution {
public:
    string s1, s2;
    int longestCommonSubsequence(string se1, string se2) {
        s1=se1;
        s2=se2;
        int n= s1.length();
        int m= s2.length();
        int ans=0;
        vector<vector<int>>dp(n, vector<int>(m,-1));
        ans= go(n-1,m-1,dp);
        return ans;
    }
    int go (int i,int j,vector<vector<int>>&dp){
        if(i<0 || j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j])return dp[i][j]=1+go(i-1, j-1,dp);
        return dp[i][j]=max(go(i-1,j,dp), go(i,j-1,dp));
    }
};
