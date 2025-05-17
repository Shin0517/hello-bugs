# [27. Remove Element](https://leetcode.com/problems/remove-element/description/)

Given an integer array <code>nums</code> and an integer <code>val</code>, remove all occurrences of <code>val</code> in <code>nums</code> <a href="https://en.wikipedia.org/wiki/In-place_algorithm" target="_blank">**in-place** </a>. The order of the elements may be changed. Then return the number of elements in <code>nums</code> which are not equal to <code>val</code>.

Consider the number of elements in <code>nums</code> which are not equal to <code>val</code> be <code>k</code>, to get accepted, you need to do the following things:

- Change the array <code>nums</code> such that the first <code>k</code> elements of <code>nums</code> contain the elements which are not equal to <code>val</code>. The remaining elements of <code>nums</code> are not important as well as the size of <code>nums</code>.
- Return <code>k</code>.

**Custom Judge:** 

The judge will test your solution with the following code:

```
int[] nums = [...]; // Input array
int val = ...; // Value to remove
int[] expectedNums = [...]; // The expected answer with correct length.
                            // It is sorted with no values equaling val.

int k = removeElement(nums, val); // Calls your implementation

assert k == expectedNums.length;
sort(nums, 0, k); // Sort the first k elements of nums
for (int i = 0; i < actualLength; i++) {
    assert nums[i] == expectedNums[i];
}
```

If all assertions pass, then your solution will be **accepted** .

**Example 1:** 

```
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

**Example 2:** 

```
Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
Note that the five elements can be returned in any order.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

**Constraints:** 

- <code>0 <= nums.length <= 100</code>
- <code>0 <= nums[i] <= 50</code>
- <code>0 <= val <= 100</code>

---

## 💡 LeetCode 27. Remove Element

### ✅ 題目說明

給定一個整數陣列 `nums` 和一個值 `val`，請就地移除所有數值等於 `val` 的元素，並回傳移除後的元素個數 `k`。要求時間複雜度為 O(n)，空間複雜度為 O(1)。

---

### 🔢 原始程式碼

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k += 1;
            }
        }
        return k;
    }
};
```

---

### ⏱ 複雜度分析

| 類型 | 複雜度                  |
| -- | -------------------- |
| 時間 | `O(n)`：遍歷一次所有元素      |
| 空間 | `O(1)`：就地修改，不額外使用記憶體 |

---

### ✅ 優點分析

| 項目       | 說明                               |
| -------- | -------------------------------- |
| ✅ 效率優良   | 單次遍歷陣列即可完成操作                     |
| ✅ 符合題目需求 | 符合 in-place 和 constant space 的要求 |
| ✅ 可讀性佳   | 使用變數 `k` 表示目前應填入的索引位置，語意明確       |

---

### ✨ 可選優化方向（非必要）

| 類型      | 說明                                             |
| ------- | ---------------------------------------------- |
| 命名可讀性   | 可將變數 `k` 改為 `writeIndex` 或 `insertPos` 增進語意清晰度 |
| 避免不必要賦值 | 若 `i == k` 時可以略過賦值操作（微幅優化）                     |

---

### 🧼 微優化版本（語意命名與略過不必要賦值）

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int insertPos = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                if (i != insertPos) {
                    nums[insertPos] = nums[i];
                }
                ++insertPos;
            }
        }
        return insertPos;
    }
};
```

---

### ✅ 優化說明

| 比較項目 | 原始版本       | 優化版本              |
| ---- | ---------- | ----------------- |
| 變數命名 | `k`（語意較模糊） | `insertPos`（語意清晰） |
| 效率   | `O(n)`     | `O(n)`（理論相同）      |
| 空間   | `O(1)`     | `O(1)`            |
| 可讀性  | 中等         | ✅ 較高              |

---

### 📌 小結

| 項目    | 原始版本   | 優化版本    |
| ----- | ------ | ------- |
| 時間複雜度 | `O(n)` | `O(n)`  |
| 空間複雜度 | `O(1)` | `O(1)`  |
| 可讀性   | 中      | ✅ 高     |
| 運行效率  | 快      | ✅ 等同或稍佳 |
