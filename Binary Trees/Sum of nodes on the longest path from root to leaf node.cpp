/*
Given a binary tree of size N. Your task is to complete the function sumOfLongRootToLeafPath(), that find the sum of all nodes on the longest path from root to leaf node.
If two or more paths compete for the longest path, then the path having maximum sum of nodes is being considered.

Example 1:
Input: 
        4        
       / \       
      2   5      
     / \ / \     
    7  1 2  3    
      /
     6
Output: 13
Explanation:
        4        
       / \       
      2   5      
     / \ / \     
    7  1 2  3 
      /
     6

The highlighted nodes (4, 2, 1, 6) above are 
part of the longest root to leaf path having
sum = (4 + 2 + 1 + 6) = 13

Example 2:
Input: 
          1
        /   \
       2     3
      / \   / \
     4   5 6   7
Output: 11
*/
class Solution
{
public:
    pair<int,int> sumPath = make_pair(0,INT_MIN);
    void sumofPathRec(Node *root,int pathLen, int sum)
    {
        if(!root)
            return;
        else if(!root->left and !root->right and sumPath.second <= pathLen)
        {
           sumPath.first = sum + root->data;
           sumPath.second = pathLen;
           return;
        }
        sumofPathRec(root->left, pathLen + 1, sum + root->data);
        sumofPathRec(root->right, pathLen + 1, sum + root->data);
        return;
        
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        sumofPathRec(root,1,0);
        return sumPath.first;
    }
};
