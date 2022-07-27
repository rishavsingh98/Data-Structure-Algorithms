/*
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

Example 1:
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: inorder = [-1], postorder = [-1]
Output: [-1]

Constraints:
1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.

*/
class Solution {
    TreeNode* buildTreeRec(vector<int>& inorder, int iStart, int iEnd, vector<int>& postorder, int pStart, int pEnd)
    {
        if(iStart >= iEnd or pStart >= pEnd) return nullptr;
        
        TreeNode* root = new TreeNode(postorder[pEnd - 1]);
        auto it = find(inorder.begin() + iStart, inorder.begin() + iEnd, root->val);
        int index = it - inorder.begin() - iStart;
        
        root->left = buildTreeRec(inorder, iStart, iStart + index, postorder, pStart, pStart + index);
        root->right = buildTreeRec(inorder, iStart + index + 1, iEnd, postorder, pStart + index, pEnd - 1);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size(); 
        if(n == 0) return nullptr;
        return buildTreeRec(inorder, 0, n, postorder, 0, n);
    }
};
