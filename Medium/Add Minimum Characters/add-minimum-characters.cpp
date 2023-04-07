//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int addMinChar(string str){    
        
        int s = 0;
        int e = str.length()-1;
        int cnt = 0;
        while(s <= e){
            
            if(str[s] != str[e]){
                cnt++;
                s = 0;
                e = str.length()-1-cnt;
            }
            else{
                s++;
                e--;
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends