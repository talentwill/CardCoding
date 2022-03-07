// 剑指 Offer 45. 把数组排成最小的数

// 03/07 自定义排序规则，两个字符串比较大小
class Solution {
public:
    string minNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), [](int a, int b){
            auto s1 = to_string(a) + to_string(b);
            auto s2 = to_string(b) + to_string(a);
            return s1 < s2; // 从小到大排序
        });

        string res;
        for (auto& i: nums) {
            res += to_string(i);
        }

        return res;
    }
};