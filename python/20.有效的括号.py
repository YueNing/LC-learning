#
# @lc app=leetcode.cn id=20 lang=python3
#
# [20] 有效的括号
# 

# @lc code=
class Solution:
    def isValid(self, s):
        stack, match = [], {')': '(', ']': '[', '}': '{'}
        for ch in s:
            if ch in match:
                if not (stack and stack.pop() == match[ch]):
                    return False
            else:
                stack.append(ch)
        return not stack

# @lc code=end
