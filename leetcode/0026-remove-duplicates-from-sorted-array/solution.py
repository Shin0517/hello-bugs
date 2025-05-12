class Solution(object):
    def removeDuplicates(self, nums):
        ref = sorted(set(nums))
        k = len(ref)
        for i in range(k):
            nums[i] = ref[i]
        return k