/*
Given two sorted arrays arr1 and arr2 of size N and M respectively and an element K. The task is to find the element that would be at the k’th position of the final sorted array.
 
Example 1:
Input:
arr1[] = {2, 3, 6, 7, 9}
arr2[] = {1, 4, 8, 10}
k = 5
Output:
6
Explanation:
The final sorted array would be -
1, 2, 3, 4, 6, 7, 8, 9, 10
The 5th element of this array is 6.

Example 2:
Input:
arr1[] = {100, 112, 256, 349, 770}
arr2[] = {72, 86, 113, 119, 265, 445, 892}
k = 7
Output:
256
Explanation:
Final sorted array is - 72, 86, 100, 112,
113, 119, 256, 265, 349, 445, 770, 892
7th element of this array is 256.
*/
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n > m)
            return kthElement(arr2, arr1, m, n, k);
        
        //if m < k we need to take atleast some from arr1; so low = max(0, k-m)
        //if k < n, we cant make high bigger than no of elements to take. so high = min (n, k)
        int low = max(0, k-m), high = min(n, k);
        while(low <= high)
        {
            int count1 = (low + high) >> 1;
            int count2 = k - count1;
            int left1 = count1 == 0 ? INT_MIN : arr1[count1 - 1];
            int left2 = count2 == 0 ? INT_MIN : arr2[count2 - 1];
            int right1 = count1 == n ? INT_MAX : arr1[count1];
            int right2 = count2 == m ? INT_MAX : arr2[count2];
            
            if(left1 <= right2 and left2 <= right1)
                return max(left1, left2);
            
            else if(left1 > right2)
                high = count1 - 1;
            
            else
                low = count1 + 1;
        }
        return 1;
    }
};
