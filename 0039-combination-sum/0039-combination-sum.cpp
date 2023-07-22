class Solution {
public:
void f1(int idx,vector<int>&ds,int sum,int target,vector<int>&candidates,int n,        vector<vector<int>>&ans){
    if(idx==n) 
    {if(sum==target){ ans.push_back(ds);}return;}
    if(sum+candidates[idx]<=target){
             ds.push_back(candidates[idx]);
             sum += candidates[idx];
             f1(idx,ds,sum,target,candidates,n,ans);
             sum -= candidates[idx];
             ds.pop_back();}
    
            f1(idx+1,ds,sum,target,candidates,n,ans);}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        int n = candidates.size();
         f1(0,ds,0,target,candidates,n,ans);
        
     return ans;
    }
};