class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) % 2:
            return False
        parenthesesPartner = {
            '{':'}',
            '(':')',
            '[':']'
        }
        stack = []
        for c in s:
            if c in parenthesesPartner:
                stack.append(parenthesesPartner[c])
            elif stack and c == stack[-1]:
                stack.pop()
            else:
                return False
        
        return not stack