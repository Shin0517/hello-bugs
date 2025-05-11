class Solution(object):
    def isPalindrome(self, x):
        if x < 0:
            return False

        inputNum = x
        newNum = 0
        while x > 0:
            digit = x % 10
            newNum = newNum * 10 + digit
            x = x // 10
        return newNum == inputNum