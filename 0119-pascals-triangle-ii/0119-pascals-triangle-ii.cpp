class Solution {
public:
    vector<int> getRow(int rowIndex) {

    vector<int>ds;
    long long ans=1;
    ds.push_back(ans);
    for(int col=0;col<rowIndex;col++)
    {
        ans=ans*(rowIndex-col);
        ans=ans/(col+1);
        ds.push_back(ans);
    }
    return ds;
   }
    
};