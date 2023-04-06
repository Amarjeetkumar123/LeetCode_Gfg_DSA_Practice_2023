//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }
 
    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int equalSum(int N, vector<int> &A) {
        
        vector<int>prefix(N);
        vector<int>suffix(N);
        
        for(int i=0;i<N;i++){
            if(i==0)
                prefix[i] = A[i];
            else
            prefix[i] = prefix[i-1]+A[i];
        }
      
        for(int j=N-1;j>=0;j--){
            if(j == N-1)
                suffix[j] = A[j];
            else
            suffix[j] = suffix[j+1] + A[j];
        }
        
        for(int i=0;i<N;i++){
            if(prefix[i]-suffix[i] == 0)
                return i+1;
        }
        
        return -1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N; 
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        int res = obj.equalSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends