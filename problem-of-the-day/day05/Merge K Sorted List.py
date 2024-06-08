class Solution(object):
    def mergeKLists(self, lists):
        # Base cases: if the input list is empty or contains only one list
        if not lists:
            return None
        if len(lists) == 1:
            return lists[0]

        # Split the list into two halves
        mid = len(lists) // 2
        l, r = self.mergeKLists(lists[:mid]), self.mergeKLists(lists[mid:])

        # Merge the two halves
        return self.merge(l, r)
    
    def merge(self, l, r):
        # Initialize a dummy node to help with merging
        dummy = p = ListNode()
        
        # Merge the two lists
        while l and r:
            if l.val < r.val:
                p.next = l
                l = l.next
            else:
                p.next = r
                r = r.next
            p = p.next
        
        # Attach the remaining elements, if any
        p.next = l or r
        
        # Return the merged list, which starts at dummy.next
        return dummy.next