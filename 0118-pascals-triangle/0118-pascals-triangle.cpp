class Solution {
public:
    
    vector<int>genraterows(int num){
        long long ans = 1;
        vector<int>ansrow;
        ansrow.push_back(1);
        for(int col=1;col<num;col++){
            ans = ans * (num-col);
            ans = ans/col;
            ansrow.push_back(ans);
            
        }
        return ansrow;
        
    }
    
    
    vector<vector<int>> generate(int numRows) {
      vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(genraterows(i));
        }
        return ans;
    }
};