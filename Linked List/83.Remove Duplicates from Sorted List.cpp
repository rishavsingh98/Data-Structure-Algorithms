/* 
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.


Example 1:
Input: head = [1,1,2]
Output: [1,2]

Example 2:
Input: head = [1,1,2,3,3]
Output: [1,2,3] 

Constraints:
The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.

*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head;
        int x=head->val;
        ListNode *temp=head,*temp1=head->next;
        while(temp1 != NULL)
        {
            while(temp1!=NULL and temp->val == temp1->val)
                temp1 = temp1->next;
            temp->next = temp1;
            if(temp != NULL) temp = temp->next;
            if(temp1 != NULL) temp1 = temp1->next;
        }
        cout<<endl;
        return head;
    }
};
