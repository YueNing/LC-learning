/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */

// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = pattern.size();
        int m = s.size();
        int j = 0;
        int tmp;
        unordered_map<char, string> patternMap;
        unordered_map<string, char> sMap;
        for (int i = 0; i < n; ++i){
            if (j == m +1){
                return false;
            }
            char pattern_sub = pattern[i];
            tmp = j;
            while (s[j] !=' ' && j < m){
                j++;
            }
            j++;
            if (i == n-1 && j != m+1){
                return false;
            }            
            string string_sub = s.substr(tmp, j - tmp - 1);
            if (patternMap.count(pattern_sub)){
                if (patternMap[pattern_sub] != string_sub){
                    return false;
                }   
            }
            if (sMap.count(string_sub)){
                if (sMap[string_sub] != pattern_sub){
                    return false;
                }
            }
            else {
                patternMap[pattern_sub] = string_sub;
                sMap[string_sub] = pattern_sub;
            }
        }
        return true;
    }
};
// @lc code=end

