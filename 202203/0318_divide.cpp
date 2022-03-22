// 剑指 Offer II 001. 整数除法

// 0318 用递归的方式，2倍数相减，负号
class Solution {
public:
    int divide(int a, int b) {
        if (a == 0 or b == 1) {
            return a;
        }

        if (b == -1) {
            return (a == INT32_MIN) ? INT32_MAX : -a; // check overflow 
        }

        int count = 0;
        int a1 = -abs(a);
        int b1 = -abs(b);
        divideImp(a1, b1, 1, count);

        if ((a > 0 and b > 0) or (a < 0 and b < 0)) {
            return -count;
        } else {
            return count;
        }
    }

    void divideImp(int& a, int b, int times, int& count) {

        if (a <= b and b >= INT32_MIN / 2) {
            divideImp(a, b + b, times + times, count);
        }

        while (a <= b) {
            count -= times;
            a -= b;
        }
    }
};
