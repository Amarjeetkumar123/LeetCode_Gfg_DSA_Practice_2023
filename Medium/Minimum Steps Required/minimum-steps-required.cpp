//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
   
    int cnt_a = 0 , cnt_b = 0;
    
    if(str[0] == 'a')
        cnt_a++;
    else
        cnt_b++;
        
    for(int i=1;i<str.length();i++){
        
        if(str[i] != str[i-1]){
            if(str[i] == 'a')
                cnt_a++;
            else
                cnt_b++;
        }
    }
    
    int ans = min(cnt_a,cnt_b);
    
    return ans+1;
    
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends