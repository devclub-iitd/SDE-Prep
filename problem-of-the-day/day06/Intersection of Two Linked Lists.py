# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution(object):
    def getLength(self, head):
        """
        :type head: ListNode
        :rtype: int
        """
        cnt = 0
        temp = head
        while temp:
            cnt += 1
            temp = temp.next
        return cnt

    def getIntersectionNode(self, headA, headB):
        """
        :type headA: ListNode
        :type headB: ListNode
        :rtype: ListNode
        """
        len1 = self.getLength(headA)
        len2 = self.getLength(headB)
        d = 0
        if len1 > len2:
            d = len1 - len2
            ptr1 = headA
            ptr2 = headB
        else:
            d = len2 - len1
            ptr1 = headB
            ptr2 = headA
        
        while d:
            ptr1 = ptr1.next
            d -= 1
            if ptr1 is None:
                return None
        
        while ptr1 and ptr2:
            if ptr1 == ptr2:
                return ptr1
            ptr1 = ptr1.next
            ptr2 = ptr2.next
        
        return None
