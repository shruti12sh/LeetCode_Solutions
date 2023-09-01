class Solution {
    private:
    int find(int idx , vector<int>&nums,int n,vector<int>&dp){
        if(idx>=n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        return dp[idx] = max(find(idx+2,nums,n,dp)+ nums[idx],find(idx+1,nums,n,dp));
    }
public:
    int rob(vector<int>& nums) {
       int n = nums.size();
        vector<int>dp(n+2,-1);
        return find(0,nums,n,dp);
    }
};