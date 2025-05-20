class Solution(object):
    climbed = {}

    def climbStairs(self, n):
        if n == 0 or n == 1:
            return 1
        if n not in self.climbed:
            self.climbed[n] = self.climbStairs(n - 1) + self.climbStairs(n - 2)
        return self.climbed[n]