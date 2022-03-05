// 剑指 Offer 58 - II. 左旋转字符串

// 03/05 利用额外数组切片拷贝
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string res(s.begin()+n, s.end());
        for (int i = 0; i < n; i++) {
            res.push_back(s[i]);
        }
        return res;
    }
};