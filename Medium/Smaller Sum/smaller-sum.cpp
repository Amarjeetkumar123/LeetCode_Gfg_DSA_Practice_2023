//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
       
       vector<pair<int,int>>new_arr;
       
       for(int i=0;i<arr.size();i++){
           new_arr.push_back(make_pair(arr[i],i));
       }
       
       sort(new_arr.begin(),new_arr.end());
       
       vector<long long>prefix_sum(arr.size());
       
       prefix_sum[0] = new_arr[0].first;
       
       for(int i=1;i<arr.size();i++){
           prefix_sum[i] = prefix_sum[i-1] + new_arr[i].first;
       }
       
       
       vector<long long>ans(arr.size());
       
       int idx = new_arr[0].second;
       ans[idx] = abs(prefix_sum[0]-new_arr[0].first);
       
       for(int i=1;i<arr.size();i++){
           
           if(new_arr[i].first == new_arr[i-1].first){
               int idx1 = new_arr[i].second;
               idx = new_arr[i-1].second;
               
               ans[idx1] = ans[idx];
           }
           else{
               idx = new_arr[i].second;
               ans[idx] = abs(prefix_sum[i] - new_arr[i].first);
           }
       }
       
       return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends