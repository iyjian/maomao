from typing import List

def minimumOperations(nums : List[int]) -> int:
    operateTime = 0
    for num in nums:
        if num % 3 != 0:
           operateTime += 1
    return operateTime


print(minimumOperations([1, 2, 3, 4]))
print(minimumOperations([3, 6, 9]))