//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string S) {
        unordered_map<char,int>mp;
        
        for(auto ch : S){
            mp[ch]++;
        }
        
        int s=0 , e = S.size()-1;
        
        bool dir = 0;
        while(s < e){
            
            if(dir == 0){
                if(mp[S[s]] == 1){
                     s++;
                }
                else{
                    
                    mp[S[s]]--;
                    S[s] = '@';
                    s++;
                    dir = 1;
                }
            }
            else{
                if(mp[S[e]] == 1){
                    e--;
                }
                else{
                    
                    mp[S[e]]--;
                    S[e] = '@';
                    dir = 0;
                    e--;
                }
            }
        }
        
        string ans = "";
        for(auto x : S){
            if(x != '@'){
                ans += x;
            }
        }
        
        if(dir == 1)
            reverse(ans.begin(),ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends