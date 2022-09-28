/*
Given a Binary search tree. Your task is to complete the function which will return the Kth largest element without doing any modification in Binary Search Tree.

Example 1:
Input:
      4
    /   \
   2     9
k = 2 
Output: 4

Example 2:
Input:
       9
        \ 
          10
K = 1
Output: 10
*/
class Solution
{
    public:
    
    void revInorder(Node *root, int& K, int& ans)
    {
        if(K < 0)
            return;
        if(!root)
            return;
        
        revInorder(root->right, K, ans);
        K--;
        if(K == 0)
            ans = root->data;
        revInorder(root->left, K, ans);
    }
    
    int kthLargest(Node *root, int K)
    {
        int ans = -1;
        revInorder(root, K, ans);
        return ans;
    }
};
