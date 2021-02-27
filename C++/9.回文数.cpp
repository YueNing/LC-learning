/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        string str = to_string(x);
        int size = str.size();
        int start, end;
        if (size % 2 == 0) {
            start = size / 2 - 1;
            end = size / 2;
            if (str[start] != str[end]) {
                return false;
            }
            while (start > 0 && end < size - 1) {
                if (str[start - 1] == str[end + 1]) {
                    start--;
                    end++;
                }
                else {
                    return false;
                }
            }
        }
        else {
            start = size / 2;
            end = start;
            while (start > 0 && end < size - 1) {
                if (str[start - 1] == str[end + 1]) {
                    start--;
                    end++;
                }
                else {
                    return false;
                }
            }            
        }
        return true;
    }
};

// class Solution {
// public:
//     bool isPalindrome(int x) {
//         // 特殊情况：
//         // 如上所述，当 x < 0 时，x 不是回文数。
//         // 同样地，如果数字的最后一位是 0，为了使该数字为回文，
//         // 则其第一位数字也应该是 0
//         // 只有 0 满足这一属性
//         if (x < 0 || (x % 10 == 0 && x != 0)) {
//             return false;
//         }

//         int revertedNumber = 0;
//         while (x > revertedNumber) {
//             revertedNumber = revertedNumber * 10 + x % 10;
//             x /= 10;
//         }

//         // 当数字长度为奇数时，我们可以通过 revertedNumber/10 去除处于中位的数字。
//         // 例如，当输入为 12321 时，在 while 循环的末尾我们可以得到 x = 12，revertedNumber = 123，
//         // 由于处于中位的数字不影响回文（它总是与自己相等），所以我们可以简单地将其去除。
//         return x == revertedNumber || x == revertedNumber / 10;
//     }
// };

// @lc code=end

