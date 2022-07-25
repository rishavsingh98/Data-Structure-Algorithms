/* 
Given the root of an n-ary tree, return the postorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)

Example 1:
Input: root = [1,null,3,2,4,null,5,6]
Output: [5,6,3,2,4,1]

Example 2:
Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [2,6,14,11,7,3,12,8,4,13,9,10,5,1]

Constraints:
The number of nodes in the tree is in the range [0, 10^4].
0 <= Node.val <= 10^4
The height of the n-ary tree is less than or equal to 1000.

*/
class Solution {
public:
    vector<int> postorder(Node* root) {
        stack<Node*> postOrd;
        Node *lastPop = NULL, *temp = NULL;
        postOrd.push(root);
        vector<int> seq;
        if(!root)
            return seq;
        int nchild = 0;
        while(!postOrd.empty())
        {
            temp = postOrd.top();
            nchild = temp->children.size();
            if(nchild == 0 or lastPop == temp->children[nchild-1])
            {
                seq.push_back(temp->val);
                postOrd.pop();
                lastPop = temp;
            }
            else
                while(nchild>0)
                    postOrd.push(temp->children[nchild-- - 1]);
        }
        return seq;
    }
};
