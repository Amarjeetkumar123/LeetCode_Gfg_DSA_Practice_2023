//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    // dijkstra's algorithm
  public:
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        // create adjacency list
        unordered_map<int,list<pair<int,int>>>adj;
        
        for(int i=0;i<flights.size();i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            
            adj[u].push_back(make_pair(v,w));
        }
        
        // creating distance array
        vector<int>dist(n+1,INT_MAX);
        
        // creating priority_queue on basis of( distance , node)
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;

        dist[k]=0;

        q.push({dist[k],k});

        int ans = -1;


        while(!q.empty()){

            auto it =  q.top();

            q.pop();

            int node = it.second;

            int cost = it.first;

            for(auto i:adj[node]){

                if(dist[i.first]>cost+i.second){

                    dist[i.first]=cost+i.second;

                    q.push({dist[i.first],i.first});

                }

            }

        }
        
        for(int i=1;i<dist.size();i++){
            if(dist[i] == INT_MAX)
                return -1;
            else
                ans = max(ans,dist[i]);
        }    
            
       return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends