/*
 * @lc app=leetcode.cn id=1553 lang=cpp
 *
 * [1553] 吃掉 N 个橘子的最少天数
 */

// @lc code=start
class Solution {
public:
    unordered_map<int,int> m;
    int minDays(int n) {
        if(n==0)return 0;//出口
        if(m.count(n))return m[n];//dp
        return m[n]=min({1+n%2+minDays(n/2),1+n%3+minDays(n/3),n});//分别对应/3,/2,-1.
    }
};
// @lc code=end

