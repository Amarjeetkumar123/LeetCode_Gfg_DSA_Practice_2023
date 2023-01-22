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
    int solve(int N, int K, vector<int> &arr) {
        
         int sum=0;
        for(int i=0; i<N; i++)  //N
        {
            sum += arr[i];
        }
        //s2 find factors of sum - AL
        vector<int>factors;  // sqrt(sum)  sqrt(0^4 * 10^5) = 10^4
        for(int i =1; i*i<=sum; i++)
        {
            if(sum%i==0)
            {
                factors.push_back(i);
                if(i != sum/i)  //  36 i=6
                factors.push_back(sum/i);
            }
        }
        // al - 1,10,2,5
        //s3
        sort(factors.begin(),factors.end());
        
        //s4 - presum - poss of sA i can take in my ans
        for(int i=1; i<N; i++)
        arr[i] = arr[i]+arr[i-1];
        
        //s5
        int ans=1;
        for(int i=factors.size()-1 ;i>=0; i--)  //x
        {
            int count_of_SA=0;
           for(int j=0; j<N; j++) // in pre sum arr  //n
           {
               if(arr[j] % factors[i] == 0)
               count_of_SA++;
           }
           if(count_of_SA >=K)   //getting the maximum poss G(factors of sum)
           {
               ans = factors[i];
               break;
           }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> arr(N);
        Array::input(arr,N);
        
        Solution obj;
        int res = obj.solve(N, K, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends