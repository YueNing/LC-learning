class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        left = ["(", "{", "["]
        right = [")", "}", "]"]
        stack = []

        for x in s:

            if x in left:
                stack.append(x)

            else:

                if len(stack) == 0:
                    return False
                else:
                    l = stack.pop()

                    for k in range(3):
                        if l == left[k] and x != right[k]:
                            return False

        return len(stack) == 0

        # s = list(s)
        # lib = {
        #     "(": ")",
        #     "[": "]",
        #     "{": "}"
        # }
        # stack = []
        # for i in range(len(s)):
        #     if s[i] in ["(", "[", "{"]:
        #         stack.append(s[i])
        #     elif not stack:
        #         return False
        #     else:
        #         l = stack.pop()
        #         if s[i] != lib.get(l):
        #             return False
        # if not stack:
        #     return True

        # s = list(s)
        # lib = {
        #     "(": ")",
        #     "[": "]",
        #     "{": "}"
        # }
        # i = 0
        # while i in range(len(s)-1):
        #     if len(s) == 1:
        #         result = False
        #         break
        #     elif lib.get(s[i]) == s[i+1]:
        #         del s[i:i+2]
        #         i = 0
        #     else:
        #         i = i + 1
        # if s:
        #     result = False
        # else:
        #     result = True
        # return result


