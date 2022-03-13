// 剑指 Offer 40. 最小的k个数

// 03/13 最小堆实现，最简单不容易出错
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k == 0) { // 注意边界条件！
            return {};
        }
        priority_queue<int> q;
        for (int i = 0; i < k; i++) {
            q.push(arr[i]);
        }

        for (int i = k; i < arr.size(); i++) {
            if (arr[i] < q.top()) {
                q.pop();
                q.push(arr[i]);
            }
        }
        vector<int> res;
        while (!q.empty()) {
            res.emplace_back(q.top());
            q.pop();
        }
        return res;
    }
};