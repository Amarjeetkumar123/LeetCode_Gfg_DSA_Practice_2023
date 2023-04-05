//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int N, vector<int> arr) {
       
       int max_num = INT_MIN;
      for(auto i : arr){
          max_num = max(max_num,i);
      }
      
      vector<int>freq(max_num+1,0);
      
      for(auto elem : arr){
          
          if(freq[elem] <= 1){
              for(int j = elem; j <= max_num; j=j+elem){
              freq[j]++;
            }
          }
      }
      
      int cnt = 0;
      for(auto x : arr){
          if(freq[x] > 1)
            cnt++;
      }
      
      return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends