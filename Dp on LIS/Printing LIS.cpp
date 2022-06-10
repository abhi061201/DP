class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n =nums.size();
        vector<int>lis(n,1);
        vector<int>hash(n);
        
        for(int i=0 ; i<n ; i++){
            hash[i]=i;
            for(int j=0 ; j<=i ; j++){
                if(nums[i]>nums[j] && 1+ lis[j] > lis[i]){
                lis[i] = 1+lis[j];
                    hash[i]=j;
                }
                
            }
        }
        int maxi_index=0,ans=0;
        for(int i=0 ; i<n ; i++){
            if(ans<lis[i]){
                ans=lis[i];
                maxi_index=i;
            }
        }
        int curindex=maxi_index;
        
        vector<int>printlis;
        printlis.push_back(nums[maxi_index]);
        while(hash[curindex]!=curindex){
            curindex= hash[curindex];
            printlis.push_back(nums[curindex]);
            
        }
        reverse(printlis.begin(), printlis.end());
        for(auto it : printlis){
            cout<<it<<" ";
        }
        cout<<"\n";
        
        return ans;
    }
};
