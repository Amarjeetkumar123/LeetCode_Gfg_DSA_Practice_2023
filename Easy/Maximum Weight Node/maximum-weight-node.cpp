//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int N, vector<int> Edge)
  {
      vector<int>wt(N);
      
      for(int i=0;i<N;i++){
          if(Edge[i] != -1)
            wt[Edge[i]] += i;
      }
      
      int mx_wt = -1 , mx_wt_idx = -1;
      
      for(int i=0;i<N;i++){
          
          if(wt[i] >= mx_wt){   // If there are multiple cells with the maximum weight return the cell with highest index.
              mx_wt = wt[i];
              mx_wt_idx = i;
          }
      }
      
      return mx_wt_idx;
  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends