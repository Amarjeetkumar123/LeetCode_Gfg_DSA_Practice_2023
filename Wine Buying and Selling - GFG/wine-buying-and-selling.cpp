//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  long long int wineSelling(vector<int>& arr, int n){
      
      long long ans = 0;
      int buyer = 0;    // positive
      int seller = 0;   // negative
      
      while(1){
          
          while(arr[buyer] <= 0 && buyer < n)
            buyer++;
        
          while(arr[seller] >= 0 && seller < n)
            seller++;
            
        
          if(buyer == n || seller == n)
            break;
            
          int x = min(arr[buyer],-arr[seller]);
          
          arr[buyer] -= x;
          arr[seller] += x;
          
          ans += x*abs(buyer-seller);
      }
      
      return ans;
  }
};



//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        long long int ans = ob.wineSelling(arr,n);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends