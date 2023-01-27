//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	     int mod = 1e9+7;
	     int solve(int index , string s, vector<int>&dp){
            // base case
            if(s[index] == '0')
                return 0;
            
            if(index == s.size())
                return 1;
            
            if(dp[index] != -1)
                return dp[index];
            
            // take single single
            int option1 = solve(index+1,s,dp);
            
            // take couple
            int option2 = 0;
            if(index < s.size()-1 && (s[index] == '1' || s[index] == '2' && s[index+1] <= '6')){
                option2 += solve(index+2, s, dp);
            }
            
            return dp[index] = (option1%mod+option2%mod)%mod;
        }
    
		int CountWays(string str){
		    
		    vector<int>dp(str.size()+1,-1);
            return solve(0,str,dp);
            
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends