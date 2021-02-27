/*
 * @lc app=leetcode.cn id=957 lang=cpp
 *
 * [957] N 天后的牢房
 */

// @lc code=start
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<int> tmp(cells);//上一个
        vector<int> cur(cells);//当前容器
        vector<vector<int>> arr;//用于记录每一天的变化
        arr.push_back(cells);
        int sumDay = 0;//如果有周期，则用于记录周期数
        for(int day = 1; day <= N; day++){
            for(int i = 1; i < 7; i++){
                if(tmp[i-1] == tmp[i+1])
                cur[i] = 1;
                else
                cur[i] = 0;
            }
            cur[0] = 0;
            cur[7] = 0; 
            tmp = cur;
            sumDay++;   
            arr.push_back(cur);
            if(cur == arr[1] && day != 1)
            {
                int t = N % (sumDay-1);
                if(t == 0)//为了防止特殊用例
                return arr[sumDay-1];
                return arr[t];
            }
        }
        return arr.back();
    }
};
// @lc code=end

