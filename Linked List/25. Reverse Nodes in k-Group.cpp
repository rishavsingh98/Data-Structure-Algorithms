/* 
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Example 2:
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
 

Constraints:
The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000

*/
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
       
        if(!head || !head->next)
            return head;
        ListNode *nextHead = head->next, *prev = head,*nxt= head->next;
        int i;
        for(i = 1; i <= k; i++)
        {
            prev = prev->next;
            if(!prev)
                break;
        }
        if(i<k)
            return head;
        prev = head;
        for(i = 0; i < k-1; i++)
        {
            nxt = nxt->next;
            nextHead->next = prev;
            prev = nextHead;
            nextHead = nxt;
            if(!nxt)
                break;
        }
        head->next = reverseKGroup(nextHead,k);
        return prev;
    }
};