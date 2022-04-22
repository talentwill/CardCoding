class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() or matrix[0].empty()) {
            return {};
        }

        vector<int> ans;

        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        while (top <= bottom and left <= right) {

            for (int col = left; col <= right; col++) {
                ans.emplace_back(matrix[top][col]);
            }
            top++;

            for (int row = top; row <= bottom; row++) {
                ans.emplace_back(matrix[row][right]);
            }
            right--;

            // 注意点：行或列大于2的情况
            if (left < right and top < bottom) {
                for (int col = right; col >= left; col--) {
                    ans.emplace_back(matrix[bottom][col]);
                }
                bottom--;

                for (int row = bottom; row >= top; row--) {
                    ans.emplace_back(matrix[row][left])
                }
                left++;
            }
        }
        return ans;
    }
};