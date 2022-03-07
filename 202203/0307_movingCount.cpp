// 剑指 Offer 13. 机器人的运动范围

// 03/07 深度优先搜索
class Solution {
public:

    bool canMove(int x, int y) {
        if (x >= M or x < 0 or y >= N or y < 0 or visit[x][y] == 1)
            return false;
        return x % 10 + x / 10 + y % 10 + y / 10 <= K; //100以内数字
    }

    int K = 0;
    int M = 0;
    int N = 0;
    int visit[100][100] = { 0 };

    int movingCount(int m, int n, int k) {
        K = k;
        N = n;
        M = m;
        return dfs(0, 0);
    }

    int dfs(int x, int y) {
        if (canMove(x, y)) {
            visit[x][y] = 1;
            return  1 + dfs(x + 1, y) + dfs(x - 1, y) + dfs(x, y + 1) + dfs(x, y - 1);
        }
        else {
            return 0;
        }
    }
};