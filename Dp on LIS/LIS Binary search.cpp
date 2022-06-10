int Solution::lis(const vector<int> &nums) {
    
    vector<int>v;
    int n= nums.size();
    v.push_back(nums[0]);
    for(int i=1 ; i<n ; i++){
        int ind= lower_bound(v.begin(), v.end(),nums[i])-v.begin();
        if(ind==v.size())v.push_back(nums[i]);
        else v[ind]=nums[i];
    }
    
    
    return v.size();
    
}
