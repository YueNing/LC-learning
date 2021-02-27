/*
 * @lc app=leetcode.cn id=149 lang=cpp
 *
 * [149] 直线上最多的点数
 */

// @lc code=start
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int size = points.size();
        int max_count = 1;
        if (size <= 2){
            return size;
        }
        for (int i = 0; i < size - 2; i++){
            int duplicates = 0;
            int count = 0;
            unordered_map<string, int> map;
            for (int j = i + 1; j < size; j++){
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]){
                    duplicates++;
                    continue;
                }
                else if (points[i][0] == points[j][0]){
                    map["LONG_LONG_MAX"] = map["LONG_LONG_MAX"] + 1;
                    count = max(count, map["LONG_LONG_MAX"]);
                }
                else {
                    int dy = points[i][1] - points[j][1];
                    int dx = points[i][0] - points[j][0];
                    int gcd1 = gcd(dy, dx);
                    dy = dy / gcd1;
                    dx = dx / gcd1;
                    string key = std::to_string(dx) + "@" + std::to_string(dy);
                    map[key] = map[key] + 1;
                    count = max(count, map[key]);
                }               
            }
            max_count = max(max_count, count + duplicates + 1);
        }
        return max_count;
    }
private:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
};
// @lc code=end

