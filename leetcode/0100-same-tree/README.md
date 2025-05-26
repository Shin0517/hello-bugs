# [100. Same Tree](https://leetcode.com/problems/same-tree/description/)

Given the roots of two binary trees <code>p</code> and <code>q</code>, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

**Example 1:** 
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/20/ex1.jpg" style="width: 622px; height: 182px;">

```
Input: p = [1,2,3], q = [1,2,3]
Output: true
```

**Example 2:** 
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/20/ex2.jpg" style="width: 382px; height: 182px;">

```
Input: p = [1,2], q = [1,null,2]
Output: false
```

**Example 3:** 
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/20/ex3.jpg" style="width: 622px; height: 182px;">

```
Input: p = [1,2,1], q = [1,1,2]
Output: false
```

**Constraints:** 

- The number of nodes in both trees is in the range <code>[0, 100]</code>.
- <code>-10^4 <= Node.val <= 10^4</code>

---

## 🌳 LeetCode 100. Same Tree

### ✅ 題目說明

給定兩棵二元樹 `p` 和 `q`，請判斷它們是否為**相同的樹**。
相同的定義是：兩棵樹的結構完全相同，且相對應的節點數值也相同。

---

### 📌 原始程式碼

```cpp
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }
        if (p && q && p->val == q->val) {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        return false;    
    }
};
```

---

### ⏱ 複雜度分析

| 類型 | 複雜度    |
| -- | ------ |
| 時間 | `O(n)` |
| 空間 | `O(h)` |

> `n` 為樹中節點數，`h` 為樹的高度（遞迴呼叫深度）

---

### ✅ 優點分析

| 項目         | 說明                    |
| ---------- | --------------------- |
| ✅ 結構清晰     | 遞迴方式直觀表達比較邏輯          |
| ✅ 邊界處理完整   | 同時處理 `nullptr` 與節點值比對 |
| ✅ 無需額外資料結構 | 使用原生遞迴不需額外記憶體         |

---

### ⚠️ 可優化項目與建議

| 類型     | 問題描述             | 建議修正       |
| ------ | ---------------- | ---------- |
| ✏️ 可讀性 | if 條件略顯複雜        | 可拆成更易讀的結構  |
| ✨ 語意清晰 | return 條件可提前結束邏輯 | 精簡並提高閱讀流暢度 |

---

### ✨ 優化版本（邏輯展開、語意更清楚）

```cpp
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // 若兩棵都是空樹
        if (!p && !q) return true;

        // 若一棵空、一棵非空
        if (!p || !q) return false;

        // 若值不同
        if (p->val != q->val) return false;

        // 遞迴比對左右子樹
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
```

---

### 📊 優化對照表

| 項目   | 原始版本   | 優化版本               |
| ---- | ------ | ------------------ |
| 邏輯結構 | 條件混合處理 | 拆分為三段 return，閱讀更直觀 |
| 可讀性  | 一次性條件  | 明確表達三種不同狀況         |
| 整體效率 | ✅ 最佳化  | ✅ 相同（語意優化）         |
