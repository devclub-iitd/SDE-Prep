class Solution(object):
    def orderlyQueue(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        # If k == 1, we can only rotate the string
        if k == 1:
            ans = s
            n = len(s)
            s += s
            for i in range(n):
                ans = min(ans, s[i:i + n])
            return ans
        # If k > 1, we can sort the string
        else:
            return ''.join(sorted(s))
