//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string longestString(vector<string> &words)
    {
        unordered_map<string,int>mp;
        
        // sort the array
        sort(words.begin(),words.end());
        
        for(auto s : words){
            mp[s]++;
        }
        
        int size = INT_MIN;
        string ans;
        for(auto i : words){
            
            int cnt = 0; int n = i.size();
            string temp="";
            for(int j=0;j<n;j++){
                
                temp += i[j];
                if(mp.count(temp)){
                    cnt++;
                }
            }
            if(cnt == n && n > size){
                ans = i;
                size = n;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends