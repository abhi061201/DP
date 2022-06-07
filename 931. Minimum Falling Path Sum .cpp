class Solution {
public:
    int n,m;
    int minFallingPathSum(vector<vector<int>>& mat) {
        
        n= mat.size();
        m=mat[0].size();
        int ans=1e9;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int col=0 ; col<m ; col++){
            ans=min(ans,go(0,col,mat,dp));
            
        }
        return ans;
    }
    int go(int i, int j,vector<vector<int>>& mat, vector<vector<int>>&dp ){
        if(i==n-1)return mat[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        int left=1e9;
        int down=1e9;
        int right=1e9;
        if(i+1<n &&j-1>=0 )left= mat[i][j]+go(i+1,j-1,mat,dp);
        if(i+1<n) down= mat[i][j]+go(i+1,j,mat,dp);
        if(i+1<n && j+1<m)right= mat[i][j]+go(i+1,j+1,mat,dp);
        return dp[i][j]= min({left,right,down});
        
    }
    
    
};
