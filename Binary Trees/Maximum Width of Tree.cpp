/*
Given a Binary Tree, find the maximum width of it. Maximum width is defined as the maximum number of nodes at any level.
For example, the maximum width of the following tree is 4 as there are 4 nodes at the 3rd level.

          1
       /     \
     2        3
   /   \    /  \
  4    5   6    7
    \
      8

Example 1:
Input:
       1
     /    \
    2      3
Output: 2
On the first level there is only
one node 1
On the second level there are
two nodes 2, 3 clearly it is the 
maximum number of nodes at any level

Example 2:
Input:
        10
      /     \
    20      30
   /    \
  40    60
Output: 2
There is one node on level 1(10)
There is two node on level 2(20, 30)
There is two node on level 3(40, 60)
Hence the answer is 2
*/
class Solution {
  public:
    int getMaxWidth(Node* root)
    {
        if(!root)
            return 0;
        int maxWidth = 1;
        queue<Node*> Q;
        Q.push(root);
        while(!Q.empty())
        {
            int currWidth = Q.size();
            maxWidth = max(maxWidth, currWidth);
            while(currWidth--)
            {
                Node *tempNode = Q.front();
                if(tempNode->left)
                    Q.push(tempNode->left);
                if(tempNode->right)
                    Q.push(tempNode->right);
                Q.pop();
            }
        }
        return maxWidth;
    }
};
