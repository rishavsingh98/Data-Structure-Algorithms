/*
Given two BSTs, return elements of both BSTs in sorted form.
Example 1:
Input:
BST1:
       5
     /   \
    3     6
   / \
  2   4  
BST2:
        2
      /   \
     1     3
            \
             7
            /
           6
Output: 1 2 2 3 3 4 5 6 6 7
Explanation: 
After merging and sorting the
two BST we get 1 2 2 3 3 4 5 6 6 7.
*/
class Solution
{
    public:
    
    void getInorder(Node* root, vector<Node*>& inorder)
    {
        if(!root)
            return;
        getInorder(root->left, inorder);
        inorder.push_back(root);
        getInorder(root->right, inorder);
        return;
    }
    
    vector<int> combine(vector<Node*> arr1, vector<Node*> arr2)
    {
        int n = arr1.size(), m = arr2.size(), i = 0, j = 0, k = 0;
        vector<int> ans(n+m, -1);
        
        while(i < n and j < m)
        {
            if(arr1[i]->data < arr2[j]->data)
                ans[k++] = arr1[i++]->data;
            else
                ans[k++] = arr2[j++]->data;
        }
        
        while(i < n)
            ans[k++] = arr1[i++]->data;
            
        while(j < m)
            ans[k++] = arr2[j++]->data;
            
        return ans;
    }
    
    vector<int> merge(Node *root1, Node *root2)
    {
        vector<Node*> inorder1, inorder2;
	    
	    getInorder(root1, inorder1);
	    getInorder(root2, inorder2);
	    
	    return combine(inorder1, inorder2);
    }
};
