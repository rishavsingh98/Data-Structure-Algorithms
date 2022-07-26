/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).
 

Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

Constraints:
nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-10^6 <= nums1[i], nums2[i] <= 10^6
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();

        //Swaping small size vector to n1
        if(n2 < n1)
        {
            swap(nums1, nums2);
            swap(n1,n2);
        }
        int left = 0, right = n1, mid1, mid2, n = n1 + n2, n1left, n2left, n1right, n2right;
        
        while(left<=right)
        {
            mid1 = left + (right-left) / 2;
            mid2 = (n + 1) / 2 - mid1;
            
            n1left =  mid1 > 0 ? nums1[mid1 - 1] : INT_MIN;
            
            n1right = mid1 < n1 ? nums1[mid1] : INT_MAX;
           
            n2left =  mid2 > 0 ? nums2[mid2 - 1] : INT_MIN;
            
            n2right = mid2 < n2 ? nums2[mid2] : INT_MAX;
            
            if(n1left <= n2right and n2left <= n1right)
            {
                //check odd or even
                if(n % 2)
                    return max(n1left,n2left);
                else
                    return float(max(n1left,n2left) + min(n1right,n2right)) / 2.0;
            }
            else if(n1left > n2right)
                right = mid1 - 1;
            else
                left = mid1 + 1;
        }
        return 0.0;
    }
};
