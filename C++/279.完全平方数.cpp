/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        int min_sqrt_n = floor(sqrt(n));
        queue<int> Queue;
        Queue.push(0);
        int step = 0;
        
        while(!Queue.empty()){
            step ++;
            int size = Queue.size();
            for(int i = 0; i < size; i++){
                int front = Queue.front();
                Queue.pop();
                for(int j = 1; j <= min_sqrt_n; j++){
                    int sum = front + pow(j, 2);
                    if(sum == n) return step;
                    if(sum > n) continue;
                    Queue.push(sum);
                }
            }
        }
        return -1;
    }
};

// @lc code=end

