class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False
        else:
            b = int(str(x)[::-1])
            if b == x:
                return True
            else:
                return False
