//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    long long gcd(long long a , long long b){
        // base case
        if(b == 0)
            return a;
        
        return gcd(b,a%b);
    }
    
    long long solve(int n){
         // formula used : a*b = gcd(a,b) * lcm(a,b);
       // step 1 : To find lcm of largest 4 possible num = n, n-1, n-2, n-3
       
       long long x = (n*(n-1)) / gcd(n,n-1);
       long long y = ((n-2)*(n-3)) / gcd(n-2,n-3);
       
       long long z = (x*y) / gcd(x,y);
       
       // step 2 : a,b,c,d are co-primes (i.e. gcd(a,b,c,d) == 1) then lcm = a*b*c*d
       
       long long num = (n * (n-1));    // to find a,b
       int cnt = 0;
       
       for(long long i=n-2;i>=1;i--){ // to find c,d      constant time
           
           if(gcd(num,i) == 1){ // log(n)
               num = num * i;
               cnt++;
           }
           
           if(cnt == 2) break;
           
       }
       return max(z,num);
    }
  public:
    long long maxGcd(int n) {
      
       return max(solve(n),solve(n-1));
       
       // total time complexity : log(n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.maxGcd(N) << "\n";
    }
}
// } Driver Code Ends