# [28. Find the Index of the First Occurrence in a String](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/)

Given two strings <code>needle</code> and <code>haystack</code>, return the index of the first occurrence of <code>needle</code> in <code>haystack</code>, or <code>-1</code> if <code>needle</code> is not part of <code>haystack</code>.

**Example 1:** 

```
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
```

**Example 2:** 

```
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
```

**Constraints:** 

- <code>1 <= haystack.length, needle.length <= 10^4</code>
- <code>haystack</code> and <code>needle</code> consist of only lowercase English characters.

---

## 💡 LeetCode 28. Find the Index of the First Occurrence in a String（`strStr()`）

### ✅ 題目說明

實作 `strStr()` 函式，找出 `needle` 在 `haystack` 中第一次出現的索引；若未出現則回傳 -1。

---

### 🔢 原始程式碼

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() > haystack.size()) return -1;

        for (int i = 0; i <= haystack.size() - needle.size(); i++) {
            if (haystack.substr(i, needle.size()) == needle) {
                return i;
            }
        }
        return -1;
    }
};
```

---

### ⏱ 複雜度分析

| 類型 | 複雜度                                                                                 |
| -- | ----------------------------------------------------------------------------------- |
| 時間 | `O(n * m)`：`substr()` 每次複製為 O(m)，迴圈最多跑 `n - m + 1` 次（n 為 haystack 長度，m 為 needle 長度） |
| 空間 | `O(m)`：每次 `substr()` 都會額外產生一段長度為 m 的字串                                              |

---

### 🔍 問題與優化建議

| 問題類型      | 說明                       |
| --------- | ------------------------ |
| ⚠ 效率問題    | `substr()` 每次都產生新字串，開銷不小 |
| ⚠ 空間使用非最優 | 每次迴圈中會動態配置記憶體以產生子字串      |
| ✅ 邏輯正確    | 可以正確處理所有基本測資情境           |

---

### ✨ 優化後版本（使用原始字元比較取代 `substr()`）

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (m > n) return -1;

        for (int i = 0; i <= n - m; ++i) {
            int j = 0;
            while (j < m && haystack[i + j] == needle[j]) {
                ++j;
            }
            if (j == m) return i;
        }
        return -1;
    }
};
```

---

### ✅ 優化說明

| 優化點     | 原始版本               | 優化後                |
| ------- | ------------------ | ------------------ |
| 子字串比較方式 | 使用 `substr()` 新建字串 | 使用 index 原地比較字元    |
| 時間複雜度   | `O(n * m)`         | `O(n * m)`（最壞情況相同） |
| 空間複雜度   | `O(m)`             | `O(1)`             |
| 效率      | 多餘分配記憶體            | ✅ 無動態分配、記憶體友善      |
| 可讀性     | 簡單易懂               | ✅ 稍微進階但可維護性高       |

---

### 📌 小結

| 項目  | 原始版本            | 優化版本       |
| --- | --------------- | ---------- |
| 可讀性 | ✅               | ✅          |
| 效率  | ❌ 使用 `substr()` | ✅ index 比較 |
| 空間  | `O(m)`          | ✅ `O(1)`   |
| 正確性 | ✅               | ✅          |

---

### 🔄 Bonus 建議（進階）

若需要處理非常大字串、或要求更佳效能，可考慮實作 KMP（Knuth-Morris-Pratt）演算法，其時間複雜度為 `O(n + m)`，能顯著減少不必要的重複比較。若有需要我可以協助你實作。
