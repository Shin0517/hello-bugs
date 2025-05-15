# [21. Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/description/)

You are given the heads of two sorted linked lists <code>list1</code> and <code>list2</code>.

Merge the two lists into one **sorted**  list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

**Example 1:** 
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/03/merge_ex1.jpg" style="width: 662px; height: 302px;">

```
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
```

**Example 2:** 

```
Input: list1 = [], list2 = []
Output: []
```

**Example 3:** 

```
Input: list1 = [], list2 = [0]
Output: [0]
```

**Constraints:** 

- The number of nodes in both lists is in the range <code>[0, 50]</code>.
- <code>-100 <= Node.val <= 100</code>
- Both <code>list1</code> and <code>list2</code> are sorted in **non-decreasing**  order.

---


以下是針對你提供的 C++ 程式碼（LeetCode 21. Merge Two Sorted Lists）的完整分析與優化建議，格式依然為你指定的 GitHub Markdown 樣式。

---

## 💡 LeetCode 21. Merge Two Sorted Lists 解法分析與優化建議

### ✅ 題目說明

將兩個**已排序**的單向鏈結串列合併為一個**排序後的新鏈結串列**，並返回這個新串列的頭節點。

---

### 🔢 原始程式碼

```cpp
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
```

---

### ⏱ 複雜度分析

| 類型 | 複雜度                                               |
| -- | ------------------------------------------------- |
| 時間 | `O(n + m)`：遍歷兩條鏈結串列各一次（n 為 list1 長度，m 為 list2 長度） |
| 空間 | `O(1)`：只使用常數額外空間（不包含輸出）                           |

---

### 🔍 問題與優化建議

| 問題類型        | 說明                                                                     |
| ----------- | ---------------------------------------------------------------------- |
| ✅ 邏輯正確      | 處理 dummy node 與合併邏輯正確。                                                 |
| ⚠ 可讀性提升空間   | 使用 `->` 較多，適度簡化可提升可讀性。                                                 |
| ⚠ 資源釋放方式可優化 | `delete dummy` 是正確的，但某些風格建議避免裸指標 `new/delete`，可使用 smart pointer 或堆疊分配。 |
| ✅ 無記憶體洩漏    | `dummy` 有釋放，沒問題。                                                       |

---

### ✨ 優化後版本（語意與簡潔性提升）

```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);  // stack allocation
        ListNode* current = &dummy;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        current->next = list1 ? list1 : list2;
        return dummy.next;
    }
};
```

---

### ✅ 優化說明

| 優化點        | 原始                             | 優化後                                   |
| ---------- | ------------------------------ | ------------------------------------- |
| Dummy 節點建立 | 使用 `new` 動態記憶體配置並手動釋放          | 使用堆疊變數，無需 `delete`                    |
| 比較順序       | `if (list1->val > list2->val)` | `if (list1->val <= list2->val)`：語意更自然 |
| `->` 存取頻率  | 多次 `list1->val` / `list2->val` | 簡化至一次條件中存取                            |
| 可讀性        | 稍微冗長                           | 精簡且語意清楚                               |

---

### 📌 小結

| 項目    | 原始版本           | 優化版本           |
| ----- | -------------- | -------------- |
| 可讀性   | 普通             | ✅ 更簡潔明確        |
| 記憶體安全 | ✅ 有手動 `delete` | ✅ 使用堆疊變數更安全簡潔  |
| 效率    | `O(n + m)`     | `O(n + m)`（相同） |
| 空間    | `O(1)`         | `O(1)`（相同）     |
