/*
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.
The replacement must be in place and use only constant extra memory.
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums)
    {
        int n = nums.size(), i, mini, toSwap, temp;
        if(n == 0 or n == 1)
            return;
        i = n-1;
        while(i>0 and nums[i-1] >= nums[i--]);
        if(i == 0 and nums[i] > nums[i+1])
            i--;
        if(i == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        toSwap = i;
        mini = ++i;
        while(++i < n)
        {
            if(nums[i] > nums[toSwap] and nums[i] <= nums[mini])
                mini = i;
        }
        temp = nums[mini];
        nums[mini] = nums[toSwap];
        nums[toSwap] = temp;
        reverse(nums.begin() + toSwap + 1, nums.end());
    }
};
