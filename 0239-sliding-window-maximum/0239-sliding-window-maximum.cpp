class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int i=0,j=0;
        vector<int>ans;
         int n = arr.size();
        deque<int>dq;
        while(i<n){
            // if it exceeds the window remove it from front beacuse max is at front and that is now beyond the window size so remove 
            if(!dq.empty() and dq.front()<i-k+1)dq.pop_front();
           // if upcoming elemnt is higher that that present at back we remove that element 
            while(!dq.empty() and arr[dq.back()]<arr[i]){
                dq.pop_back();
            }
          // insert the index in deque
            dq.push_back(i++);
         //  push the fornt of deque in vector
            if(i>k-1)ans.push_back(arr[dq.front()]);
        }
        return ans;
          
    }
};