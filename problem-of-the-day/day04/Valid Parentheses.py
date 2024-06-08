class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []

        for c in s:
            if c in '([{':
                stack.append(c)
            else:
                if len(stack) == 0:
                    return False
                cond1 = stack[-1] == '(' and c == ')'
                cond2 = stack[-1] == '{' and c == '}'
                cond3 = stack[-1] == '[' and c == ']'

                if cond1 or cond2 or cond3:
                    stack.pop()
                else:
                    return False
        return len(stack) == 0
