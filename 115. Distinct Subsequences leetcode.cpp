class Solution {
public:
    string s1,s2;
    int numDistinct(string s, string t) {
        s1=s;
        s2=t;
        int n= s.length();
        int m= t.length();
        vector<vector<int>>dp(n, vector<int>(m,-1));
        return go(n-1,m-1,dp);
    }
    int go(int i,int j, vector<vector<int>>&dp){
        if(j<0)return 1;
        if(i<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j])return dp[i][j]= go(i-1,j-1,dp)+go(i-1,j,dp);
        else return  dp[i][j]=go(i-1,j,dp);
    }
};
