class Solution {
public:
    string s1,s2;
    int minDistance(string S1, string S2) {
        s1=S1;
        s2=S2;
        
        int n= s1.size();
        int m= s2.size();
        if(m==0)return n;
        if(n==0)return m;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return go(n-1,m-1,dp);
        
    }
    
    int go(int i,int j, vector<vector<int>>&dp){
        if(i<0)return j+1;
        if(j<0)return i+1;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j])return dp[i][j]=go(i-1,j-1,dp);
        
        //insert
        int in= 1+ go(i-1,j,dp);
        
        // del
        int de= 1+go(i,j-1,dp);
        
        // replace
        int rep= 1+go(i-1,j-1,dp);
        
        return dp[i][j]= min({de,in,rep});
    }
};
