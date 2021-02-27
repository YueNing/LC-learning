/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */

// @lc code=start
class Solution {
public:
    vector<int> res;
    vector<int> prev;
    vector<int> grayCode(int n) {
        unordered_map<int, int> visited;
        this->prev = vector<int>(n, 0);
        res.push_back(0);
        visited.insert({0, 1});
        int val = 0;
        backtracking(n, val, visited);
        return res;
    }
    void backtracking(int n, int& val, unordered_map<int, int>& visited) {
        for (int i = 0; i < n; i++) {
            prev[i] ^= 1;
            val += (prev[i] == 1 ? pow(2, i) : - pow(2, i));
            if (visited.count(val)) {
                val -= (prev[i] == 1 ? pow(2, i) : - pow(2, i));
                prev[i] ^= 1;
                continue;
            }
            else {
                visited.insert({val, 1});
                res.push_back(val);
                backtracking(n, val, visited);
            }
        }
    }
};
// @lc code=end

