def twoSum(nums: list, target: int) -> list:
    length_num = len(nums)
    map = {}
    for a in range(length_num):
        if target - nums[a] in map:
            return map[target - nums[a]], a
        else:
            map[nums[a]] = a


k = [1, 5, 8, 13, 6, 15, 2]
f = twoSum(k, 19)
m = 2 ^ 31
print(m)
print(f)