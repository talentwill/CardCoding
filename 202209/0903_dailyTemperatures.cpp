// 038. 每日温度
class Solution {
public:
    // 单调栈问题，每次温差的计算
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size());
        stack<int> stack;
        for (int i = 0; i < temperatures.size(); i++) {
            while (!stack.empty() && temperatures[stack.top()] < temperatures[i]) {
                res[stack.top()] = i - stack.top();
                stack.pop();
            }
            stack.push(i);
        }
        return res;
    }
};