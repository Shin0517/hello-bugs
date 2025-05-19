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