class Solution(object):
    def twoSum(self, nums, target):
        numDict = {}
        for i, num in enumerate(nums):
            complement = target - num
            if complement in numDict:
                return [numDict[complement], i]
            else:
                numDict[num] = i