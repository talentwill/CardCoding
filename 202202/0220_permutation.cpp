// 剑指 Offer 38. 字符串的排列 v1.0

class Solution
{
public:
    vector<string> permutation(string s)
    {
        vector<string> ans;
        permutation(s, 0);
        for (const auto &x : results)
        {
            ans.emplace_back(std::move(x));
        }
        return ans;
    }

    void permutation(std::string &s, int begin)
    {
        if (begin == s.size() - 1)
        {
            results.emplace(s);
        }
        else
        {
            for (size_t next = begin; next < s.size(); next++)
            {
                std::swap(s[begin], s[next]);
                permutation(s, begin + 1);
                std::swap(s[next], s[begin]);
            }
        }
    }

    set<string> results;
};
