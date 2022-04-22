// 剑指 Offer 57. 和为s的两个数字

// 0422 二分法加双指针
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        // 二分法先找到第一个小于target的值
        while (left <= right) {
            int mid = (left + right) / 2;
            int x = nums[mid];
            if (x >= target) {
                right = mid - 1;
            } else if (x < target) {
                left = mid + 1;
            }
        }

        int low = 0;
        int high = right;
        // 双指针累加
        while (low <= high) {
            int sum = nums[low] + nums[high];
            if (sum > target) {
                high--;
            } else if (sum < target) {
                low++;
            } else {
                return {nums[low], nums[high]};
            }
        }

        return {};
    }
};
