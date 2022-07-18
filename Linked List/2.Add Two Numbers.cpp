/* 
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 
Constraints:
1. The number of nodes in each linked list is in the range [1, 100].
2. 0 <= Node.val <= 9
3. It is guaranteed that the list represents a number that does not have leading zeros.

*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         ListNode *head = l1;
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        ListNode *newNode = new(ListNode), *it1 = l1, *it2 = l2,*temp;
        int sum,carry = 0;
        temp = it1;
        while(it1 and it2)
        {
            sum = it1->val + it2->val + carry;
            if(sum>9)
            {
                it1->val = sum%10;
                carry = 1;
            }
            else
            {
                carry = 0;
                it1->val = sum;
            }
            it1 = it1->next;
            if(it1)
                temp = it1;
            it2 = it2->next;
        }
        if(it1)
        {
            while(it1)
            {
                sum = it1->val + carry;
                if(sum>9)
                {
                    it1->val = sum%10;
                    carry = 1;
                }
                else
                {
                    carry = 0;
                    it1->val = sum;
                }
                it1 = it1->next;
                if(it1)
                    temp = it1;
            }
        }
        if(it2)
        {
            temp->next = it2;
            it1 = it2;
            temp = it1;
            while(it1)
            {
                sum = it1->val + carry;
                if(sum>9)
                {
                    it1->val = sum%10;
                    carry = 1;
                }
                else
                {
                    carry = 0;
                    it1->val = sum;
                }
                it1 = it1->next;
                if(it1)
                    temp = it1;
            }
        }
        if(carry)
        {
            newNode->val = carry;
            newNode->next = NULL;
            temp->next = newNode;
        }
        return l1;
    }
};
