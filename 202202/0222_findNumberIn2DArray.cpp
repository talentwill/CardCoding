// 剑指 Offer 04. 二维数组中的查找 v1.0

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        // N == 0
        if (matrix.empty()) {
            return false;
        }

        // M == 0
        if (matrix[0].empty()) {
            return false;
        }

        // Upper right corner
        int i = 0;
        int j = matrix[i].size() - 1;
        
        while (i < matrix.size() && j >= 0) {
            int x = matrix[i][j];
            if (x == target) {
                return true;
            }
            else if (x < target) {
                i++;
            }
            else if (x > target) {
                j--;
            }
        }
        return false;
    }
};
