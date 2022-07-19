/*
Given a binary tree, print the bottom view from left to right.
A node is included in bottom view if it can be seen when we look at the tree from bottom.

                      20
                    /    \
                  8       22
                /   \        \
              5      3       25
                    /   \      
                  10    14

For the above tree, the bottom view is 5 10 3 14 25.
If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal. For example, in the below diagram, 3 and 4 are both the bottommost nodes at horizontal distance 0, we need to print 4.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \      
                 10       14

For the above tree the output should be 5 10 4 14 25.

*/
class Solution {
  public:
    vector <int> bottomView(Node *root) {
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
                nodemap[index-1] = temp->left->data;
            }
            if(temp->right)
            {
                Q.push(make_pair(temp->right,index+1));
                nodemap[index+1] = temp->right->data;
            }
            Q.pop();
        }
        for(auto ele: nodemap)
            ans.push_back(ele.second);
        return ans;
    }
};
