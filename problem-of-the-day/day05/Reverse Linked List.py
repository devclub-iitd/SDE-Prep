# Iterative
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head:
            return None
        n = head
        m = head.next
        while n and m:
            r = m.next
            m.next = n
            n = m
            m = r
        head.next = None
        return n


# Recursive
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head:
            return None
        elif not head.next:
            return ListNode(head.val)
        ans = self.reverseList(head.next)
        n = ans
        while n.next:
            n = n.next
        n.next = ListNode(head.val)
        return ans
