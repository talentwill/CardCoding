// 剑指 Offer 17. 打印从1到最大的n位数

// 0322 不考虑大数，直接输出数字的方式。
class Solution {
public:
    vector<int> printNumbers(int n) {
        int maxNum = pow(10,n);
        vector<int> ans;

        for (int i = 1; i < maxNum; i++) {
            ans.emplace_back(i);
        }

        return ans;
    }
};
