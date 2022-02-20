// 剑指 Offer 10- II. 青蛙跳台阶问题 v1.0

class Solution
{
public:
    vector<int> cache;

    int jump(int n)
    {
        if (n < 1 )
        {
            return !n;
        }

        if (cache[n] == 0)
        {
            cache[n] = jump(n - 1) + jump(n - 2);
        }
        return cache[n] % 1000000007;
    }

    int numWays(int n)
    {
        cache.resize(n + 1);
        return jump(n);
    }
};
