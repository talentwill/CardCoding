// 剑指 Offer 03. 数组中重复的数字

// 21/12/25 HashTable
#include <bitset>
struct Solution
{
    int findRepeatNumber(vector<int> &nums)
    {
        std::bitset<100000> counts;

        for (auto &&n : nums)
        {
            if (counts.test(n))
            {
                return n;
            }
            else
            {
                counts.set(n);
            }
        }
        return -1;
    }
};

// 22/03/06 参考书中，交换排序检测重复，T=O(N)
struct Solution
{
    int findRepeatNumber(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); ) {
            if (nums[i] == i) {
                i++;
            } else {
                int x = nums[i];
                if (nums[x] == x) {
                    return x;
                } else {
                    swap(nums[x], nums[i]);
                }
            }
        }
        return -1;
    }
};
