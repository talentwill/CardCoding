// 剑指 Offer 47. 礼物的最大价值

// 03/08 Try dynamic programming by myself, code may be not clean and efficient, but it was AC.
class Solution {
public:

    int m = 0;
    int n = 0;
    int cache[200][200] = {0}; // It was a timeout if I didn't add this cache.

    int dp(int x, int y, vector<vector<int>>& grid) {
        if (x < 0 or y < 0 or x >= m or y >= n) {
            return 0;
        }
        
        if (cache[x][y] == 0) {
            cache[x][y] = grid[x][y] + max(dp(x-1, y, grid), dp(x, y-1, grid));
        }

        return cache[x][y];
    }

    int maxValue(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        return dp(m-1, n-1, grid);
    }
};
