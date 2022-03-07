// 剑指 Offer 12. 矩阵中的路径

// 03/07 dfs实现 
class Solution
{
public:
    vector<bool> visited;
    int m = 0;
    int n = 0;
    bool exist(vector<vector<char>> &board, string word)
    {
        rows = board.size();
        n = board[0].size();

        if (board.empty() || word.empty())
        {
            return false;
        }
        visited.resize(m * n);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0])
                {
                    if (findWord(board, i, j, word, 0))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    struct Dir
    {
        int row;
        int col;
    };

    Dir dirs[4] = {
        {0, -1},
        {0, 1},
        {-1, 0},
        {1, 0},
    };

    bool isVisited(int i, int j)
    {
        return visited[i * n + j];
    }

    bool findWord(vector<vector<char>> &board, int i, int j, string &word, int k)
    {
        if (i < 0 or j < 0 or i >= board.size() or j >= board[i].size() or k >= word.size())
        {
            return false;
        }

        if (isVisited(i, j))
            return false;

        if (board[i][j] == word[k])
        {
            visited[i * n + j] = true;
            if (k == word.size() - 1)
            {
                return true;
            }
            else
            {
                for (int x = 0; x < 4; x++)
                {
                    if (findWord(board, i + dirs[x].row, j + dirs[x].col, word, k + 1))
                    {
                        return true;
                    }
                }
            }
            visited[i * n + j] = false;
        }
        return false;
    }
};