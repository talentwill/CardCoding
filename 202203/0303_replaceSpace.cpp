// 剑指 Offer 05. 替换空格

// 22/03/03 自己实现API替换
class Solution {
public:
    string replaceSpace(string s) {
        string old = " ";
        string rep = "%20";
        for (string::size_type pos(0); pos != string::npos; pos += rep.length()) {
            if ((pos = s.find(old, pos)) != string::npos) {
                s.replace(pos, old.length(), rep);
            } else {
                break;
            }
        }
        return s;
    }
};

// 22/03/03 参考书上解法，从后往前替换，注意字符也要相反
class Solution {
public:
    string replaceSpace(string src) {
        // calc space count
        int space = 0;
        for (const auto& x: src) {
            if (x == ' ') {
                space++;
            }
        }

        int oldLen = src.length();
        int newLen = oldLen + 2 * space;
        src.resize(newLen);

        // replace from back
        for (int i = oldLen -1; i >= 0; i--) {
            if (src[i] == ' ') {
                src[--newLen] = '0';
                src[--newLen] = '2';
                src[--newLen] = '%';
            } else {
                src[--newLen] = src[i];
            }
        }
        return src;
    }
};
