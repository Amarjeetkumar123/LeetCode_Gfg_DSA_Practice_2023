//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<int> findMaxRow(vector<vector<int>> mat, int N) {
       
       vector<int>ans(2);
       int max_count = INT_MIN;
       for(int i=0;i<mat.size();i++){
           int cnt = 0;
           
           for(int j=0;j<mat[0].size();j++){
               if(mat[i][j] == 1){
                   cnt++;
               }
           }
           
           if(cnt > max_count){
               ans[0] = i;
               ans[1] = cnt;
           }
           max_count = max(max_count,cnt);
       }
       
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> arr(n, vector<int> (n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        vector<int> ans = obj.findMaxRow(arr, n);
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends