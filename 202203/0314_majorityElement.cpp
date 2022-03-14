// 剑指 Offer 39. 数组中出现次数超过一半的数字

// 0314 利用boyre-moore voting 快速解题，实现O(n)和O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int major = 0;

        for (int x: nums) {
            if (count == 0) {
                major = x;
            }

            if (x == major) {
                count++;
            }else {
                count--;
            }
        }
        return major;
    }
};