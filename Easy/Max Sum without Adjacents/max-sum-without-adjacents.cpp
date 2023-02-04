//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    int solve(int *arr, int n, int i, vector<int>&dp){
        
        if(i > n)
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
            
        // take
        int take = arr[i] + solve(arr,n,i+2,dp);
        
        // not take
        int not_take = 0 + solve(arr,n,i+1,dp);
        
        return dp[i] = max(take,not_take);
    }
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    vector<int>dp(n+1,-1);
	    
	    return solve(arr,n-1,0,dp);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends