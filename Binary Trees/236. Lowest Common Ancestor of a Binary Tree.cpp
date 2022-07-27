/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.

Example 2:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

Example 3:
Input: root = [1,2], p = 1, q = 2
Output: 1
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return root;
        stack<pair<TreeNode*,TreeNode*>> postOrd;
        postOrd.push(make_pair(root,root));
        bool pFound = false, qFound = false;
        pair<TreeNode*,TreeNode*> temp;
        TreeNode *pPar = NULL, *qPar = NULL, *lastPop = NULL;
        while(!postOrd.empty())
        {
            //PostOrder Traversal anc check is root is p or q
            temp = postOrd.top();
            
            if(!pFound and temp.first == p)
            {
                pFound = true;
                pPar = temp.first;
            }
            if(!qFound and temp.first == q)
            {
                qFound = true;
                qPar = temp.first;
            }
            
            //check if stack top is leaf or is already visited
            if((!temp.first->right and !temp.first->left) or (temp.first->right and lastPop == temp.first->right) 
               or (temp.first->left and lastPop == temp.first->left))
            {
                //if poped node is pPar or qPar change parent to nodes parent
                if(pFound and pPar == temp.first)
                    pPar = temp.second;
                if(qFound and qPar == temp.first)
                    qPar = temp.second;
                
                lastPop = temp.first;
                postOrd.pop();
            }
            
            
            //Push Right and Left noes to stack
            else 
            {
                if(temp.first->right)
                    postOrd.push(make_pair(temp.first->right, temp.first));
                if(temp.first->left)
                    postOrd.push(make_pair(temp.first->left, temp.first));
            }
            
            //check if there parents are equal
            if(pPar and qPar and pPar == qPar)
                return pPar;
            
        }
        return pPar;
    }
};
