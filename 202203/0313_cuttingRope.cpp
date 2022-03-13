// 剑指 Offer 14- I. 剪绳子

// 0313 利用动态规划解题，先分析出公式，循环解决
class Solution {
public:
    int factors[59] = { 1, 1, 2, 3}; //根据题目设置好缓存大小
    int cuttingRope(int n) {
        if (n <= 3) {
            return n - 1;
        }

        int ans = 0;
        for (int i = 4; i <= n; i++) { // n 从4开始算
            for (int j = 2; j <= i - j; j++) {
                ans = max(ans, factors[j] * factors[i - j]);
            }
            factors[i] = ans; // 逐步更新缓存
        }
        return factors[n];
    }
};
