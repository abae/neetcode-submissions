class Solution:
    def isValid(self, s: str) -> bool:
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
        
        if not stack:
            return True
        return False