class Solution(object):
    def isValid(self, s):
        parenthesesStack = []
        parenthesesPairs = {")": "(", "]":"[", "}":"{"}
        
        for char in s:
            if char not in parenthesesPairs:
                parenthesesStack.append(char)
            elif not parenthesesStack or parenthesesStack[-1] != parenthesesPairs[char]:
                return False
            else:
                parenthesesStack.pop()
                
        return len(parenthesesStack) == 0
