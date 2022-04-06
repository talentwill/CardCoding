// 剑指 Offer 31. 栈的压入、弹出序列

// 0406 模拟堆栈的方式
class Solution31 {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.empty()) {
            return true;
        }

        int top = -1;
        vector<int> stack(pushed.size());

        int j = 0;
        for (int i = 0; i < pushed.size(); i++)
        {
            stack[++top] = pushed[i];
            while (top >= 0 and stack[top] == popped[j])
            {
                j++;
                top--;
            }
        }

        return j == popped.size();
    }
};