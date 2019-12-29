class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        lib = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000,
        }
        result = 0
        skip = False
        for i in range(len(s)-1):
            if not skip:
                if lib.get(s[i]) < lib.get(s[i+1]):
                    result = result + lib.get(s[i+1]) - lib.get(s[i])
                    skip = True
                else:
                    result = result + lib.get(s[i])
                    skip = False
            else:
                skip = False
        if not skip:
            result = result + lib.get(s[-1])
        return result


