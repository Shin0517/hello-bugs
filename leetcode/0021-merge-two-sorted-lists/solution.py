class Solution(object):
    def mergeTwoLists(self, list1, list2):
        dummy = ListNode()
        current = dummy

        while list1 and list2:
            if list1.val > list2.val:
                current.next = list2
                list2 = list2.next
            else:
                current.next = list1
                list1 = list1.next
            
            current = current.next
        
        if list1:
            current.next = list1
        else:
            current.next = list2
        
        return dummy.next