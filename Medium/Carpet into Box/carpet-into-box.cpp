//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int carpetBox(int A, int B, int C, int D){
        
        int length = A;
        int breadth = B;
        
        int moves = 0;
        
        while(length > C || breadth > D){
            
            if(length > C){
                length = length/2;
                moves++;
            }
            if(breadth > D){
                breadth = breadth/2;
                moves++;
            }
        }
        
        int prev_ans = moves;
        moves = 0;
        // rotate 90 deg
        length = B;
        breadth = A;
        
        while(length > C || breadth > D){
            
            if(length > C){
                length = length/2;
                moves++;
            }
            if(breadth > D){
                breadth = breadth/2;
                moves++;
            }
        }
        
        return min(prev_ans,moves);
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends