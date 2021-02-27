/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> cur;
        int size = path.size();
        string tmp;
        tmp.push_back('/');
        for (int i = 0; i < size - 1; i++) {
            // if (tmp.empty() && path[i] == '/') {
            //     tmp.push_back('/');
            //     continue;
            // }
            if (tmp == "/.." && path[i] == '/') {
                if (!cur.empty()) {
                    cur.pop();
                }
                tmp.clear();
                tmp.push_back('/');
                continue;
            }
            if (tmp == "/." && path[i] =='/') {
                tmp.clear();
                tmp.push_back('/');
                continue;
            }
            if (tmp == "/" && path[i] == '/') {
                continue;
            }
            else if (path[i] == '/') {
                cur.push(tmp);
                tmp.clear();
                tmp.push_back('/');
                continue;
            }
            else {
                tmp.push_back(path[i]);
            }
        }
        if ((tmp == "/." && path[size - 1] == '.') || (tmp == "/.." && path[size - 1] == '/')) {
            if (!cur.empty()) {
                cur.pop();
            }            
        }
        else if ((tmp == "/" && path[size - 1] == '.') || (tmp == "/." && path[size - 1] == '/')) {}
        else if (path[size - 1] != '/') {
                tmp.push_back(path[size - 1]);
                cur.push(tmp);
        }
        else if (tmp == "/" && path[size - 1] == '/') {}
        else if (path[size - 1] == '/') {
            cur.push(tmp);           
        }
        string res;
        if (cur.empty()) {
            return "/";
        }
        while (!cur.empty()) {
            res = cur.top() + res;
            cur.pop();
        }
        return res;
    }
};
// @lc code=end

