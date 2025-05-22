# [94. Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/description/)

Given the <code>root</code> of a binary tree, return the inorder traversal of its nodes' values.

**Example 1:** 

<div class="example-block">
Input: root = [1,null,2,3]

Output: [1,3,2]

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/08/29/screenshot-2024-08-29-202743.png" style="width: 200px; height: 264px;">

**Example 2:** 

<div class="example-block">
Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [4,2,6,5,7,1,3,9,8]

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/08/29/tree_2.png" style="width: 350px; height: 286px;">

**Example 3:** 

<div class="example-block">
Input: root = []

Output: []

**Example 4:** 

<div class="example-block">
Input: root = [1]

Output: [1]

**Constraints:** 

- The number of nodes in the tree is in the range <code>[0, 100]</code>.
- <code>-100 <= Node.val <= 100</code>

**Follow up:**  Recursive solution is trivial, could you do it iteratively?

---

## 🌳 LeetCode 94. Binary Tree Inorder Traversal

### ✅ 題目說明

給定一棵二元樹，請回傳其中序遍歷的節點值序列。

---

### 📌 原始程式碼

```cpp
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stack;
        vector<int> result;

        while (root != nullptr || !stack.empty()) {
            while (root != nullptr) {
                stack.push(root);
                root = root->left;
            }

            root = stack.top();
            stack.pop();
            result.push_back(root->val);
            root = root->right;
        }
        return result;        
    }
};
```

---

### ⏱ 複雜度分析

| 類型 | 複雜度    |
| -- | ------ |
| 時間 | `O(n)` |
| 空間 | `O(n)` |

> `n` 為節點數量。每個節點最多進出 stack 一次。

---

### ✅ 優點分析

| 項目         | 說明            |
| ---------- | ------------- |
| ✅ 非遞迴實作    | 避免遞迴堆疊溢位問題    |
| ✅ 空間與時間最佳化 | 每個節點處理一次，結構簡潔 |
| ✅ 原地走訪     | 無額外樹結構建立      |

---

### ⚠️ 可優化項目與建議

| 類型       | 問題描述                           | 建議修正                |
| -------- | ------------------------------ | ------------------- |
| ✏️ 命名一致性 | `stack` 作為變數名稱與 C++ STL 衝突可能混淆 | 建議改為 `nodeStack`    |
| ✨ 可讀性提升  | 加入註解協助理解 in-order 步驟           | 有助新手理解 traversal 機制 |

---

### ✨ 優化版本（語意與命名調整）

```cpp
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> nodeStack;

        while (root || !nodeStack.empty()) {
            // 走到最左邊
            while (root) {
                nodeStack.push(root);
                root = root->left;
            }

            // 訪問節點
            root = nodeStack.top();
            nodeStack.pop();
            result.push_back(root->val);

            // 處理右子樹
            root = root->right;
        }

        return result;
    }
};
```

---

### 📊 優化對照表

| 項目    | 原始版本    | 優化版本               |
| ----- | ------- | ------------------ |
| 命名清晰度 | `stack` | `nodeStack`（避免保留字） |
| 可讀性   | 無註解     | 加入註解輔助理解           |
| 整體效率  | ✅ 最佳化   | ✅ 相同               |

---

### ✅ 小結

這題使用「顯式 stack 模擬遞迴」是最佳解，尤其適合在無法使用遞迴的情況下。
你已經掌握這個模式的精髓，如果想進一步挑戰，可以嘗試：

* Morris Traversal（空間 `O(1)` 的 In-order 方法）
* 實作 Preorder / Postorder Traversal 的迴圈版本
