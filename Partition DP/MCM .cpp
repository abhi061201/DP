BOTTOM UP

TC- O(n^3)
SC= O(n^2)

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int n, int arr[])
    {
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=n-1 ; i>0 ; i--){
            for(int j= i+1; j<n ; j++){
                int step=1e9;
                for(int k=i; k<j ; k++){
                    step= min(step, arr[i-1]* arr[j]*arr[k]
                    +dp[i][k]+dp[k+1][j]);
                }
                dp[i][j]= step;
            }
        }
        
        return dp[1][n-1];
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends

TOP DOWN

TC- O(n^3)
SC- O(n^2)+O(n)

  // { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int n, int arr[])
    {
        vector<vector<int>>dp(n,vector<int>(n,-1));
       
        
        return go(1,n-1,arr,dp);
        
    }
    int go(int i, int j, int arr[],vector<vector<int>>&dp){
        if(i==j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int step=1e9;
        for(int k=i; k<j ; k++){
            step= min(step, arr[i-1]* arr[j]*arr[k]
            + go(i,k,arr,dp)+go(k+1,j,arr,dp));
        }
        return dp[i][j]=step;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends

