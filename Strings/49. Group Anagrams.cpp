/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:
Input: strs = [""]
Output: [[""]]

Example 3:
Input: strs = ["a"]
Output: [["a"]]
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> word_map = {};
        vector<vector<string>> ans;
        int id = 0,row;
        for(auto word : strs)
        {
            char char_map[27];
            memset(char_map,48,sizeof(char_map));
            char_map[26] = '\0';
            int n = word.length();
            for(int i =0 ; i<n; i++)
                char_map[word[i]-97]++;
            string str_map(char_map);
            if(word_map.find(str_map) != word_map.end())
            {
                row = word_map[str_map];
                ans[row].push_back(word);
            }
            else
            {
                word_map[str_map] = id++;
                vector<string> string_row;
                string_row.push_back(word);
                ans.push_back(string_row);
            }
        }
        return ans;
        
    }
};
