/*
https://www.codingninjas.com/codestudio/problems/largest-sub-tree-sum_920400
Given a binary tree, task is to find subtree with maximum sum in tree.
Examples: 
Input :       1
            /   \
           2      3
          / \    / \
         4   5  6   7
Output : 28
As all the tree elements are positive,
the largest subtree sum is equal to
sum of all tree elements.

Input :       1
            /    \
          -2      3
          / \    /  \
         4   5  -6   2
Output : 7
Subtree with largest sum is :  -2
                             /  \ 
                            4    5
Also, entire tree sum is also 7.

*/
class Solution {
    int largestSubtreeSumRec(Node* root, int& maxsum) 
    {
        int left = -9999, right = -9999, subtreesum = 0;
        if(!root->left and !root->right)
        {
            maxsum = max(maxsum,root->data);
            return root->data;
        }
        if(root->left)
        {
            left = largestSubtreeSumRec(root->left,maxsum);
            subtreesum += left;
        }
        if(root->right)
        {
            right = largestSubtreeSumRec(root->right,maxsum);
            subtreesum += right;
        }
        int m = max(left,right);
        subtreesum += root->data;
        m = max(m,subtreesum);
        maxsum = max(maxsum,m);
        return subtreesum;
    }
public:
    // Function to find largest subtree sum.
    int findLargestSubtreeSum(Node* root)
    {
        int maxsum = -9999;
        largestSubtreeSumRec(root,maxsum);
        return maxsum;
    }
};
