# [83. Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/)

Given the <code>head</code> of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list **sorted**  as well.

**Example 1:** 
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/04/list1.jpg" style="width: 302px; height: 242px;">

```
Input: head = [1,1,2]
Output: [1,2]
```

**Example 2:** 
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/04/list2.jpg" style="width: 542px; height: 222px;">

```
Input: head = [1,1,2,3,3]
Output: [1,2,3]
```

**Constraints:** 

- The number of nodes in the list is in the range <code>[0, 300]</code>.
- <code>-100 <= Node.val <= 100</code>
- The list is guaranteed to be **sorted**  in ascending order.

---

## 🧹 LeetCode 83. Remove Duplicates from Sorted List

### ✅ 題目說明

給定一個排序過的單向 Linked List，刪除所有重複的元素，使每個元素只出現一次。

---

### 📌 原始程式碼

```cpp
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;

        while (current && current->next) {
            if (current->val == current->next->val) {
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }
        return head;
    }
};
```

---

### ⏱ 複雜度分析

| 類型 | 複雜度    |
| -- | ------ |
| 時間 | `O(n)` |
| 空間 | `O(1)` |

> `n` 為 Linked List 的長度。

---

### ✅ 優點分析

| 項目        | 說明         |
| --------- | ---------- |
| ✅ 簡潔明確的邏輯 | 直接比較相鄰節點   |
| ✅ 原地修改    | 空間使用效率高    |
| ✅ 判斷條件正確  | 完整處理所有重複節點 |

---

### ⚠️ 可優化項目與建議

| 類型        | 問題描述                 | 建議修正                 |
| --------- | -------------------- | -------------------- |
| ✏️ 命名可讀性  | `current` 可明確表達為遍歷指標 | 無需大修，建議保留或微調為 `curr` |
| 🧹 無需額外優化 | 邏輯與效率已最佳化            | ✅ 維持原狀               |

---

### ✨ 優化版本（語意稍微調整）

```cpp
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;

        while (curr && curr->next) {
            if (curr->val == curr->next->val) {
                curr->next = curr->next->next;  // 移除重複
            } else {
                curr = curr->next;  // 向前移動
            }
        }

        return head;
    }
};
```

---

### 📊 優化對照表

| 項目    | 原始版本      | 優化版本          |
| ----- | --------- | ------------- |
| 命名清晰度 | `current` | `curr`（一致性更高） |
| 邏輯結構  | ✅ 正確      | ✅ 相同，略加註解     |
| 可讀性   | 中等        | 稍好（語意說明）      |

---

### ✅ 小結

這題重點是**排序保證所有重複項都連續**，讓我們能用單指標一次過濾完畢。你的實作乾淨俐落，不須大改！
如需處理 **未排序 List 中的重複元素**，會需要額外的 `set` 或排序前處理。
