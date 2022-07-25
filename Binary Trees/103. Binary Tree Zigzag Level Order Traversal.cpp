/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []

Constraints:
The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
*/

//Using QUEUE and REVERSE
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zigzag;
        if(!root)
            return zigzag;
        queue<TreeNode*> Q;
        Q.push(root);
        TreeNode* temp = NULL;
        int pushed = 1, toPop = 0, direction = 0; //direction = 0 : left to right; direction = 1 : right to left; 
        while(!Q.empty())
        {
            vector<int> row;
            toPop = pushed;
            pushed = 0;
            while(toPop--)
            {
                temp = Q.front();
                row.push_back(temp->val);
                Q.pop();
                if(temp->left)
                {
                    Q.push(temp->left);
                    pushed++;
                }
                if(temp->right)
                {
                    Q.push(temp->right);
                    pushed++;
                }
            }
            if(direction)
            {
                reverse(row.begin(),row.end());
                zigzag.push_back(row);
                direction = 0;
            }
            else
            {
                zigzag.push_back(row);
                direction = 1;
            }
        }
        return zigzag;
    }
};

//WITHOUT REVERSE function and Using DEQUE
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zigzag;
        if(!root)
            return zigzag;
        deque<TreeNode*> Q;
        Q.push_back(root);
        TreeNode* temp = NULL;
        int pushed = 1, toPop = 0;
        bool direction = true; //direction = true : left to right; direction = false : right to left; 
        while(!Q.empty())
        {
            vector<int> row;
            toPop = pushed;
            pushed = 0;
            deque<TreeNode*> dQ;
            while(toPop--)
            {
                temp = Q.front();
                row.push_back(temp->val);
                Q.pop_front();
                if(direction)    
                {
                    if(temp->left)
                    {
                        dQ.push_front(temp->left);
                        pushed++;
                    }
                    if(temp->right)
                    {
                        dQ.push_front(temp->right);
                        pushed++;
                    }
                }
                else
                {
                   if(temp->right)
                    {
                        dQ.push_front(temp->right);
                        pushed++;
                    }
                    if(temp->left)
                    {
                        dQ.push_front(temp->left);
                        pushed++;
                    }
                }
            }
            direction = !direction;
            Q.insert(Q.end(),dQ.begin(),dQ.end());
            zigzag.push_back(row);
        }
        return zigzag;
    }
};
