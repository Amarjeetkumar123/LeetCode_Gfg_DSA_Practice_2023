//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestXYDist(vector<vector<char>> grid, int N, int M) {
        
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>visited(N,vector<int>(M,0));
        
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(grid[i][j] == 'X'){
                    q.push({{i,j},0});
                    visited[i][j] = 1;
                }
            }
        }
        
        int ans = INT_MAX;
        
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        
        while(!q.empty()){
            
            auto it = q.front();
            q.pop();
            
            int r = it.first.first;
            int c = it.first.second;
            int dist = it.second;
            
            if(grid[r][c] == 'Y')
                return dist;
                
            for(int i=0;i<4;i++){
                
                int new_r = r + dx[i];
                int new_c = c + dy[i];
                
                if(new_r < N && new_r >=0 && new_c < M && new_c >= 0 && visited[new_r][new_c] == 0){
                    
                    q.push({{new_r,new_c},dist+1});
                    visited[new_r][new_c] = 1;
                }
            }
            
        }
        
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends