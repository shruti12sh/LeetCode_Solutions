//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{ 
    private:
    int findSmaller(vector<vector<int>> &matrix,int assumedMedian){
        int n = matrix.size();
        int ele = 0;
        for(int i=0;i<n;i++){
            int start = 0;
            int end = matrix[i].size() - 1;
            while(start<=end){
                int mid = start+(end-start)/2;
                if(matrix[i][mid]<=assumedMedian)
                {
                    start = mid+1;
                }
                else{
                    end = mid -1;
                }
            }
            ele += start;
            
        }
        return ele;
    }
public:
    int median(vector<vector<int>> &matrix, int R, int C){
        int n = R*C;
        int median = n/2;
        // code here 
        int low = 0;
        int high= 2000;
        while(low<=high){
            int assumedMedian = low + (high-low)/2;
            int smallerElements = findSmaller(matrix,assumedMedian);
            if(smallerElements<=median)
             low = assumedMedian +1 ;
             else
             high = assumedMedian -1;
        }
        return low;
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends