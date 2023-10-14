class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        

        int ans = 1;
        sort(nums.begin(), nums.end());
        for(auto i: nums) if(i == ans) ans++;
        return ans;
    }
    
};