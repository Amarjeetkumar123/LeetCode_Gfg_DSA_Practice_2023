//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        
        unordered_map<char,int>mp;
        
        for(auto ch : s)
            mp[ch]++;
            
        int flag = 1;
        int ans = 0;
        while(flag){
            if(mp['b'] >= 1 && mp['a'] >= 1 && mp['l'] >= 2 && mp['o'] >= 2 && mp['n'] >= 1){
                ans++;
                mp['b']--;
                mp['a']--;
                mp['l'] -= 2;
                mp['o'] -= 2;
                mp['n']--;
            }
            else{
                flag = 0;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends