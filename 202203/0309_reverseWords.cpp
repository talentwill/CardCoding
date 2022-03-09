// 剑指 Offer 58 - I. 翻转单词顺序

// 03/09 两次翻转，题目和书上有点不一样。
class Solution {
public:

    void reverse(string&s, int first, int last){
        while ( first < last) {
            swap(s[first], s[last]);
            first++;
            last--;
        }
    }

    string reverseWords(string s) {
        if (s.empty()) {
            return s;
        }

        // 参考书上思路，两次翻转
        reverse(s, 0, s.size() - 1);
        for (int i = 0, j = 0; j <= s.size(); j++) {
            if (j == s.size() or s[j] == ' ') {
                reverse(s, i, j-1);
                i = j + 1;
            }
        }

        // 去掉句首空格        
        int first = 0;
        while (first < s.size() and s[first] == ' '){
            first++;
        }
        // 去掉句尾空格   
        int last = s.size() - 1;
        while (last > 0 and s[last] == ' '){
            last--;
        }

        string res;
        for (int i = first; i <= last; i++) {
            if (s[i] == ' ') {
                // 过滤单词间多余空格
                if (i > 0 && s[i - 1] != ' ') {
                    res.push_back(s[i]);
                }
            }else {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};
