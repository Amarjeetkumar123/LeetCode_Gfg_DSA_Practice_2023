//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    Node* search(Node* root , int target, int &sum1){
        
        if(root == NULL)
            return NULL;
        
        sum1 += root->data;
        
        if(root->data == target)
            return root;
        
        if(target < root->data){
            return search(root->left, target, sum1);
        }
        else{
            return search(root->right,target,sum1);
        }
    }
    
    int min_sum(Node* root){
        
        if(root->left == NULL && root->right == NULL)
            return root->data;
        
        int mn = INT_MAX;
        if(root->left){
            mn = min(mn,min_sum(root->left));
        }
        if(root->right){
            mn = min(mn,min_sum(root->right));
        }
        
        return mn+root->data;
    }
    
    int maxDifferenceBST(Node *root,int target){
        
        int sum1 = 0;
        Node* target_node = search(root,target,sum1);
        
        if(target_node == NULL)
            return -1;
        
        int sum2 = min_sum(target_node);
        
        return sum1-sum2;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends