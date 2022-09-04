// https://leetcode.cn/problems/0ynMMM/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s; // 按照柱子的高度，单调递增的栈，存的值是柱子在数组中的下标
        s.push(-1); // 插入下标-1的柱子，用于辅助计算矩形的宽

        int area = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            // 1. 如果当前的柱子比栈内柱子矮，则不断弹出较高的柱子（单调栈的典型做法）
            while (s.size() > 1 && (heights[i] < heights[s.top()])) {

                // 2. 以弹出的柱子为矩形的高，计算矩形的面积
                int height = heights[s.top()]; s.pop();
                // 宽，右边界 - 左边界 - 1，左右边界分别是左右两边第一个比当前柱子矮的柱子。
                int width = i - s.top() - 1;
                area = max(area, height * width);
            }
            s.push(i);
        }

        // 剩余的部分，全是单调递增的柱子，右边的边界就说是heights.size()
        while (s.size() > 1) {
            int height = heights[s.top()]; s.pop();
            int width = heights.size() - s.top() - 1;
            area = max(area, height * width);
        }
        return area;
    }
};
