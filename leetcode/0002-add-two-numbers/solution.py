class Solution(object):
    def addTwoNumbers(self, l1, l2):
        dummy = ListNode()
        res = dummy

        carry = 0
        while l1 or l2 or carry:
            num = carry 
            if l1:
                num += l1.val
                l1 = l1.next
            if l2:
                num += l2.val
                l2 = l2.next
            
            digit = num % 10
            carry = num // 10
            dummy.next = ListNode(digit)
            dummy = dummy.next
        
        return res.next
            
