//剑指 Offer 46. 把数字翻译成字符串

// 03/08 动态规划做题，f[i] = f[i-1] + f[(i-2,i)]
class Solution {
public:
    int translateNum(int num) {
        string str = to_string(num);

        int p1 = 1;
        int p2 = 1;
        int fi = p1; // 判断个位数
        for (int i = 1; i < str.size(); i++) {
            fi = p1;
            auto temp = str.substr(i - 1, 2);
            if (temp >= "10" and temp <= "25") { //注意是25，26越界
                fi += p2;
            }
            p2 = p1;
            p1 = fi;
        }

        return fi;
    }
};