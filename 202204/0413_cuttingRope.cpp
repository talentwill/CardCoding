#include "../helper.h"

// 0413 剪绳子 I

class Solution
{
public:
    int cuttingRope(int n) {
        if (n <= 3) return n - 1;

        vector<int> products = { 0, 1, 2, 3 };
        products.resize(n + 1);
        int ans = 0;
        for (int i = 4; i <= n; i++) {
            for (int j = 1; j <= i / 2; j++) {
                ans = max(ans, products[j] * products[i - j]);
            }
            products[i] = ans;
        }
        return products[n];
    }
};

// 剑指 Offer 14- II. 剪绳子 II
// 0413 循环求余数
class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 3) return n - 1;

        int quotient = n / 3;
        int remainder = n % 3;

        if (remainder == 0) { // 整除
            remainder = 1;
        }
        else if (remainder == 1) { // 余1，把 3+1 变成 2+2
            remainder = 4;
            quotient--;
        }
        long res = remainder;
        for (int i = 0; i < quotient; i++) {
            res = (res * 3) % 1000000007;
        }
        return res;
    }
};
