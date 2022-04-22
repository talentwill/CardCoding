// 剑指 Offer 66. 构建乘积数组

// 0422 前缀积，后缀积相乘
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        if (a.empty()) return {};

        vector<int> ans(a.size());

        ans[0] = 1;
        for (int i = 1; i < ans.size(); i++) {
            ans[i] = ans[i-1] * a[i-1]; 
        }

        int temp = 1;
        for (int i = ans.size() - 2; i >= 0; i--) {
            temp *= a[i+1];
            ans[i] *= temp;
        }

        return ans;
    }
};