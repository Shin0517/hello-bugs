# [66. Plus One](https://leetcode.com/problems/plus-one/description/)

You are given a **large integer**  represented as an integer array <code>digits</code>, where each <code>digits[i]</code> is the <code>i^th</code> digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading <code>0</code>'s.

Increment the large integer by one and return the resulting array of digits.

**Example 1:** 

```
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
```

**Example 2:** 

```
Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].
```

**Example 3:** 

```
Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].
```

**Constraints:** 

- <code>1 <= digits.length <= 100</code>
- <code>0 <= digits[i] <= 9</code>
- <code>digits</code> does not contain any leading <code>0</code>'s.

---

## 🔢 LeetCode 66. Plus One

### ✅ 題目說明

給定一個由「非負整數」所組成的陣列 `digits`，表示一個大整數的每一位數。請對此整數加一，並以相同的陣列形式回傳結果。

---

### 🧾 原始程式碼

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] + 1 != 10) {
                digits[i] += 1;
                return digits;
            }

            digits[i] = 0;
            if (i == 0) {
                digits.insert(digits.begin(), 1);
                return digits;
            }
        }
        return digits;
    }
};
```

---

### ⏱ 複雜度分析

| 類型 | 複雜度                            |
| -- | ------------------------------ |
| 時間 | `O(n)` 最壞情況下需處理所有位數（如 999...9） |
| 空間 | `O(1)` 就地修改輸入陣列（除非進位導致額外插入元素）  |

---

### ✅ 優點分析

| 項目     | 說明                                |
| ------ | --------------------------------- |
| ✅ 邏輯正確 | 正確處理進位與末位更新                       |
| ✅ 空間節省 | 基本為就地修改 `digits`，僅於必要時使用 `insert` |
| ✅ 早停設計 | 遇到非進位情況即直接 `return`，提高效率          |

---

### ✨ 可選優化方向

| 類型       | 建議                                               |
| -------- | ------------------------------------------------ |
| 💡 結構清晰化 | 將條件與 return 拆開，讓流程更直覺                            |
| 📌 邏輯一致性 | 在迴圈外加進位判斷即可避免在 `if (i == 0)` 時提前 `return`，減少重複路徑 |

---

### 🧼 建議優化版本（更清晰、更一致）

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }

        // 全部為9的情況，例如 999 -> 1000
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
```

---

### 📊 優化比較表

| 項目     | 原始版本   | 優化版本           |
| ------ | ------ | -------------- |
| 時間複雜度  | `O(n)` | `O(n)`         |
| 空間複雜度  | `O(1)` | `O(1)`         |
| 可讀性    | 中等     | ✅ 更清晰一致        |
| 邏輯重複處理 | ❌ 有    | ✅ 減少 return 分支 |

---

### ✅ 小結

此題關鍵為處理 **進位與高位溢出** 的情境。原始邏輯正確，但在控制流程上略顯繁瑣。建議精簡條件與 return 分支，提高程式結構的清晰度與可維護性。
