class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        pre = 0
        cur = 1
        while cur in range(len(nums)):
            if nums[cur] == nums[pre]:
                cur = cur + 1
            else:
                pre = pre + 1
                nums[pre] = nums[cur]
                cur = cur + 1
        pre = pre + 1
        return pre