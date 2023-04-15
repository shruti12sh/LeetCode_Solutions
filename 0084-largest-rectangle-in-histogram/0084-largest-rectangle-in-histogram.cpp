class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
      stack<int> st;
        int n=heights.size();
        vector<int> nse(n,-1),pse(n);
        st.push(0);
        for(int i=1;i<n;i++)
        {
            while(!st.empty() && heights[i]<heights[st.top()])
            {
                nse[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty())
        {
            nse[st.top()]=n;
            st.pop();
        }
        st.push(n-1);
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty() && heights[i]<heights[st.top()])
            {
                pse[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty())
        {
            pse[st.top()]=-1;
            st.pop();
        }
        int maxarea=0;
        for(int i=0;i<n;i++)
        {
            maxarea=max(maxarea,heights[i]*(nse[i]-pse[i]-1));
        }
        return maxarea;
    }
};