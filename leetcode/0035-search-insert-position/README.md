# [35. Search Insert Position](https://leetcode.com/problems/search-insert-position/description/)

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You mustwrite an algorithm with<code>O(log n)</code> runtime complexity.

**Example 1:** 

```
Input: nums = [1,3,5,6], target = 5
Output: 2
```

**Example 2:** 

```
Input: nums = [1,3,5,6], target = 2
Output: 1
```

**Example 3:** 

```
Input: nums = [1,3,5,6], target = 7
Output: 4
```

**Constraints:** 

- <code>1 <= nums.length <= 10^4</code>
- <code>-10^4 <= nums[i] <= 10^4</code>
- <code>nums</code> contains **distinct**  values sorted in **ascending**  order.
- <code>-10^4 <= target <= 10^4</code>

--- 

## 🔍 LeetCode 35. Search Insert Position

### ✅ 題目說明

給定一個排序過的整數陣列 `nums` 和一個目標值 `target`，請找出目標值應插入的位置，並確保陣列仍然維持排序。要求時間複雜度為 `O(log n)`。

---

### 🧾 原始程式碼

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = (right + left) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};
```

---

### ⏱ 複雜度分析

| 類型 | 複雜度               |
| -- | ----------------- |
| 時間 | `O(log n)`：標準二分搜尋 |
| 空間 | `O(1)`：未使用額外資料結構  |

---

### ✅ 優點分析

| 項目     | 說明                                     |
| ------ | -------------------------------------- |
| ✅ 高效搜尋 | 使用 Binary Search 保證 `O(log n)` 時間複雜度   |
| ✅ 邏輯清晰 | 使用 `left`, `right`, `mid` 三指標，有效分割搜尋空間 |
| ✅ 結構簡潔 | 不需額外資料結構或 STL API                      |

---

### ✨ 可選優化方向

| 類型      | 說明                                                                        |
| ------- | ------------------------------------------------------------------------- |
| ⛳️ 溢位風險 | `int mid = (left + right) / 2` 在極端情況下可能溢位，可改為 `left + (right - left) / 2` |
| 💡 命名提升 | 若教學用途，可將變數改為 `low`, `high`, `mid` 更貼近教科書慣例                                |

---

### 🧼 建議優化版本（防溢位 + 可讀性）

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2; // 防止 overflow

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};
```

---

### 📊 優化比較表

| 項目     | 原始版本       | 優化版本                        |
| ------ | ---------- | --------------------------- |
| 時間複雜度  | `O(log n)` | `O(log n)`                  |
| 空間複雜度  | `O(1)`     | `O(1)`                      |
| 溢位保護   | ❌ 無        | ✅ 使用 `low + (high - low)/2` |
| 可讀性/風格 | 中等（學習者友好）  | ✅ 更安全且正規                    |

---

### ✅ 小結

本題原始程式碼已符合效能要求。建議實務上可修正 `mid` 的計算方式避免整數溢位，並適當命名提升可讀性，讓程式碼更安全與清楚。
