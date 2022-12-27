//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

long long maxArea(long long A[], int len)
{
    // Optimise solution (Two Pointers)
    
    int low=0 , high=len-1;
    long long ans = 0;
    while(low < high){
        
        long long area = (high-low)*min(A[low],A[high]);
        
        if(A[low] < A[high])
            low++;
        else
            high--;
            
        ans = max(ans,area);
    }
    
    return ans;
}

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends