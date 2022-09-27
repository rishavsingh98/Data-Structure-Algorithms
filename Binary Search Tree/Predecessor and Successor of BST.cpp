/*
There is BST given with root node with key part as an integer only. You need to find the in-order successor and predecessor of a given key. If either predecessor or successor is not found, then set it to NULL.

Example:

Input:
2
6
50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R
65
6
50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R
100

Output:
60 70
80 -1
*/
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if(!root)
        return;
    if(root->key == key)
    {
        Node *temp = root;
        
        if(root->left)
        {
            pre = root->left;
            temp = pre;
            while(temp->right)
                temp = temp->right;
            if(temp)
                pre = temp;
        }
            
        if(root->right)
        {    
            suc = root->right;
            temp = suc;
            while(temp->left)
                temp = temp->left;
            if(temp)
                suc = temp;
        }
        
    }
    else if(key < root->key)
    {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
        return;
    }
    else
    {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
        return;
    }
}
