// 剑指 Offer 20. 表示数值的字符串

// 0422 暴力破解，类似状态机
class Solution {
public:
   
    bool isNumber(string s) {

        if (s.empty()) {
            return false;
        }

        bool allowDigit = true;
        bool allowDot = true;
        bool allowSign = true;
        bool allowE = false;
        int countOfE = 0;
        bool allowEndSpaces = true;
        bool matchDigit = false;

        int first = 0;
        int last = s.size() - 1;

        while (first < s.size()) {
            if (s[first++] != ' ') {
                first--;
                break;
            }
        }

        while (last >= 0) {
            if (s[last--] != ' ') {
                last++;
                break;
            }
        }

        for (int i = first; i <= last; ++i)
        {
            char c = s[i];
            if (c == '-' or c == '+') {
                if (allowSign) {
                    allowSign = false;
                    matchDigit = false;
                } else {
                    return false;
                }
            }
            else if (c == '.') {
                if (allowDot) {
                    allowDot = false;
                    allowSign = false;
                }else {
                    return false;
                }
            } else if (c == 'E' or c == 'e') {
                if (countOfE == 1) {
                    return false;
                }
                if (allowE) {
                    countOfE++;
                    allowE = false;
                    allowDot = false;
                    allowSign = true;
                    matchDigit = false;
                } else {
                    return false;
                }
            } else if (c >= '0' and c <= '9') {
                matchDigit = true;
                allowE = true;
                allowSign = false;
            } else {
                return false;
            }
        }

        return matchDigit;
    }
};