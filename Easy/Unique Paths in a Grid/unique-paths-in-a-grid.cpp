//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int mod = 1000000007;
    vector<vector<int>>dp;
    int solve(int n, int m, vector<vector<int>> &grid, int i, int j){
        
        if(i == n-1 && j == m-1)
            return 1;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ways = 0;
        if(j+1 < m && grid[i][j+1] == 1){
            ways += solve(n,m,grid,i,j+1);
        }
        if(i+1 < n && grid[i+1][j] == 1){
            ways += solve(n,m,grid,i+1,j);
        }
        
        return dp[i][j] =  ways%mod;
    }
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
       
       if(grid[0][0] == 0)
            return 0;
        
        dp.resize(n,vector<int>(m,-1));
       return solve(n,m,grid,0,0)%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends