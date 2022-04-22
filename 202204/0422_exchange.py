# 剑指 Offer 21. 调整数组顺序使奇数位于偶数前面

# 0422 数组原地拆分，双指针交换
class Solution:
    def exchange(self, nums: List[int]) -> List[int]:
        even = 0
        odd = len(nums) - 1
        while even < odd:
            while even < odd and nums[even] % 2 == 1:
                even += 1
            while even < odd and nums[odd] % 2 == 0:
                odd -= 1
            if even < odd:
                nums[even], nums[odd] = nums[odd], nums[even]

        return nums