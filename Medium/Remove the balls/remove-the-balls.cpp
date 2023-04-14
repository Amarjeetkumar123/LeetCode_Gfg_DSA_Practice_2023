//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int finLength(int N, vector<int> color, vector<int> radius) {
        
        
        stack<pair<int,int>>st;
        
        for(int i=0;i<color.size();i++){
            
            pair<int,int> temp = make_pair(color[i],radius[i]);
            if(!st.empty() && temp.first == st.top().first && temp.second == st.top().second ){
                st.pop();
            }
            else{
                 st.push(temp);
            }
            
        }
        
        return st.size();
    }
};


//{ Driver Code Starts.
int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        vector<int> color(n), radius(n);
        for (int i = 0; i < n; i++) cin >> color[i];
        for (int i = 0; i < n; i++) cin >> radius[i];
        int ans = sol.finLength(n, color, radius);
        cout << ans << "\n";
    }

    return 0;
}

// } Driver Code Ends