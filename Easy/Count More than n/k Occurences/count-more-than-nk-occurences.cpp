//{ Driver Code Starts
// A C++ program to print elements with count more than n/k

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) {
       
        if (k < 2)
        return 0;

        
       vector<pair<int,int>>v(k-1,{0,0});
       
       for(int i=0;i<n;i++){
           int j;
           // if arr[i] is aready present in v
           for(j=0;j<k-1;j++){
               if(arr[i] == v[j].first){
                   v[j].second++;
                   break;
               }
           }
           
           // If arr[i] is not present in v
           
           if(j == k-1){
               int l;
               
               for(l=0;l<k-1;l++){
                   if(v[l].second == 0){
                       v[l].first = arr[i];
                       v[l].second = 1;
                       break;
                   }
               }
               
               // if no one have count 0 in v
               if(l == k-1)
                   for(l=0;l<k-1;l++){
                       v[l].second--;
                   }
               
           }
    
       }
       
       // Calculate actual count of elements
           int ans = 0;
           for(int i=0;i<k-1;i++){
               
               int cnt = 0;
               for(int j=0;j<n;j++){
                   if(arr[j] == v[i].first)
                    cnt++;
               }
               
               
               if(cnt > n/k)
                ans++;
               
           }
       
       return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t, k;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;

        int arr[n];

        for (i = 0; i < n; i++) cin >> arr[i];
        cin >> k;
        Solution obj;
        cout << obj.countOccurence(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends