class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>> ans(2);
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            while (i < n1-1 && nums1[i] == nums1[i+1]) i++;
            while (j < n2-1 && nums2[j] == nums2[j+1]) j++;
            if (nums1[i] < nums2[j]) {
                ans[0].push_back(nums1[i++]);
            }
            else if (nums1[i] > nums2[j]) {
                ans[1].push_back(nums2[j++]);
            }
            else {
                i++;
                j++;
            }
        }
        while (i < n1) {
            while (i < n1-1 && nums1[i] == nums1[i+1]) i++;
            ans[0].push_back(nums1[i++]);
        }
        while (j < n2) {
            while (j < n2-1 && nums2[j] == nums2[j+1]) j++;
            ans[1].push_back(nums2[j++]);
        }
        return ans;
    }
};