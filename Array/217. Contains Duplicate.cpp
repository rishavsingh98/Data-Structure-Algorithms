/* 
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:
Input: nums = [1,2,3,1]
Output: true

Example 2:
Input: nums = [1,2,3,4]
Output: false

Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true

Constraints:
1 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> dict = {};
        for(auto i: nums)
        {
            if (dict.find(i) == dict.end())
                dict.insert({i,1});                
            else
                dict[i] += 1;
        }
        std::unordered_map<int, int>::iterator it = dict.begin();
        while (it != dict.end())
        {   
            if (dict[it->first] >=2)
                return true;
            it++;        
        }    
     return false;
    }
    
};
