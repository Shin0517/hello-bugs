class Solution {
public:
    unordered_map<int, int> climbed;

    int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        if (climbed.find(n) == climbed.end()) {
            climbed[n] = climbStairs(n - 1) + climbStairs(n - 2);
        }
        return climbed[n];
    }
};