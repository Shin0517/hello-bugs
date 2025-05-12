# [26. Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/)

Given an integer array <code>nums</code> sorted in **non-decreasing order** , remove the duplicates <a href="https://en.wikipedia.org/wiki/In-place_algorithm" target="_blank">**in-place** </a> such that each unique element appears only **once** . The **relative order**  of the elements should be kept the **same** . Then return the number of unique elements in <code>nums</code>.

Consider the number of unique elements of <code>nums</code> to be <code>k</code>, to get accepted, you need to do the following things:

- Change the array <code>nums</code> such that the first <code>k</code> elements of <code>nums</code> contain the unique elements in the order they were present in <code>nums</code> initially. The remaining elements of <code>nums</code> are not important as well as the size of <code>nums</code>.
- Return <code>k</code>.

**Custom Judge:** 

The judge will test your solution with the following code:

```
int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
```

If all assertions pass, then your solution will be **accepted** .

**Example 1:** 

```
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

**Example 2:** 

```
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

**Constraints:** 

- <code>1 <= nums.length <= 3 * 10^4</code>
- <code>-100 <= nums[i] <= 100</code>
- <code>nums</code> is sorted in **non-decreasing**  order.

---

以下是針對 LeetCode 題目 `26. Remove Duplicates from Sorted Array` 的程式碼優化與分析，依照你的 GitHub-friendly Markdown 格式撰寫：

---

## 💡 LeetCode 26. Remove Duplicates from Sorted Array 解法分析與優化建議

### 原始程式碼

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[k] = nums[i];
                k += 1;
            }
        }
        return k;
    }
};
```

---

### ✅ 功能說明

此程式碼解法針對已排序的陣列 `nums`，就地（in-place）移除重複元素，並回傳移除後的長度 `k`。所有前 `k` 個元素將是唯一的，並按照原始順序保留。

---

### 🧠 時間與空間複雜度分析

* **時間複雜度：** `O(n)`
  僅需一次迴圈遍歷整個陣列。

* **空間複雜度：** `O(1)`
  使用兩個變數，不需額外空間，屬於 in-place 操作。

---

### 🔍 優化建議

#### ✅ 此解法已經非常接近最佳解法，簡潔且高效，無需額外容器，也無需複雜條件。

可以進一步強化以下細節：

1. **邊界情況檢查（防止空陣列崩潰）**
   雖然 `LeetCode` 通常提供非空陣列，但為健壯性可加 `if (nums.empty()) return 0;`。

2. **語意清晰命名**

   * `k` 可以改為 `insertPos`（或 `writeIndex`），更容易讓其他人閱讀時理解此變數用途。

---

### 🚀 優化後程式碼（語意化命名 + 邊界保護）

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int insertPos = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                nums[insertPos] = nums[i];
                ++insertPos;
            }
        }
        return insertPos;
    }
};
```

---

### 📝 總結

| 項目    | 原始程式碼    | 優化後程式碼          |
| ----- | -------- | --------------- |
| 效率    | `O(n)`   | `O(n)`（相同）      |
| 空間    | `O(1)`   | `O(1)`（相同）      |
| 邊界處理  | 未處理空陣列   | 加入 `empty()` 檢查 |
| 命名可讀性 | `k` 不易理解 | 改為 `insertPos`  |
| 可讀性   | 中        | 高               |