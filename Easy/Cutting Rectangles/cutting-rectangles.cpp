//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long gcd(long long a , long long b){
        
        if(b==0)
            return a;
            
        return gcd(b,a%b);
    }
    vector<long long int> minimumSquares(long long int L, long long int B)
    {
        long long K = gcd(L,B);
        
        long long N = (L/K*B/K);
        
        return {N,K};
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long int L, B;
        cin>>L>>B;
        
        Solution ob;
        vector<long long int> ans = ob.minimumSquares(L, B);
        cout<<ans[0]<<" "<<ans[1]<<"\n";
    }
    return 0;
}
// } Driver Code Ends