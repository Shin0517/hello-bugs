# [58. Length of Last Word](https://leetcode.com/problems/length-of-last-word/description/)

Given a string <code>s</code> consisting of words and spaces, return the length of the **last**  word in the string.

A **word**  is a maximal <button type="button" aria-haspopup="dialog" aria-expanded="false" aria-controls="radix-:rp:" data-state="closed" class="">substring</button> consisting of non-space characters only.

**Example 1:** 

```
Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
```

**Example 2:** 

```
Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
```

**Example 3:** 

```
Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
```

**Constraints:** 

- <code>1 <= s.length <= 10^4</code>
- <code>s</code> consists of only English letters and spaces <code>' '</code>.
- There will be at least one word in <code>s</code>.

---

## 📝 LeetCode 58. Length of Last Word

### ✅ 題目說明

給定一個由英文字母與空格組成的字串 `s`，返回字串中最後一個單字的長度。單字被定義為不包含空格的連續字母序列。

---

### 🧾 原始程式碼

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int i = s.size() - 1;

        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--; 
        }
        return length;
    }
};
```

---

### ⏱ 複雜度分析

| 類型 | 複雜度                |
| -- | ------------------ |
| 時間 | `O(n)` 最多遍歷整個字串    |
| 空間 | `O(1)` 常數空間，只用整數變數 |

---

### ✅ 優點分析

| 項目     | 說明                            |
| ------ | ----------------------------- |
| ✅ 效率高  | 單趟從尾端反向掃描，遇到第一個單字就回傳，避免不必要處理  |
| ✅ 空間優化 | 無需額外字串處理，僅使用原字串與幾個變數          |
| ✅ 清晰明瞭 | 兩個 while-loop 明確對應去除尾部空白與計算長度 |

---

### ✨ 可選優化方向

| 類型                | 建議                                         |
| ----------------- | ------------------------------------------ |
| 💡 表達優化           | 雖然邏輯已非常高效，但可以微調變數命名增加語意性（如 `index` 而非 `i`） |
| 💡 STL 替代（若不限制使用） | 可考慮使用 `std::find_if` 等 STL 提高語義可讀性，但效率差異不大 |

---

### 🧼 建議優化版本（語意更清晰）

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int index = s.size() - 1;

        // Skip trailing spaces
        while (index >= 0 && s[index] == ' ') {
            index--;
        }

        // Count last word length
        while (index >= 0 && s[index] != ' ') {
            length++;
            index--;
        }

        return length;
    }
};
```

---

### 📊 優化比較表

| 項目    | 原始版本   | 優化版本      |
| ----- | ------ | --------- |
| 時間複雜度 | `O(n)` | `O(n)`    |
| 空間複雜度 | `O(1)` | `O(1)`    |
| 可讀性   | 中等     | ✅ 較清晰、語意佳 |
| STL使用 | ❌ 無    | ✅ 可視需求補強  |

---

### ✅ 小結

這題的重點是處理尾部空格與單字邊界，原始程式已非常優化，無需改動核心邏輯。若需微幅增進可讀性，可考慮變數命名語意化或使用 C++ STL 工具函式。
