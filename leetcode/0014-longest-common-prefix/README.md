# [14. Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/description/)

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string <code>""</code>.

**Example 1:** 

```
Input: strs = ["flower","flow","flight"]
Output: "fl"
```

**Example 2:** 

```
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
```

**Constraints:** 

- <code>1 <= strs.length <= 200</code>
- <code>0 <= strs[i].length <= 200</code>
- <code>strs[i]</code> consists of only lowercase English letters if it is non-empty.

---

以下是針對 LeetCode 題目 `14. Longest Common Prefix` 的程式碼分析與優化建議，保持為你指定的 GitHub-friendly Markdown 格式：

---

## 💡 LeetCode 14. Longest Common Prefix 解法分析與優化建議

### 原始程式碼

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        } 
        
        sort(strs.begin(), strs.end());
        auto first = strs.front();
        auto last = strs.back();

        int i = 0;
        while (i < first.length() && i < last.length() && first[i] == last[i]){
            i++;
        }
        
        return first.substr(0, i);
    }
};
```

---

### ✅ 功能說明

此程式碼透過排序字串陣列，僅比較字典序第一個與最後一個字串，從而找出整體最長公共前綴（Longest Common Prefix, LCP）。這是因為排序後，其他字串的變異範圍必定落在此兩者之間。

---

### 🧠 時間與空間複雜度分析

* **時間複雜度：**

  * 排序：`O(n log n)`，其中 `n` 為字串陣列大小。
  * 字首比較：最多比較兩個長度為 `m` 的字串 → `O(m)`
  * 整體：`O(n log n + m)`

* **空間複雜度：** `O(1)`（不計排序內部操作，未使用額外資料結構）

---

### 🔍 優化建議

#### 1. ✅ **原始做法的優點**

* **巧妙地利用排序壓縮比較範圍**：只需要比較 `first` 與 `last` 字串。
* **簡潔高效**：比直接 pairwise 比對所有字串更優雅。

#### 2. ⚠️ **排序操作為非必要成本**

* 雖然排序後比較兩端字串很聰明，但排序的時間複雜度為 `O(n log n)`，實際上可以用 **逐字元掃描法（horizontal scanning）** 降到 `O(n * m)`，在字串數量 `n` 小但字串長度 `m` 較大時更有效。

---

### 🚀 優化後程式碼（Horizontal Scanning）

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string prefix = strs[0];

        for (int i = 1; i < strs.size(); ++i) {
            int j = 0;
            while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j]) {
                ++j;
            }
            prefix = prefix.substr(0, j);

            if (prefix.empty()) break;  // 提前退出
        }

        return prefix;
    }
};
```

---

### 📝 總結

| 項目     | 原始程式碼            | 優化後程式碼          |
| ------ | ---------------- | --------------- |
| 比對方式   | 排序後比較第一與最後       | 循序逐字比較所有字串      |
| 時間複雜度  | `O(n log n + m)` | `O(n * m)`      |
| 提前退出機制 | 無                | 有，prefix 為空立即結束 |
| 適用場景   | 字串少、長度短，排序成本低    | 大量字串或長字串，較省效能   |
| 可讀性    | 高                | 稍長但直觀           |

---

### 🔧 小提醒

* 若字串很少（如 <= 10），排序法的常數成本其實很低，反而更清晰。
* 若面試要求解釋思路，「排序前後比較法」是個可以展示你觀察力與思維跳躍的好方式。
