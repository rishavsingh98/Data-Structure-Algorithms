/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]

Constraints:
The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz

*/
//RECURSIVE NAIVE Approach : 2 Pass in Recursion
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int& n) {
        if(!head)
            return head;
        head->next = removeNthFromEnd(head->next,n);
        n--;
        if(n == 0)
            return head->next;
        return head;
    }
};
//Iterative 2 Pointer 1 pass solution
//In order to solve this problem in only one pass and O(1) extra space, however, we would need to find a way to both reach
//the end of the list with one pointer and also reach the n'th node from the end simultaneously with a second pointer.

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int& n) {
        if(!head)
            return head;
        ListNode *fast = head, *slow = head;
        for(int i = 0; i < n; i++)
            fast = fast->next;
        if(!fast)
            return head->next;
        while(fast->next) fast = fast->next, slow = slow->next;
        slow->next = slow->next->next;
        return head;
    }
};
