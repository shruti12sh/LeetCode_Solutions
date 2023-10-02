class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
      list<int>li;
        vector<int>ans;
        int i=0,j=0;
        
        while(j<arr.size()){
            
            while(li.size()>0 && li.back()<arr[j]){
                li.pop_back();
            }
            li.push_back(arr[j]);
            
            if(j-i+1 < k)j++;
            
            else if(j-i+1 == k){
                ans.push_back(li.front());
                
                if(arr[i] == li.front()){
                    li.pop_front();
                }
                i++;
                j++;
            }
        }
        return ans;
          
    }
};