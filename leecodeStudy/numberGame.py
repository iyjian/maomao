from typing import List
def numberGame(nums: List[int]) -> List[int]:
    sorted_nums = sorted(nums)
    sorted_nums[::2], sorted_nums[1::2] = sorted_nums[1::2], sorted_nums[::2]
    return sorted_nums

