# [13. Roman to Integer](https://leetcode.com/problems/roman-to-integer/description/)

Roman numerals are represented by seven different symbols:<code>I</code>, <code>V</code>, <code>X</code>, <code>L</code>, <code>C</code>, <code>D</code> and <code>M</code>.

```
**Symbol**    **Value** 
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
```

For example,<code>2</code> is written as <code>II</code>in Roman numeral, just two ones added together. <code>12</code> is written as<code>XII</code>, which is simply <code>X + II</code>. The number <code>27</code> is written as <code>XXVII</code>, which is <code>XX + V + II</code>.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not <code>IIII</code>. Instead, the number four is written as <code>IV</code>. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as <code>IX</code>. There are six instances where subtraction is used:

- <code>I</code> can be placed before <code>V</code> (5) and <code>X</code> (10) to make 4 and 9.
- <code>X</code> can be placed before <code>L</code> (50) and <code>C</code> (100) to make 40 and 90.
- <code>C</code> can be placed before <code>D</code> (500) and <code>M</code> (1000) to make 400 and 900.

Given a roman numeral, convert it to an integer.

**Example 1:** 

```
Input: s = "III"
Output: 3
Explanation: III = 3.
```

**Example 2:** 

```
Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
```

**Example 3:** 

```
Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
```

**Constraints:** 

- <code>1 <= s.length <= 15</code>
- <code>s</code> contains onlythe characters <code>('I', 'V', 'X', 'L', 'C', 'D', 'M')</code>.
- It is **guaranteed** that <code>s</code> is a valid roman numeral in the range <code>[1, 3999]</code>.

---

以下是針對 LeetCode 題目 `13. Roman to Integer` 的程式碼優化與複雜度分析，使用你指定的 Markdown 格式，適合直接貼到 GitHub：

---

## 💡 LeetCode 13. Roman to Integer 解法分析與優化建議

### 原始程式碼

```cpp
class Solution {
public:
    int charToNum(char a) {
        switch(a) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }

    int romanToInt(string s) {
        int num = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (charToNum(s[i]) < charToNum(s[i + 1]) && i + 1 < s.length()){
                num -= charToNum(s[i]);
            } else {
                num += charToNum(s[i]);
            }
        }

        return num;
    }
};
```

---

### ✅ 功能說明

此程式碼將一個羅馬數字字串（如 `"MCMXCIV"`）轉換成對應的整數。若某字符比下一個小，表示應用減法規則（例如 `IV = 4`），否則則加總該字符對應的值。

---

### 🧠 時間與空間複雜度分析

* **時間複雜度：** `O(n)`
  一次遍歷字串，`charToNum()` 為常數時間操作。

* **空間複雜度：** `O(1)`
  未使用額外資料結構，只使用少量變數。

---

### 🔍 優化建議

#### 1. **避免重複呼叫 `charToNum`**

* 每個 `charToNum(s[i])` 都重複呼叫多次，效率不佳。
* 可以先將字串轉換為對應的數值陣列，再進行處理。

#### 2. **使用雜湊表替代 `switch-case`**

* 雜湊查表方式更清楚、擴充性更高，可用 `unordered_map<char, int>` 取代 `charToNum` 函數。

#### 3. **for-loop 節點檢查順序修正**

* 當 `i + 1` 超出範圍時，`charToNum(s[i+1])` 呼叫在條件中出現，容易產生潛在風險。
* 應先判斷 `i + 1 < s.length()`，再比較大小。

---

### 🚀 優化後程式碼

```cpp
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanMap = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int total = 0;
        for (int i = 0; i < s.length(); ++i) {
            int current = romanMap[s[i]];
            int next = (i + 1 < s.length()) ? romanMap[s[i + 1]] : 0;

            if (current < next) {
                total -= current;
            } else {
                total += current;
            }
        }

        return total;
    }
};
```

---

### 📝 總結

| 項目     | 原始程式碼                   | 優化後程式碼                 |
| ------ | ----------------------- | ---------------------- |
| 效率     | 每步重複呼叫 `charToNum`      | 只呼叫一次                  |
| 安全性    | `charToNum(s[i+1])` 易越界 | 預先檢查 `i + 1 < len`     |
| 彈性與可讀性 | `switch-case` 較繁瑣       | 使用 `unordered_map` 更直覺 |
| 時間複雜度  | `O(n)`                  | `O(n)`（相同）             |
| 空間複雜度  | `O(1)`                  | `O(1)`（略增雜湊表但為常數）      |
