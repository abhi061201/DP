TC- O(n*M)
SC- O(n*M)+O(n+M)

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


// BOTTOM UP
TC= O(n*M)
SC= O(n*M)
    
 #define M 1000000007
int subsequenceCounting(string &s1, string &s2, int lt, int ls) {
   
    int n=lt; 
    int m= ls; 
    vector<vector<int>>dp(n+1 ,vector<int>(m+1,0));
     for(int i=0 ; i<=n ; i++){
         dp[i][0]=1;
     }
    for(int j=1 ; j<=m ; j++){
        dp[0][j]=0;
    }
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            if(s1[i-1]==s2[j-1])dp[i][j]=(dp[i-1][j-1] %M+dp[i-1][j] %M)%M;
            else dp[i][j]= (dp[i-1][j])%M;
        }
    }
    return dp[n][m];
    
    
    
} 
