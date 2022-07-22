/*
Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

       1
    /     \
   2       3
  /  \    /   \
4    5  6   7

Top view will be: 4 2 1 3 7
Note: Return nodes from leftmost node to rightmost node.

Example 1:
Input:
      1
   /    \
  2      3
Output: 2 1 3

Example 2:
Input:
       10
    /      \
  20        30
 /   \    /    \
40   60  90    100
Output: 40 20 10 30 100

*/
class Solution
{
    public:
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        map<int,int> nodemap; //index,value
        queue<pair<Node*,int>>Q; //Queue contains the nodes to be trasversed along with the key in map
        Q.push(make_pair(root,0));
        nodemap[0] = root->data;
        int index;
        Node *temp;
        while(!Q.empty())
        {
            temp = Q.front().first;
            index = Q.front().second;
            if(temp->left)
            {
                Q.push(make_pair(temp->left,index-1));
                if(nodemap.find(index-1)==nodemap.end())
                    nodemap[index-1] = temp->left->data;
            }
            if(temp->right)
            {
                Q.push(make_pair(temp->right,index+1));
                if(nodemap.find(index+1)==nodemap.end())
                    nodemap[index+1] = temp->right->data;
            }
            Q.pop();
        }
        for(auto ele: nodemap)
            ans.push_back(ele.second);
        return ans;
    }

};
