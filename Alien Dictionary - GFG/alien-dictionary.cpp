//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        vector <int> adj[K];
        // encode : 0->a, 1->b 
        for(int i=0; i<N-1; i ++){
            int l1 = dict[i].size();
            int l2 = dict[i+1].size();
            int j = 0;
            while (j<l1 and j<l2){
                if (dict[i][j]!=dict[i+1][j]){
                    adj[int(dict[i][j]-'a')].push_back(int(dict[i+1][j]-'a'));
                    break;
                }
                j++;
            }
            
        }
        
        
        int V = K;
        // now find in-degree
        int ind [V] = {0};
        for(int i=0;i<V;i++){
            for(auto j: adj[i]){
                ind[j]++;
            }
        }
        // adding terminal node in queue
        queue <int> q;
        for(int i=0;i<V;i++){
            if (ind[i]==0){
                q.push(i);
            }
        }
        
        // finding topo sort
        string res = "";
        while (q.size()){
            int node = q.front();
            q.pop();
            
            res+=char(node+'a');
            
            for(int i: adj[node]){
                ind[i]--;
                if (ind[i]==0){
                    q.push(i);
                }
            }
            
        }
        
        return res;
        
    
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends