class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>>dp(n, vector<int>(m,-1));
        return go(0,0,n,m,grid,dp);
    }
    int go(int i,int j,int n,int m,vector<vector<int>>& grid,  vector<vector<int>>&dp){
        if(i==n-1 && j== m-1){
            return grid[n-1][m-1];
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int down=1e9;
        int right= 1e9;
        if(i<n && j+1<m)down=grid[i][j]+go(i,j+1,n,m,grid,dp);
        if(i+1<n && j<m)right= grid[i][j]+go(i+1,j,n,m,grid,dp);
        return dp[i][j]= min(down,right);
    }
};
