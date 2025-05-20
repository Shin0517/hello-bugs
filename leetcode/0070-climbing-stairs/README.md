# [70. Climbing Stairs](https://leetcode.com/problems/climbing-stairs/description/)

You are climbing a staircase. It takes <code>n</code> steps to reach the top.

Each time you can either climb <code>1</code> or <code>2</code> steps. In how many distinct ways can you climb to the top?

**Example 1:** 

```
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
```

**Example 2:** 

```
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
```

**Constraints:** 

- <code>1 <= n <= 45</code>

---

## 🧗 LeetCode 70. Climbing Stairs

### ✅ 題目說明

給定一個整數 `n`，代表有 `n` 個階梯，每次你可以爬 1 或 2 階，請問總共有多少種不同的方法可以爬到頂端。

---

### 📌 原始程式碼

```cpp
class Solution {
public:
    unordered_map<int, int> climbed;

    int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        if (climbed.find(n) == climbed.end()) {
            climbed[n] = climbStairs(n - 1) + climbStairs(n - 2);
        }
        return climbed[n];
    }
};
```

---

### ⏱ 複雜度分析

| 類型 | 複雜度                       |
| -- | ------------------------- |
| 時間 | `O(n)` - 使用記憶化遞迴避免重複計算    |
| 空間 | `O(n)` - 遞迴堆疊與 map 儲存中間結果 |

---

### ✅ 優點分析

| 項目                   | 說明                          |
| -------------------- | --------------------------- |
| ✅ 使用記憶化（Memoization） | 有效解決重複子問題                   |
| ✅ 邏輯清晰               | 基本結構符合 Fibonacci 解法         |
| ✅ 邊界條件處理完備           | 對 `n == 0` 與 `n == 1` 有良好處理 |

---

### ⚠️ 問題與優化建議

| 類型          | 問題描述                                           | 建議修正                                       |
| ----------- | ---------------------------------------------- | ------------------------------------------ |
| 🧠 記憶化結構外部化 | `climbed` 作為類別變數會造成不同測資間殘留資料（在 LeetCode 上可能出錯） | 改為函數內部的 `unordered_map` 或改用 `vector` 儲存中間值 |
| 🚀 效能可進一步提升 | 使用遞迴仍會產生呼叫堆疊成本                                 | 可改用 bottom-up 動態規劃（DP）實作或 Fibonacci 空間優化版  |

---

### ✨ 優化版本：動態規劃（空間優化）

```cpp
class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) return 1;
        
        int first = 1, second = 1;
        for (int i = 2; i <= n; ++i) {
            int current = first + second;
            first = second;
            second = current;
        }
        return second;
    }
};
```

---

### 📊 優化對照表

| 項目    | 原始版本              | 優化版本           |
| ----- | ----------------- | -------------- |
| 時間複雜度 | `O(n)`            | `O(n)`         |
| 空間複雜度 | `O(n)`（map 與遞迴堆疊） | `O(1)`（只保留兩變數） |
| 遞迴堆疊  | 有                 | 無（改用迴圈）        |
| GC安全  | ❌ 共享變數殘留          | ✅ 每次呼叫獨立       |

---

### ✅ 小結

原始實作邏輯正確，但在 LeetCode 多測資情境中，使用類別成員變數 `climbed` 可能導致資料殘留。推薦改用函式內變數或轉換為動態規劃實作，不僅避免錯誤，也能提升效能與簡潔性。
