/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* res = dummy;
        
        int num = 0, carry = 0;
        while (l1 || l2 || carry) {
            num = carry;
            if (l1) {
                num += l1 -> val;
                l1 = l1 -> next;
            }
            if (l2) {
                num += l2 -> val;
                l2 = l2 -> next;
            }

            int digit = num % 10;
            carry = num / 10;
            dummy -> next = new ListNode(digit);
            dummy = dummy -> next;
        }
        ListNode* result = res -> next;
        return result;
    }
};