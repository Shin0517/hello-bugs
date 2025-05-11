# [9. Palindrome Number](https://leetcode.com/problems/palindrome-number/description/)

Given an integer <code>x</code>, return <code>true</code> if <code>x</code> is a <button type="button" aria-haspopup="dialog" aria-expanded="false" aria-controls="radix-:rp:" data-state="closed" class="">**palindrome** </button>, and <code>false</code> otherwise.

**Example 1:** 

```
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
```

**Example 2:** 

```
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
```

**Example 3:** 

```
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
```

**Constraints:** 

- <code>-2^31<= x <= 2^31- 1</code>

**Follow up:**  Could you solve it without converting the integer to a string?

---

以下是針對 LeetCode 題目 `9. Palindrome Number` 的解法分析與優化建議，已使用你指定的 GitHub-friendly Markdown 格式整理：

---

## 💡 LeetCode 9. Palindrome Number 解法分析與優化建議

### 原始程式碼

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0){
            return false;
        }

        int inputNum = x;
        long reversedNum = 0;
        while (x > 0){
            reversedNum = reversedNum * 10 + x % 10;
            x = x / 10;
        }

        return (reversedNum == inputNum);
    }
};
```

---

### ✅ 功能說明

這段程式碼判斷一個整數是否為回文數（即正著讀與反著讀相同），負數直接回傳 `false`，正整數則反轉整數並與原始值比較。

---

### 🧠 時間與空間複雜度分析

* **時間複雜度：** `O(log_{10}(x))`
  因為每次除以 10，最多做 `digits` 次。

* **空間複雜度：** `O(1)`
  使用常數空間，不含輸入。

---

### 🔍 優化建議

#### 1. **避免使用 `long` 型別**

* 原本反轉的數字可能超過 `int` 範圍，因此使用 `long`。
* 但實際上，題目中給定的 `x` 為 **32-bit signed integer**，不需額外延伸型別即可解題，只要反轉一半數字即可避免溢位。

#### 2. **只反轉數字的一半以提升效率與安全性**

* 只需反轉一半數字即可比較是否為回文，避免不必要的全數字反轉運算，且可完全避免溢位問題。

#### 3. **排除尾數為 0 的非 0 整數**

* 例如：`10`, `100` 等都不可能為回文數（除非是 0 本身）

---

### 🚀 優化後程式碼

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers and numbers ending in 0 (except 0 itself) can't be palindrome
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        // Even length: x == reversedHalf
        // Odd length: x == reversedHalf / 10 (skip middle digit)
        return (x == reversedHalf || x == reversedHalf / 10);
    }
};
```

---

### 📝 總結

| 項目     | 原始程式碼         | 優化後程式碼          |
| ------ | ------------- | --------------- |
| 資料型別   | 使用 `long` 防溢位 | 完全避免溢位，僅用 `int` |
| 效率     | 全數字反轉         | 只反轉一半，效率更高      |
| 邏輯簡潔度  | 中             | 高，且更安全          |
| 額外條件處理 | 無             | 加入尾數為 0 的過濾邏輯   |

此優化解法是 LeetCode 官方推薦解法之一，兼具 **效率** 與 **安全性**，非常適合在面試或實務中使用。
