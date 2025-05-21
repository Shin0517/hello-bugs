# [2. Add Two Numbers](https://leetcode.com/problems/add-two-numbers/description/)

You are given two **non-empty**  linked lists representing two non-negative integers. The digits are stored in **reverse order** , and each of their nodes contains a single digit. Add the two numbers and return the sumas a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

**Example 1:** 
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/02/addtwonumber1.jpg" style="width: 483px; height: 342px;">

```
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
```

**Example 2:** 

```
Input: l1 = [0], l2 = [0]
Output: [0]
```

**Example 3:** 

```
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
```

**Constraints:** 

- The number of nodes in each linked list is in the range <code>[1, 100]</code>.
- <code>0 <= Node.val <= 9</code>
- It is guaranteed that the list represents a number that does not have leading zeros.

---

## ➕ LeetCode 2. Add Two Numbers

### ✅ 題目說明

給定兩個非空的 Linked List，代表兩個非負整數，數字以倒序方式儲存，每個節點只存一位數，請回傳這兩個數字相加後的結果（仍以倒序方式回傳）。

---

### 📌 原始程式碼

```cpp
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
```

---

### ⏱ 複雜度分析

| 類型 | 複雜度            |
| -- | -------------- |
| 時間 | `O(max(m, n))` |
| 空間 | `O(max(m, n))` |

> `m`, `n` 為兩個 Linked List 的長度。

---

### ✅ 優點分析

| 項目                | 說明                      |
| ----------------- | ----------------------- |
| ✅ 清楚使用 dummy node | 建立結果鏈結清晰並易於管理           |
| ✅ 處理進位與邊界完備       | 能處理不同長度的 list 且處理 carry |
| ✅ 程式邏輯清楚          | 每次循環只處理一位數，符合題意         |

---

### ⚠️ 問題與優化建議

| 類型         | 問題描述                       | 建議修正                       |
| ---------- | -------------------------- | -------------------------- |
| 💡 命名語意    | `dummy` 實際是尾部指針，命名可更清楚     | 建議改名為 `tail`               |
| 🧹 可移除中介變數 | `res -> next` 可直接回傳，無需額外指標 | 可簡化為 `return dummy->next;` |

---

### ✨ 優化版本

```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode();
        ListNode* tail = dummyHead;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            tail->next = new ListNode(sum % 10);
            carry = sum / 10;
            tail = tail->next;
        }

        return dummyHead->next;
    }
};
```

---

### 📊 優化對照表

| 項目    | 原始版本                                           | 優化版本                         |
| ----- | ---------------------------------------------- | ---------------------------- |
| 命名清晰度 | `dummy`, `res`                                 | `dummyHead`, `tail`          |
| 語意冗餘  | `ListNode* result = res->next; return result;` | 直接 `return dummyHead->next;` |
| 邏輯改進  | ❌                                              | ✅（語意一致）                      |
| 可讀性   | 普通                                             | 更佳（命名直觀）                     |

---

### ✅ 小結

本題原始實作已相當完整，重點在於程式命名與結構清晰度。改良版本使用更語意清楚的變數名稱與簡化 return 邏輯，使程式碼更具可讀性與維護性。
