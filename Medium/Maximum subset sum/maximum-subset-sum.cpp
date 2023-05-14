//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
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
    vector<vector<int>>dp;
    long long solve(int index, vector<int>&arr,int last_take){
        
        if(index >= arr.size())
            return 0;
            
        if(dp[index][last_take] != -1)
            return dp[index][last_take];
        
        if(last_take == 0){
            
            return dp[index][last_take] = arr[index] + solve(index+1, arr, 1);
        }
        
        if(last_take == 1){
            
            return dp[index][last_take] = max(solve(index+1, arr, 0), arr[index] + solve(index+1, arr, 1));
        }
        
    }
    
    long long findMaxSubsetSum(int N, vector<int> &A) {
        
        dp.resize(N,vector<int>(2,-1));
        
        return max(solve(0,A,0),solve(0,A,1));
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
        IntArray::input(A,N);
        
        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends