// 剑指 Offer 11. 旋转数组的最小数字 v1.0 271641323

class Solution {
    public int minArray(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }

        if (nums[0] < nums[nums.length-1]) {
            return nums[0];
        }

        int low = 0;
        int high = nums.length -1;
        
        while (low < high) {
            int mid = (low + high) / 2;
            if (nums[mid] < nums[high]) {
                high = mid;
            } else if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else if (nums[mid] == nums[high]) {
                high = high -1; // KEY!
            }
        }
        return nums[low];
    }
}