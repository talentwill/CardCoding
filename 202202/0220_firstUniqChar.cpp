// 剑指 Offer 50. 第一个只出现一次的字符 v1.0

class Solution
{
public:
    char firstUniqChar(string s)
    {

        if (s.empty())
        {
            return ' ';
        }

        vector<int> table(256, 0);

        for (const auto &x : s)
        {
            table[x] += 1;
        }

        for (const auto &x : s)
        {
            if (table[x] == 1)
            {
                return x;
            }
        }

        return ' ';
    }
};