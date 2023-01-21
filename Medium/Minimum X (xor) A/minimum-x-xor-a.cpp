//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   int setBit(int n){
        
        int count=0;
        while(n>0)
        {
            if((n&1)!=0)
            count++;

            n=n/2;
        }
        return count;
    }
    
    int minVal(int a, int b) {
        
        int sB1 = setBit(a);
        int sB =  setBit(b);
        if(sB1==sB)
        return a;

        int ans=0;
        for(int i=0; i<=31 ;i++)
        {
            int mask = 1<<i;
            int set = a & mask;

            if(set==0 && sB1 < sB)
            {
                ans |= mask; // ans = ans|mask // include the mask in ans -y ? i flipped 0->1/ // to amake the number of 1 in x equla to b
                sB--;
            }
            else if(set!=0 && sB1 > sB)
            {
                sB1--;
            }
            else
            {
                ans |= set ; // including the same ithe bit of A in ans(x);
            }
        }
        return ans;

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends