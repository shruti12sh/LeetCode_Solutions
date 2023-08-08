//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//User function Template for C++

class BrowserHistory {
public:
     // constructor to initialize object with homepage
    vector<string> pages;
    string homePage;
    int currpage;
    BrowserHistory(string homepage) {
        pages.push_back(homepage);
        homePage=homepage;
        currpage=0;
    }
    
    // visit current url
    void visit(string url) {
        currpage += 1;
        if (currpage < pages.size()) {
            pages.resize(currpage); 
        }
        pages.push_back(url);
    }
    
    // 'steps' move backward in history and return current page
    string back(int steps) {
        currpage=max(0, currpage-steps);
        return pages[currpage];
    }
    
    // 'steps' move forward and return current page
    string forward(int steps) {
        if(currpage+steps>=pages.size()){
            currpage=pages.size()-1;
            return pages[pages.size()-1];
        }
        currpage+=steps;
        return pages[currpage];
    }
};


//{ Driver Code Starts.

int main()
{
    string homepage;
    cin >> homepage;
    
    BrowserHistory obj(homepage);
    
    int total_queries;
    cin >> total_queries;
    while(total_queries--)
    {
        int query;
        cin >> query;
        
        // if query = 1, visit()
        // if query = 2, back()
        // if query = 3, forward()
        
        if(query == 1) {
            string url;
            cin >> url;
            obj.visit(url);
        }
        else if(query == 2) {
            int steps;
            cin >> steps;
            cout << obj.back(steps) << endl;
        }
        else {
            int steps;
            cin >> steps;
            cout << obj.forward(steps) << endl;
        }
    }
    return 0;
}
// } Driver Code Ends