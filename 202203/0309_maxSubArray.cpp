// 剑指 Offer 42. 连续子数组的最大和

// 03/09 在线处理思想
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxsum = nums[0]; //先把第一个数字作为最大
        for (auto& x: nums) {
            sum += x;
            if (sum > maxsum) {
                maxsum = sum;
            }
            if (sum < 0) { //不能用else if
                sum = 0;
            }
        }
        return maxsum;
    }
};
