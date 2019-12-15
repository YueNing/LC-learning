#
# @lc app=leetcode.cn id=7 lang=python3
#
# [7] 整数反转
#

# @lc code=start
class Solution:
    def reverse(self, x: int) -> int:
        s = (x > 0) - (x < 0) 
        r = int(str(abs(x))[::-1])
        return s*r (r<2**31)
        
# @lc code=end

