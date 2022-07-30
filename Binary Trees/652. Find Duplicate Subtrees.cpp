/*
Given the root of a binary tree, return all duplicate subtrees.
For each kind of duplicate subtrees, you only need to return the root node of any one of them.
Two trees are duplicate if they have the same structure with the same node values.

Example 1:
Input: root = [1,2,3,4,null,2,4,null,null,4]
Output: [[2,4],[4]]

Example 2:
Input: root = [2,1,1]
Output: [[1]]

Example 3:
Input: root = [2,2,2,3,null,3,null]
Output: [[2,3],[3]]
 
Constraints:
The number of the nodes in the tree will be in the range [1, 10^4]
-200 <= Node.val <= 200

*/
class Solution {
    string serialize(TreeNode* root, vector<TreeNode*>& dupes, unordered_map<string,int>& hashSubtree)
    {
        string serial;
        if(!root)
            return "";
        else if(!root->left and !root->right)
            serial = to_string(root->val); 
        else
            serial = to_string(root->val) + "(" + serialize(root->left,dupes,hashSubtree) + ")" + "(" + serialize(root->right,dupes,hashSubtree) + ")";
       
        hashSubtree[serial] += 1;
        
        if(hashSubtree[serial] == 2)
                dupes.push_back(root);
        
        return serial;
    }
    
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
    {
        vector<TreeNode*> dupes;
        unordered_map<string,int> hashSubtree = {};
        serialize(root, dupes, hashSubtree);
        return dupes;
    }
};
