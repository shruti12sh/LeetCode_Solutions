class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        
        
        struct Comparator {
    bool operator()(pair<int, int>lhs, pair<int, int> rhs){
        return lhs.second < rhs.second; // Compare values, not keys
    }
};
    priority_queue<pair<int,int>,vector<pair<int,int>>,Comparator>ds;
         for (const auto& pair : mp) {
        ds.push(pair);
    }

        for(int i=0;i<k;i++){
            pair<int,int>p;
            p = ds.top();
            ds.pop();
           ans.push_back(p.first);
        }
        return ans;
    }
};