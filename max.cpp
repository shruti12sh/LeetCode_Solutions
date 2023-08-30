#include <bits/stdc++.h> 
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    int prev= nums[0];
    int prev2 = 0;
    for(int i=1;i<n;i++){
 int take = nums[i] ;
  if(i>1) take += prev2;
  int not_pick = 0 + prev;
    
int curr = max(take,not_pick);
prev2 = prev;
prev = curr;
  
    }
    return prev;
}
