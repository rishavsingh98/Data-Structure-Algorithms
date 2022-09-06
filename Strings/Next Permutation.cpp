/*
Implement the next permutation, which rearranges the list of numbers into Lexicographically next greater permutation of list of numbers. If such arrangement is not possible, it must be rearranged to the lowest possible order i.e. sorted in an ascending order. You are given an list of numbers arr[ ] of size N.

Example 1:
Input: N = 6
arr = {1, 2, 3, 6, 5, 4}
Output: {1, 2, 4, 3, 5, 6}
Explaination: The next permutation of the 
given array is {1, 2, 4, 3, 5, 6}.

*/
class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> nums){
        int  i, mini, toSwap, temp;
        if(n == 0 or n == 1)
            return nums;
        i = n-1;
        while(i>0 and nums[i-1] >= nums[i--]);
        if(i == 0 and nums[i] > nums[i+1])
            i--;
        if(i == -1)
        {
            reverse(nums.begin(), nums.end());
            return nums;
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
        return nums;
    }
};
