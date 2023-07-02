class Solution {
    
public:
    
    int solve(vector<int>&cookies,int i,vector<int>&a){
       int n=cookies.size();
        if(i==n){
            int ans =0;
            for(auto it: a)
                ans =max(ans,it);
                return ans;  
        }
        int mn = INT_MAX;
        for(int j=0;j<a.size();j++){
            a[j]  += cookies[i];
            mn = min(mn,solve(cookies,i+1,a));
            a[j]  -= cookies[i];
        }
        return mn;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>a(k);
        int i;
        return solve(cookies,0,a);
    }
};