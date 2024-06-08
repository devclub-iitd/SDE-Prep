# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None





class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        slow = head
        fast = head
        start = head

        if head is None:
            return None

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if fast == slow:
                while slow != start:
                    slow = slow.next
                    start = start.next
                return slow

        return None
