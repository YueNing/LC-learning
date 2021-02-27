/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */

// @lc code=start
// class Solution {
// public:
//     int leastInterval(vector<char>& tasks, int n) {
//         vector<int>cnt(26,0);
//         for(auto type : tasks)  // 桶排序思想
//             cnt[type-'A']++;
//         int cnt_max = 0, equal_cnt_max = -1;  // equal_cnt_max初值为-1是因为后面的循环会多算一次
//         for(auto i: cnt) cnt_max = max(i, cnt_max);
//         for(int i = 25; i>=0; --i) 
//             if(cnt_max == cnt[i])
//                 ++equal_cnt_max;  // 统计出现次数与最大出现次数相同的任务总个数
//         int ans = max((cnt_max-1)*n+cnt_max+equal_cnt_max, (int)tasks.size());
//         return ans;
//     }
// };


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> letters(26, 0);
        for (char task: tasks){
            letters[task - 'A']++;
        }
        int max_count = 0;
        int same_max = 0;
        for (int letter: letters){
            max_count = max(letter, max_count);
        }
        for (int letter: letters){
            if (max_count == letter){
                same_max++;
            }
        }
        int res = max((n + 1) * (max_count - 1) + same_max, (int)tasks.size());
        return res;
    }
};
// @lc code=end

