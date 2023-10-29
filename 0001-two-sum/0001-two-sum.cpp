class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         unordered_map<int, int> mpp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
        int moreNeeded = target - nums[i];
        if (mpp.find(moreNeeded) != mpp.end()) {
            return {mpp[moreNeeded], i};
        }
            
                 mpp[nums[i]] = i; // Store the current element and its index
 
    }
    return { -1, -1};
   }
    
};