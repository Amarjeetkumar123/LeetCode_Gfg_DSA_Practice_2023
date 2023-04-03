//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++


class Solution
{

public:
    int xmod11(string x)
    {
       
       long odd_sum = 0 , even_sum = 0;
       
       for(int i=0;i<x.length();i++){
           
           if(i%2 == 0)
                odd_sum += (x[i]-'0');
           else 
                even_sum += (x[i]-'0');
       }
       
        long diff = (odd_sum - even_sum)%11;
        
        if(x.length()%2 == 0){
            return abs(diff-11)%11;
        }
         
         return diff;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string x;
        cin>>x;
        Solution ob;
        int ans = ob.xmod11(x);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends