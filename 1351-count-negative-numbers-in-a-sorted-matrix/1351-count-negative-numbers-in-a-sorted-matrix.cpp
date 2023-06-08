class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
          int total = 0;
          for(int i=0;i<grid.size();i++){
              int neg = upper_bound(grid[i].rbegin(),grid[i].rend(),-1)-grid[i].rbegin();
              total += neg;
          }
return total;
           
          }
        
};