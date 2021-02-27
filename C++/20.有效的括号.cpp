/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0){
            return false;
        }
        unordered_map<char, char> pairs = {
            {'{', '}'},
            {'[', ']'},
            {'(', ')'}};
        stack<char> tmp;
        for (char ch: s){
            if (pairs.count(ch)){
                tmp.push(ch);
            }
            else if (tmp.empty()){
                return false;
            }
            else if (ch == '}'){
                if (tmp.top() != '{'){
                    return false;
                }
                else {
                    tmp.pop();
                }
            }
            else if (ch == ']'){
                if (tmp.top() != '['){
                    return false;
                }
                else {
                    tmp.pop();
                }
            }            
            else if (ch == ')'){
                if (tmp.top() != '('){
                    return false;
                }
                else {
                    tmp.pop();
                }
            }
            else
                return false;
        }
        if (tmp.empty()){
            return true;}
        else
            return false;
    }
};
// @lc code=end

