# [20. Valid Parentheses](https://leetcode.com/problems/valid-parentheses/description/)

Given a string <code>s</code> containing just the characters <code>'('</code>, <code>')'</code>, <code>'{'</code>, <code>'}'</code>, <code>'['</code> and <code>']'</code>, determine if the input string is valid.

An input string is valid if:

- Open brackets must be closed by the same type of brackets.
- Open brackets must be closed in the correct order.
- Every close bracket has a corresponding open bracket of the same type.

**Example 1:** 

<div class="example-block">
Input: s = "()"

Output: true

**Example 2:** 

<div class="example-block">
Input: s = "()[]{}"

Output: true

**Example 3:** 

<div class="example-block">
Input: s = "(]"

Output: false

**Example 4:** 

<div class="example-block">
Input: s = "([])"

Output: true

**Constraints:** 

- <code>1 <= s.length <= 10^4</code>
- <code>s</code> consists of parentheses only <code>'()[]{}'</code>.

---

以下是針對你提供的 C++ 程式碼（來自 LeetCode 20. Valid Parentheses）的完整分析與優化建議，採用你要求的 GitHub Markdown 格式。

---

## 💡 LeetCode 20. Valid Parentheses 解法分析與優化建議

### ✅ 題目說明

給定一個只包含 `'('`, `')'`, `'{'`, `'}'`, `'['`, `']'` 的字串，檢查是否為**有效的括號序列**。有效的定義如下：

* 左括號必須用相同類型的右括號閉合。
* 左括號必須以正確的順序閉合。

---

### 🔢 原始程式碼

```cpp
class Solution {
public:
    bool isValid(string s) {
        std::stack<char> parenthesesStack;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                parenthesesStack.push(s[i]);
            } else if (!parenthesesStack.empty() && (
                        (parenthesesStack.top() == '(' && s[i] == ')') ||
                        (parenthesesStack.top() == '[' && s[i] == ']') ||
                        (parenthesesStack.top() == '{' && s[i] == '}'))) {
                parenthesesStack.pop();
            } else {
                return false;
            }
        }
        return parenthesesStack.empty();
    }
};
```

---

### ⏱ 複雜度分析

| 類型 | 複雜度                              |
| -- | -------------------------------- |
| 時間 | `O(n)`：遍歷整個字串一次                  |
| 空間 | `O(n)`：最壞情況下所有字元皆為左括號，皆需推入 stack |

---

### 🔍 問題與優化建議

| 問題類型    | 說明                                           |
| ------- | -------------------------------------------- |
| ✅ 邏輯正確  | 使用 `stack` 處理括號匹配，思路正確且高效。                   |
| ⚠ 可讀性略低 | `else if` 條件過長且嵌套，閱讀不易。可用變數或映射簡化。            |
| ⚠ 變數命名  | `parenthesesStack` 太冗長，可簡化為 `stk` 或 `stack`。 |
| ⚠ 型別限定  | `std::` 前綴可省略於 LeetCode 編譯器中，提升可讀性。          |
| ✅ 無語法錯誤 | 與前版本相比，這版已修復括號錯誤。                            |

---

### ✨ 優化後版本

使用 C++11 的範圍型迴圈與簡潔命名：

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stk.push(c);
            } else {
                if (stk.empty()) return false;
                char top = stk.top();
                if ((top == '(' && c == ')') ||
                    (top == '[' && c == ']') ||
                    (top == '{' && c == '}')) {
                    stk.pop();
                } else {
                    return false;
                }
            }
        }
        return stk.empty();
    }
};
```

---

### 🔁 進階優化：使用映射提高可擴充性與清晰度

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> pairs = {
            {')', '('}, {']', '['}, {'}', '{'}
        };

        for (char c : s) {
            if (pairs.count(c)) {
                if (stk.empty() || stk.top() != pairs[c]) return false;
                stk.pop();
            } else {
                stk.push(c);
            }
        }

        return stk.empty();
    }
};
```

---

### 📌 小結

| 項目   | 原始版本            | 優化版本                |
| ---- | --------------- | ------------------- |
| 可讀性  | `else if` 條件較複雜 | ✅ 拆解條件、語義化命名        |
| 擴充性  | ❌ 寫死三種括號邏輯      | ✅ 可透過 map 延伸其他配對結構  |
| 效率   | `O(n)` / `O(n)` | `O(n)` / `O(n)`（相同） |
| 錯誤處理 | ✅ 有處理空堆疊的情況     | ✅ 相同                |

