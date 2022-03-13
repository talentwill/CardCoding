// 剑指 Offer 21. 调整数组顺序使奇数位于偶数前面

// 0313 数组原地拆分，双指针交换
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int even = 0;
        int odd = nums.size() - 1;

        while (even < odd) {
            while (even < odd && nums[even] % 2 != 0) {
                even++;
            }

            while (even < odd && nums[odd] % 2 != 1) {
                odd--;
            }

            if (even < odd) {
                swap(nums[even++], nums[odd--]);
            }
        }
        return nums;
    }
};