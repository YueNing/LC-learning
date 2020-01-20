class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        new = "1"
        for i in range(n-1):
            nums = new
            say = nums[0]
            count = 0
            new = ""
            for j in range(len(nums)):
                if nums[j] == say:
                    count = count + 1
                else:
                    new = new + str(count) + str(say)
                    count = 1
                    say = nums[j]
            new = new + str(count) + str(say)
        return new

test = Solution()
print(test.countAndSay(6))