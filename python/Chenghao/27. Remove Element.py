class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        pre = 0
        for cur in range(len(nums)):
            if nums[cur] != val:
                nums[pre] = nums[cur]
                pre = pre + 1
        return pre