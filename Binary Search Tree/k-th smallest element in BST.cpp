/*
Given a BST and an integer K. Find the Kth Smallest element in the BST. 

Example 1:
Input:
      2
    /   \
   1     3
K = 2
Output: 2

Example 2:
Input:
        2
      /  \
     1    3
K = 5
Output: -1
*/
class Solution {
  public:
    void modInorder(Node *root, int& K, int& ans)
    {
        if(K < 0)
            return;
        if(!root)
            return;
        
        modInorder(root->left, K, ans);
        K--;
        if(K == 0)
            ans = root->data;
        modInorder(root->right, K, ans);
    }
    int KthSmallestElement(Node *root, int K)
    {
        int ans = -1;
        modInorder(root, K, ans);
        return ans;  
    }
};
