
from typing import List


def twoSum(nums: List[int], target: int) -> List[int]:
    sub_i = 0
    for i in nums:
        sub_j = 0
        for j in nums:
            if i + j == target and sub_i != sub_j:
                return [sub_i, sub_j]
            sub_j += 1
        sub_i += 1

print(twoSum([2, 7, 11, 15], 9))
print(twoSum([3, 2, 4], 6))