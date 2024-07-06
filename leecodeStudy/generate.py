import math
# C(n,m)= n! / m!(n−m)!


def combination(n : int, m : int) -> int:
    # 计算组合数， 从n个数字里选出m个
    if n < m:
        return 
    return math.factorial(n) / math.factorial(m) / math.factorial(n - m)

print(combination(1, 1))