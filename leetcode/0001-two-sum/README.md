# [1. Two Sum](https://leetcode.com/problems/two-sum/description/)

Given an array of integers <code>nums</code>and an integer <code>target</code>, return indices of the two numbers such that they add up to <code>target</code>.

You may assume that each input would have **exactly one solution** , and you may not use the same element twice.

You can return the answer in any order.

**Example 1:** 

```
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
```

**Example 2:** 

```
Input: nums = [3,2,4], target = 6
Output: [1,2]
```

**Example 3:** 

```
Input: nums = [3,3], target = 6
Output: [0,1]
```

**Constraints:** 

- <code>2 <= nums.length <= 10^4</code>
- <code>-10^9 <= nums[i] <= 10^9</code>
- <code>-10^9 <= target <= 10^9</code>
- **Only one valid answer exists.** 

**Follow-up:** Can you come up with an algorithm that is less than <code>O(n^2)</code>time complexity?

---

以下是針對你提供的 LeetCode `Two Sum` 解法的 **程式碼分析與優化建議**，已整理為適合貼到 GitHub README 或筆記中的 Markdown 格式。

---

## 💡 LeetCode Two Sum 解法分析與優化建議

### 原始程式碼

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> numsMap;    

        for (int i = 0; i < nums.size(); ++i){
            int complement = target - nums[i];

            auto item = numsMap.find(complement);
            if (item != numsMap.end()){
                return {numsMap[complement], i};
            }
            
            numsMap[nums[i]] = i;
        }

        return {};
    }
};
```

---

### ✅ 功能說明

此程式碼實作了經典的 `Two Sum` 問題：給定一個整數陣列 `nums` 與一個目標值 `target`，返回兩個數字的索引，使得它們相加之和等於目標值。

---

### 🧠 時間與空間複雜度分析

* **時間複雜度：** `O(n)`
  一次遍歷 `nums` 陣列，查找與插入 map 操作皆為對數時間。

* **空間複雜度：** `O(n)`
  使用一個 map 儲存最多 `n` 個元素。

---

### 🔍 優化建議

#### 1. **使用 `unordered_map` 替代 `map`**

* `std::map` 是紅黑樹結構，查找與插入操作為 `O(log n)`
* `std::unordered_map` 是雜湊表，查找與插入操作為 `O(1)` 平均時間
* 因此此處使用 `unordered_map` 可提升整體效能

#### 2. **語意與命名強化可讀性**

* 使用更語意化的命名如 `numToIndex` 代替 `numsMap`
* 不需要先 `find()` 再查 `numsMap[complement]`，可直接用 `count()` 或 `find()->second`

---

### 🚀 優化後程式碼

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> numToIndex;

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];

            if (numToIndex.count(complement)) {
                return {numToIndex[complement], i};
            }

            numToIndex[nums[i]] = i;
        }

        return {};
    }
};
```

---

### 📝 總結

| 項目       | 原始程式碼      | 優化後程式碼               |
| -------- | ---------- | -------------------- |
| 查找結構     | `std::map` | `std::unordered_map` |
| 查找/插入複雜度 | `O(log n)` | `O(1)`（平均）           |
| 命名語意     | `numsMap`  | `numToIndex`         |
| 整體效率     | 中          | 高                    |

使用雜湊表 (`unordered_map`) 是此題的最佳解法之一，可將時間效率提升至 **線性時間** 並保有乾淨、簡潔的邏輯結構。
