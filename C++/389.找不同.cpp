/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */

// @lc code=start
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> sMap;
        for (auto i: s){
            sMap[i]++;
        }
        for (auto i: t){
            if (sMap.count(i) && sMap[i] !=0){
                sMap[i]--;
            }
            else{
                return i;
            }
        }
        return ' ';
    }
};
// @lc code=end

