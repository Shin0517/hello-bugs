# [69. Sqrt(x)](https://leetcode.com/problems/sqrtx/description/)

Given a non-negative integer <code>x</code>, return the square root of <code>x</code> rounded down to the nearest integer. The returned integer should be **non-negative**  as well.

You **must not use**  any built-in exponent function or operator.

- For example, do not use <code>pow(x, 0.5)</code> in c++ or <code>x ** 0.5</code> in python.

**Example 1:** 

```
Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
```

**Example 2:** 

```
Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
```

**Constraints:** 

- <code>0 <= x <= 2^31 - 1</code>

---

## 📝 LeetCode 69. Sqrt(x)

### ✅ 題目說明

實作 `int mySqrt(int x)` 函式，計算並回傳 `x` 的平方根（只取整數部分，捨去小數位）。

---

### 🧾 原始程式碼

```cpp
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }

        int start = 1;
        int end = x;
        int mid = 0;

        while (start <= end) {
            mid = start + (end - start) / 2;
            if ((long)mid * mid > (long)x) {
                end = mid - 1;
            } else if (mid * mid < x) {
                start = mid + 1;
            } else {
                return mid;
            }
        }
        return round(end);
    }
};
```

---

### ⏱ 複雜度分析

| 類型 | 複雜度                |
| -- | ------------------ |
| 時間 | `O(log x)` 使用二分搜尋法 |
| 空間 | `O(1)` 常數空間        |

---

### ✅ 優點分析

| 項目               | 說明                          |
| ---------------- | --------------------------- |
| ✅ 高效             | 使用 Binary Search，時間複雜度優於暴力法 |
| ✅ 邊界清楚           | 有處理 `x = 0` 與 `x = 1` 特殊情況  |
| ✅ 使用 `long` 避免溢位 | 避免 `mid * mid` 溢位問題，正確處理大數值 |

---

### ⚠️ 問題與優化建議

| 類型     | 問題描述                                      | 建議修正                                                     |
| ------ | ----------------------------------------- | -------------------------------------------------------- |
| ❌ 語意錯誤 | `round(end)` 不正確，應回傳「最接近但不超過平方根」的整數       | 使用 `end` 即可，`end` 是最小的 `mid`，使 `mid*mid <= x` 成立         |
| ✏️ 可讀性 | 判斷 `mid * mid > x` 與 `mid * mid < x` 重複計算 | 可抽出 `long long square = (long long)mid * mid` 提升可讀性與效能微調 |

---

### ✨ 優化版本

```cpp
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;

        int left = 1, right = x;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long square = (long long)mid * mid;

            if (square == x) {
                return mid;
            } else if (square < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right; // right 是平方 <= x 的最大值
    }
};
```

---

### 📊 優化對照表

| 項目    | 原始版本                | 優化版本              |
| ----- | ------------------- | ----------------- |
| 時間複雜度 | `O(log x)`          | `O(log x)`        |
| 空間複雜度 | `O(1)`              | `O(1)`            |
| 溢位處理  | ✅ 有處理               | ✅ 有處理             |
| 結果正確性 | ⚠️ 有誤（`round(end)`) | ✅ 正確使用 `right`    |
| 可讀性   | 中等                  | ✅ 較佳（抽出 `square`） |

---

### ✅ 小結

本題核心在於**二分搜尋找平方根的下界**，原始解法邏輯正確但在回傳結果時使用 `round(end)` 不恰當。建議改回傳 `right`（或 `end`），這樣才符合「不超過平方根」的要求。
