class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        pre = 0
        for cur in range(len(nums)):
            if nums[pre] != nums[cur]:
                pre = pre + 1
                nums[pre] = nums[cur]
                cur = cur + 1
        pre = pre + 1
        return pre