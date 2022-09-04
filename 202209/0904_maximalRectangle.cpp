// https://leetcode.cn/problems/PLYXKQ/

class Solution {
public:
    int maximalRectangle(vector<string>& m) {
        if (m.empty()) return 0;

        vector<int> heights(m[0].size()); // 矩阵转换成直方图

        int area = 0;
        for (auto& s : m) {
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == '0') {
                    heights[i] = 0;
                }
                else if (s[i] == '1') {
                    heights[i] += 1;
                }
            }

            area = max(area, largestRectangleArea(heights));
        }
        return area;
    }

    // 直方图的最大矩形面积
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        s.push(-1);
        int area = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (s.size() > 1 && heights[i] < heights[s.top()]) {
                int h = heights[s.top()]; s.pop();
                int w = i - s.top() - 1;
                area = max(area, h * w);
            }
            s.push(i);
        }

        while (s.size() > 1) {
            int h = heights[s.top()]; s.pop();
            int w = heights.size() - s.top() - 1;
            area = max(area, h * w);
        }

        return area;
    }
};