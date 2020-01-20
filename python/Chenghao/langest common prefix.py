class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """

        prefix = ""
        if len(strs) == 0: return prefix

        for i in range(len(min(strs))):
            c = strs[0][i]
            if all(a[i] == c for a in strs):
                prefix += c
            else:
                break
        return prefix


test = Solution()
strs = ["flower","flow","flight"]
print(test.longestCommonPrefix(strs))
        # if not strs:
        #     result = ""
        # else:
        #     result = strs[0]
        #     for j in range(1, len(strs)):
        #         i = 0
        #         while i in range(min(len(result), len(strs[j]))):
        #             if result[i] != strs[j][i]:
        #                 break
        #             i = i + 1
        #         result = result[0:i]
        # return result
