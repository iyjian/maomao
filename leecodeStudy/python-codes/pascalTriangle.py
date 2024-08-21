import math
from typing import List
# C(n,m)= n! / m!(n−m)!


def combination(n : int, m : int) -> int:
    return int(math.factorial(n) / (math.factorial(m) * math.factorial(n - m)))

def pascal_triangle_line(numRows : int) -> List[int]:
    return [combination(numRows, i) for i in range(numRows + 1)]

def pascal_triangle(numRows: int) -> List[List[int]]:
    return[pascal_triangle_line(i) for i in range(numRows)]