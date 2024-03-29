//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int n, string s, int x){
        
       vector<int>v;
       
        for(int i=0;i<n;i++){
            
            if(s[i]=='1'){
                v.push_back(i);
            }
        }
        
        for(int i=0;i<v.size()-1;i++){
            
            if(v[i+1]-v[i]-1>2*x){
                return false;
            }
        }
        
        if(v[0]>x) return false;
        
        if(n-1-v[v.size()-1]>x) return false;
        
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends