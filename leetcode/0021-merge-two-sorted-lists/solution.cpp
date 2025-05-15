class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            ListNode* dummy = new ListNode(0);
            ListNode* current = dummy;
    
            while (list1 && list2) {
                if (list1 -> val > list2 -> val) {
                    current -> next = list2;
                    list2 = list2 -> next;
                } else {
                    current -> next = list1;
                    list1 = list1 -> next;
                }
                current = current -> next;
            }
            current -> next = list1 ? list1 : list2;
            
            ListNode* newList = dummy -> next;
            delete dummy;
            return newList;
        }
};