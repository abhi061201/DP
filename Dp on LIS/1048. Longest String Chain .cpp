class Solution {
public:
    static bool comp(string &a,string &b){
        return a.size()<b.size();
    }
    int longestStrChain(vector<string>& words) {
        int n= words.size();
        vector<int>lis(n,1);
        sort(words.begin(),words.end(),comp);
        // for(auto it : words)cout<<it<<" ";
        int ans=0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<i ; j++){
                if( check(words[i],words[j]) &&1+lis[j] >lis[i]){
                    lis[i]= max(lis[i],1+lis[j]);
                }
                
            }
            ans= max(ans,lis[i]);
        }
        return ans;
        
    }
    bool check(string &s1,string &s2){
        int n= s1.length();
        int m=s2.length();
        if(n-1!=m)return false;
        int i=0,j=0;
        while(i<n ){
            if(s1[i]!=s2[j]){
                i++;
            }
            else {
                i++;j++;
            }
        }
        if(i==n && j==m)return 1;
        return 0;
    }
};
