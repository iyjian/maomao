import math
from typing import List
# C(n,m)= n! / m!(n−m)!


def combination(n : int, m : int) -> int:
    return int(math.factorial(n) / (math.factorial(m) * math.factorial(n - m)))

def generate_line(numRows : int) -> List[int]:
    line = []
    for i in range(0, numRows):
        line.append(combination(numRows, i))
    if line != [1]:
        line.append(1)
    return line


# def generate(numRows: int) -> List[List[int]]:
for i in range(1, 6):
    print(generate_line(i))