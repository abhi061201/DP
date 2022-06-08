TC- O(n)
Sc= O(1)  

class Solution {
public:
    int maxProfit(vector<int>& nums) {
      
        
        int ans =0;
        int mini= nums[0];
        int maxi= nums[0];
        int n= nums.size();
        for(int i=0 ; i<n ; i++){
            
            if(mini>nums[i]){
                maxi=nums[i];
                mini=nums[i];
            }
            else if(maxi<nums[i]){
                maxi=nums[i];
                ans= max(ans,maxi-mini);
                
            }
        }
        return ans;
            
    }
};
