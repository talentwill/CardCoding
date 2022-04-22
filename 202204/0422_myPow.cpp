// 剑指 Offer 16. 数值的整数次方

// 0421 快速幂求解
class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) {
            return 1.0 / quickMul(x, -(long)n);
        }
        return quickMul(x, n);
    }

    // 递归，对半分解n的方式
    double quickMul(double x, long n) {
        if (n == 0) {
            return 1;
        }
        double y = quickMul(x, n / 2);
        if (n % 2 == 1) {
            return x * y * y;
        }
        else {
            return y * y;
        }
    }

    // 快速幂，把n分解成2的幂次之和
    double quickMul1(double x, long n) {
        double ans = 1.0;
        while (n > 0) {
            if (n % 2 == 1) {
                ans *= x;
            }
            x *= x;
            n = n >> 1;
        }
        return ans;
    }
};