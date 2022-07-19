/*
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example 1:
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]

Example 2:
Input: root = [1,null,3]
Output: [1,3]

Example 3:
Input: root = []
Output: []

Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

*/
class Solution {
public:
    void solveRightView(TreeNode *root, vector<int>& rsv, int level)
    {
        if(!root)
            return;
        if(level == rsv.size())
            rsv.push_back(root->val);
        
        solveRightView(root->right,rsv,level+1);
        solveRightView(root->left,rsv,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rsv;
        solveRightView(root,rsv,0);
        return rsv;
    }
};
